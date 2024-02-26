#include <iostream>
#include "Utils/TerminalColors.h"
#include "MenuTools.cpp"

using namespace std;

int main()
{
    cout << TerminalColors::Green;

    cout << "Bem vindo ao GrafEmulator" << endl;

    Menu menu;

    menu.setNumVertices();

    menu.setTipoEstrutura();

    menu.setTipoGrafo();

    menu.setPrint();

    menu.generateGrafo();

    menu.startEmulator();
    
    cout << TerminalColors::White;
}