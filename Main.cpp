#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"
#include <stdexcept>
#include <algorithm>
#include <filesystem>

using namespace std;

std::string program;
std::string filename_in;
std::string filename_out;
bool debug = false;
static bool only_preprocess = false;
static bool only_compile = false;
static bool specified_out_name = false;

bool isNumber(const std::string &s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

static std::string getExtension(const std::string &filename)
{
    return filename.substr(filename.size() >= 2 ? filename.size() - 2 : 0);
}

static std::string getName(const std::string &path)
{
    filesystem::path filePath(path);
    return filePath.stem().string();
}

static void validateFileName(const std::string &filename)
{
    auto ext = getExtension(filename);
    if (ext != ".cpp" && ext != "cc" && ext != ".s" && ext != ".o" && ext != ".a")
        throw invalid_argument("bad file name format: " + filename);
}

int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        throw invalid_argument("ERROR. Assembly file name not provided!");
    }
    string filename_in = argv[1];

    SymbolTable symbTable;
    // First scan to deal with labels.
    Parser parser1(filename_in);
    // Rom addresss starting from 0. ++romAdd when encounter none-L commands.
    int romAddr = -1;
    while (parser1.hasMoreCommands())
    {
        parser1.advance();
        if (parser1.commandType() == L_COMMAND)
        {
            symbTable.addEntry(parser1.symbol(), romAddr + 1);
            //cout << parser1.symbol() << '\t' << symbTable.getAddress(parser1.symbol()) << endl;
        }
        else
            ++romAddr;
    }

    // Second scan.
    ofstream hackFile;
    hackFile.open(getName(filename_in) + ".hack");
    int memOffset = 16;
    int memAddr;
    string symbol;
    string binary;
    Parser parser2(filename_in);
    Code code;

    while (parser2.hasMoreCommands())
    {
        parser2.advance();
        if (parser2.commandType() == A_COMMAND)
        {
            //cout << " A_COMMAND!" << endl;
            symbol = parser2.symbol();
            // @ a constant
            if (isNumber(symbol))
            {
                binary = code.aCmdCode(symbol);
            }
            // Check if this symbol is a label which already been mapped.
            else if (symbTable.contains(symbol))
            {
                memAddr = symbTable.getAddress(symbol);
                binary = code.aCmdCode(to_string(memAddr));
            }
            // Then the symbol must be a variable.
            else
            {
                symbTable.addEntry(symbol, memOffset);
                binary = code.aCmdCode(to_string(memOffset));
                ++memOffset;
            }
            hackFile << binary << endl;
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
