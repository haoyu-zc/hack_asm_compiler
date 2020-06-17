#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

bool isNumber(const string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        throw invalid_argument("ERROR. Assembly file name not provided!");
    }
    string asmFile = argv[1];

    SymbolTable symbTable;
    // First scan to deal with labels.
    Parser parser1(asmFile);
    // Rom addresss starting from 0. ++romAdd when encounter none-L commands.
    int romAddr = 0;
    while (parser1.hasMoreCommands())
    {
        parser1.advance();
        if (parser1.commandType() == L_COMMAND)
            symbTable.addEntry(parser1.symbol(), romAddr + 1);
        else
            romAddr++;
    }

    // Second scan.
    ofstream hackFile;
    hackFile.open(asmFile.substr(0, asmFile.find('.')) + ".hack");
    int memOffset = 16;
    int memAddr = 0;
    string command;
    string symbol;
    string binary;
    Parser parser2(asmFile);
    Code code;
    while (parser2.hasMoreCommands())
    {
        parser2.advance();
        command = parser2.currentCmd;
        if (parser2.commandType() == A_COMMAND)
        {
            symbol = parser2.symbol();
            // @ a constant
            if (isNumber(symbol))
            {
                binary = code.aCmdCode(parser2.symbol());
                hackFile << binary << endl;
            }
            // Check if this symbol is a label which already been mapped.
            else if (symbTable.contains(symbol))
            {
                memAddr = symbTable.getAddress(symbol);
                binary = code.aCmdCode(to_string(memAddr));
                hackFile << binary << endl;
            }
            // Then the symbol must be a variable.
            else {
                symbTable.addEntry(symbol, memOffset);
                memOffset++;
            }
        }
        else if (parser2.commandType() == C_COMMAND)
        {
            binary = "111" + code.comp(parser2.comp()) + code.dest(parser2.dest()) + code.jump(parser2.jump());
            hackFile << binary << endl;
        }
    }
    hackFile.close();

    return 0;
}

