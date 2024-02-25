#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "GrafTools.cpp"
#include "TerminalColors.h"
#include "MenuTools.cpp"

using namespace std;

int main()
{
    cout << TerminalColors::Green;

    cout << "Bem vindo ao GrafEmulator" << endl;

    setNumVertices();

    setTipoEstrutura();

    setTipoGrafo();

    generateGrafo();

    startEmulator();
    
    cout << TerminalColors::White;
}