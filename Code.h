#pragma once
#include <string>
#include <map>

using std::string;
using std::map;

class Code
{
private:
    map<string, string> biTable;
    
public:
    Code(/* args */);
    void loadCompa0(string compa0);
    void loadCompa1(string compa1);
    void loadDest(string dest);
    void loadJmp(string Jmp);
};

