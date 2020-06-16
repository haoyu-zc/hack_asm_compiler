#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Code.h"
#include <stdexcept>

using std::invalid_argument;
using std::string;
using std::ofstream;

int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        throw invalid_argument("ERROR. Assembly file name not provided!");
    }

    string asmFile = argv[1];
    ofstream hackFile;
    hackFile.open(asmFile.substr(0, asmFile.find('.')) + ".hack");
    Code code;
    Parser parser(asmFile);
    
    string command;
    string binary;
    while (parser.hasMoreCommands())
    {
        parser.advance();
        command = parser.currentCmd;
        if (parser.commandType() == A_COMMAND)
        {
            binary = code.aCmdCode(parser.symbol());
            hackFile << binary << endl;
        }
        else if (parser.commandType() == C_COMMAND)
        {
            binary = "111" + code.comp(parser.comp()) + code.dest(parser.dest()) + code.jump(parser.jump());
            hackFile << binary << endl;
        }
    }
    hackFile.close();

    return 0;
}