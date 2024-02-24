#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "GrafTools.h"
#include "TerminalColors.h"
#include "MenuTools.h"

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