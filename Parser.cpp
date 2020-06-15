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

    this->advance();
    this->advance();
    command = this->currentCmd;
    cout << this->symbol() << endl;

    // while (this->hasMoreCommands())
    // {
    //     this->advance();
    //     command = this->currentCmd;

    //     /* hasMoreCommarnd() test */
    //     // cout << command + " has more commands? " << boolalpha << this->hasMoreCommands() << endl;
    //     // cout << this->commandType() << endl;

    //     /* symbol() test */
    //     // if(this->commandType() == A_COMMAND)
    //     //     cout << this->symbol() << endl;

    //     fout << command << endl;
    // }
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

// Variables for advance()
void Parser::advance()
{
    string pattern = "\\W*//.+";
    regex r(pattern);
    string fmt = "";
    string line;
    getline(fin, line);
    line = regex_replace(line, r, fmt);
    // Skip empty lines after removing comments.
    while (line.empty())
    {
        getline(fin, line);
        line = regex_replace(line, r, fmt);
    }
    this->currentCmd = line;
}

int Parser::commandType()
{
    const char *firstChar = &this->currentCmd.at(0);
    switch (*firstChar)
    {
    case '@':
        return A_COMMAND;
    case '(':
        return L_COMMAND;
    default:
        break;
    }
    return C_COMMAND;
}

string Parser::symbol()
{
    string pattern = "\\(([^)]+)\\)";
    regex r(pattern);
    smatch result;
    if (this->commandType() == A_COMMAND)
        return this->currentCmd.substr(1);
    else if (this->commandType() == L_COMMAND)
    {
        regex_search(this->currentCmd, result, r);
        return result.str(1);
    }
    else
        throw runtime_error("Not a A or L command!");
}