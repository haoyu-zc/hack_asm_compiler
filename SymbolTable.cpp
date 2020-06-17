#include "SymbolTable.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <initializer_list>

using namespace std;

SymbolTable::SymbolTable()
{
    string tableFile = "./tables/symbols.txt";
    this->loadTable({tableFile});
}

void SymbolTable::loadTable(initializer_list<string> files)
{
    ifstream fin;
    string line;
    string symbol;
    int address;
    int tabPos;

    for (const string &file : files)
    {
        fin.open(file);
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            tabPos = line.find('\t');
            symbol = line.substr(0, tabPos);
            address = stoi(line.substr(tabPos + 1));
            this->symbTable[symbol] = address;
        }
        fin.close();
    }
}

void SymbolTable::addEntry(string symbol, int address)
{
    if (this->contains(symbol))
        throw runtime_error("Key " + symbol + " already exsits!");
    else
        this->symbTable[symbol] = address;
}

bool SymbolTable::contains(string symbol)
{
    return this->symbTable.count(symbol);
}

int SymbolTable::getAddress(string symbol)
{
    return this->symbTable[symbol];
}