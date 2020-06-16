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
    Code();
    void loadTable(initializer_list<string> files);
};

