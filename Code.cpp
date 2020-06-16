#include "Code.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

Code::Code()
{
    string compa0File = "./tables/comp_a0.txt";
    string compa1File = "./tables/comp_a1.txt";
    string destFile = "./tables/dest.txt";
    string jumpFile = "./tables/jump.txt";
    this->loadCompa0(compa0File);
    this->loadCompa1(compa1File);
    this->loadDest(destFile);
    this->loadJmp(jumpFile);
}

void Code::loadCompa0(string file)
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
        cout << symbol << '\t' << binary << endl;
        this->biTable[symbol] = binary;
    }

    fin.close();
}

void Code::loadCompa1(string file)
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
        cout << symbol << '\t' << binary << endl;
        this->biTable[symbol] = binary;
    }

    fin.close();
}

void Code::loadDest(string file)
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
        cout << symbol << '\t' << binary << endl;
        this->biTable[symbol] = binary;
    }

    fin.close();
}

void Code::loadJmp(string file)
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
        cout << symbol << '\t' << binary << endl;
        this->biTable[symbol] = binary;
    }

    fin.close();
}