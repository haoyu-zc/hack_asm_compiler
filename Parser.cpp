#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include <regex>

using namespace std;

// Private fuctions
void Parser::trim()
{
    ofstream fout;
    fout.open("trimedFile.asm");
    // Define regex parameters.
    // Remove one-line and inline comments (and the spaces in the beginning).
    string pattern = "\\W*//.+";
    regex r(pattern);
    string fmt = "";

    string command;

    while (this->hasMoreCommands())
    {
        this->advance();
        command = regex_replace(this->currentCmd, r, fmt);
        // Skip empty lines after removing comments.
        if (command.empty())
            continue;
        cout << command + " has more commands? " << boolalpha << this->hasMoreCommands() << endl;
        cout << this->commandType() << endl;
        fout << command << endl;
    }
    fin.close();
    fout.close();
}

// Public functions
Parser::Parser(string asmFile)
{
    //ifstream fin;
    this->fin.open(asmFile);
    this->trim();
}

bool Parser::hasMoreCommands()
{
    if (this->fin.peek() != EOF)
        return true;
    else
        return false;
}

void Parser::advance()
{
    getline(fin, this->currentCmd);
}

int Parser::commandType()
{
    const char *firstChar = &this->currentCmd.at(0);
    switch (*firstChar)
    {
    case '@':
        return A_COMMNAD;
    case '(':
        return L_COMMAND;
    default:
        break;
    }
    return C_COMMAND;
}