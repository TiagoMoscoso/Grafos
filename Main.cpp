#include <iostream>
#include "Utils/TerminalColors.h"
#include "MenuTools.cpp"

using namespace std;

int main()
{
    cout << TerminalColors::Green;

    cout << "Bem vindo ao GrafEmulator" << endl;

    Menu menu;

    menu.startEmulator();
    
    cout << TerminalColors::White;
}
