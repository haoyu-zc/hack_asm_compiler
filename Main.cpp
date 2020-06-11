#include <iostream>
#include <string>
#include "Parser.h"

using std::string;

int main(int argc, char *argv[])
{
    // Read raw
    string asmFile = argv[1];
    Parser parser(asmFile);
    
    // Output coded hack file.
    // ofstream hackFile;
    // hackFile.open("output.hack");
    // hackFile << "To be or not to be.\n";
    // hackFile.close();

    return 0;
}