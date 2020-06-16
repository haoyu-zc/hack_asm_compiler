#include "Code.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <initializer_list>
#include <bitset>

using namespace std;

Code::Code()
{
    string compa0File = "./tables/comp_a0.txt";
    string compa1File = "./tables/comp_a1.txt";
    string destFile = "./tables/dest.txt";
    string jumpFile = "./tables/jump.txt";

    this->loadTable({compa0File, compa1File, destFile, jumpFile});
}

void Code::loadTable(initializer_list<string> files)
{
    for (const string &file : files)
    {
        ifstream fin;
        fin.open(file);
        string line;
        string symbol;
        string binary;
        int tabPos;
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            tabPos = line.find('\t');
            symbol = line.substr(0, tabPos);
            binary = line.substr(tabPos + 1);
            this->biTable[symbol] = binary;
        }

        fin.close();
    }
}

string Code::comp(string compStr)
{
    return this->biTable[compStr];
}

string Code::dest(string destStr)
{
    return this->biTable[destStr];
}

string Code::jump(string jumpStr)
{
    return this->biTable[jumpStr];
}

string Code::aCmdCode(string aStr)
{
    // Convert the decimal value of an A-Command to a binary string with leading-zero padding.
    string binary = bitset<15>(stoi(aStr)).to_string();
    return "0" + binary;
}