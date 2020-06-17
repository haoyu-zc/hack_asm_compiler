#include <map>
#include <string>
#include <initializer_list>

using std::map;
using std::string;
using std::initializer_list;

class SymbolTable
{
private:
    map<string, int> symbTable;

public:
    SymbolTable();
    void addEntry(string symbol, int address);
    bool contains(string symbol);
    int getAddress(string symbol);
    void loadTable(initializer_list<string> files);
};

