#ifndef TERMINALCOLORS
#define TERMINALCOLORS

#include <string>

using namespace std;
class TerminalColors 
{
    public:
        static const string Green;
        static const string Yellow;
        static const string Red;
        static const string Blue;//roxo
        static const string White;
};


const string TerminalColors::Green = "\033[1;32m";
const string TerminalColors::Yellow = "\033[1;33m";
const string TerminalColors::Red = "\033[1;31m";
const string TerminalColors::Blue = "\033[34m";
const string TerminalColors::White = "\033[1;37m";

#endif