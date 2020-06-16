#pragma once
#include <string>
#include <map>
#include <initializer_list>

using std::string;
using std::map;
using std::initializer_list;

class Code
{
private:
    map<string, string> compTable;
    map<string, string> destTable;
    map<string, string> jumpTable;

public:
    Code();
    void loadTable(initializer_list<string> files);
    string comp(string compStr);
    string dest(string destStr);
    string jump(string jumpStr);
    string aCmdCode(string aStr);
};

