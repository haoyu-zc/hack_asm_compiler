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
    string line;
    // Define regex parameters.
    // Remove one-line and inline comments (and the spaces in the beginning).
    string pattern = "\\W*//.+";
    regex r(pattern);
    string fmt = "";

    while (this->hasMoreCommands())
    {
        string command;
        getline(fin, line);
        command = regex_replace(line, r, fmt);
        // Skip empty lines after removing comments.
        if (command.empty())
            continue;
        cout << command + " has more commands? " << boolalpha << this->hasMoreCommands() << endl;
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
    string line;
    getline(fin, line);
    this->currentCmd = line;
}

auto Parser::commandType()
{
}