#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"

using std::string;
using std::cout;
using std::istream;
using std::endl;

Parser::Parser(string asmFile)
{
    ifstream fin;
    fin.open(asmFile);
    string line;
    while(fin)
    {
        getline(fin, line);
        cout << line << endl;
    }
    fin.close();
}

bool Parser::hasMoreCommands()
{
    return true;
}