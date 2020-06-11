// Cleaner representation of ifndef...
#pragma once
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using A_COMMAND = string;
using C_COMMAND = string;
using L_COMMAND = string;

class Parser
{
private:
    ifstream asmFile;

public:
    Parser() = default;
    // Load the assembly file in commnad line argument
    Parser(string asmFile);

    // Open a file
    void open(string asmFile);

    // Is there more commands in the asm file?
    bool hasMoreCommands();
    
    // Load next command and set it as "current" command.
    void advance();

    // Return the type of the current command, including
    // A_COMMAND, C_COMMAND, and L_COMMAND.
    auto commandType();

    // Return the symbol or decimal Xxx of the current command @Xxx or (Xxx).
    // Should be called only when command_type is A_COMMAND or L_COMMAND.
    string symbol();

    // Return the dest mnemonic in the current C-command (8 possibilities).
    // Should be called only when command_type is C_COMMAND.
    string dest();

    // Return the comp mnemonic in the current C-command (28 possibilities).
    // Should be called only when command_type is C_COMMAND.
    string comp();

    // Return the jump mnemonic in the current C-command (8 possibilities).
    // Should be called only when command_type is C_COMMAND.
    string jump();

};
