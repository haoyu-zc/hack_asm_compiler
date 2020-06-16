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
    map<string, string> biTable;

public:
    Code(/* args */);
    void loadTable(initializer_list<string> files);
    void loadCompa1(string compa1);
    void loadDest(string dest);
    void loadJmp(string Jmp);
};

