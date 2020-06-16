#include <iostream>
#include <string>
#include "Parser.h"
#include "Code.h"
#include <stdexcept>

using std::string;
using std::invalid_argument;

int main(int argc, char *argv[])
{
    // if(!argv[1])
    // {
    //     throw invalid_argument("ERROR. Assembly file name not provided!");
    // }
    // string asmFile = argv[1];
    Code code;
    code.aCmdCode("2");
    //Parser parser(asmFile);
    
    // Output coded hack file.
    // ofstream hackFile;
    // hackFile.open("output.hack");
    // hackFile << "To be or not to be.\n";
    // hackFile.close();

    return 0;
}