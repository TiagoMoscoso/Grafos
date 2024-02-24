#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "TerminalColors.h"
#include <algorithm>
#include <iomanip>
#include "GrafTools.h"

int NumVertices = 0;
short TipoDeEstrutura = -1; // 0 matriz, 1 lista, 2 os dois
bool TipoGrafo; // true direcionado, false nao direcionado

void setNumVertices()
{
    cout << TerminalColors::Green;
    cout << "Deseja criar um grafo de quantos vertices?" << endl;

    while(NumVertices <= 0)
    {
        try
        {
            string auxiliarNumVet;

            cout << TerminalColors::White;
            cin>> auxiliarNumVet;

            NumVertices = stoi(auxiliarNumVet);

            if(NumVertices <= 0)
            {
                cout << TerminalColors::Red;
                cout << "O numero deve ser maior que 0" << endl;
            }
        }
        catch(exception ex)
        {
            cout << TerminalColors::Red;
            cout << "Deve inserir apenas numeros inteiros!!!" << endl;
        }
    }
    cout << TerminalColors::White;
    cout << endl;
}

void setTipoEstrutura()
{
    cout << TerminalColors::Green;
    cout << "Deseja usar matriz, lista ou os dois para representar seu grafo?" << endl;

    while(TipoDeEstrutura <= -1)
    {
        string auxiliarTipoEstru = "";

        cout << TerminalColors::White;
        cin>> auxiliarTipoEstru;

        transform(auxiliarTipoEstru.begin(), auxiliarTipoEstru.end(), auxiliarTipoEstru.begin(), ::tolower);

        if(auxiliarTipoEstru == "matriz" || auxiliarTipoEstru == "mat" || auxiliarTipoEstru == "0")
        {
            TipoDeEstrutura = 0;
            cout << TerminalColors::Green;
            cout << "Estrutura de grafo definida como matriz." << endl;
        }
        else if(auxiliarTipoEstru == "lista" || auxiliarTipoEstru == "list" || auxiliarTipoEstru == "1")
        {
            TipoDeEstrutura = 1;
            cout << TerminalColors::Green;
            cout << "Estrutura de grafo definida como lista." << endl;
        }
        else if(auxiliarTipoEstru == "os dois" || auxiliarTipoEstru == "dois" || auxiliarTipoEstru == "2")
        {
            TipoDeEstrutura = 2;
            cout << TerminalColors::Green;
            cout << "Estrutura de grafo definida como matriz e lista." << endl;
        }
        else
        {
            cout << TerminalColors::Red;
            cout << "Tipo invalido" << endl;
            cout << "Use os seguintes tipos:" << endl;
            cout << TerminalColors::Yellow;
            cout << setw(20) << "Matriz:" << setw(10) << "(matriz) ou (0)" << endl;
            cout << setw(20) << "Lista:" << setw(10) << "(lista) ou (1)" << endl;
            cout << setw(20) << "Os dois:" << setw(10) << "(os dois) ou (2)" << endl;

        }
    }
    cout << TerminalColors::White;
    cout << endl;
}

void setTipoGrafo()
{
    cout << TerminalColors::Green;
    cout << "Qual sera o tipo de grafo?" << endl;
    cout << "Nao Direcionado ou Direcionado" << endl;
    while(true)
    {
        string auxiliartipoGrafo = "";

        cout << TerminalColors::White;
        cin>> auxiliartipoGrafo;

        transform(auxiliartipoGrafo.begin(), auxiliartipoGrafo.end(), auxiliartipoGrafo.begin(), ::tolower);

        if(auxiliartipoGrafo == "nao direcionado" || auxiliartipoGrafo == "nao" || auxiliartipoGrafo == "0")
        {
            TipoGrafo = false;//nao direcionado
            cout << TerminalColors::Green;
            cout << "Grafo definido como nao direcionado." << endl;
            break;
        }
        else if(auxiliartipoGrafo == "direcionado" || auxiliartipoGrafo == "direc" || auxiliartipoGrafo == "1")
        {
            TipoGrafo = true;//direcionado
            cout << TerminalColors::Green;
            cout << "Grafo definido como direcionado." << endl;
            break;
        }
        else
        {
            cout << TerminalColors::Red;
            cout << "Tipo invalido" << endl;
            cout << "Use os seguintes tipos:" << endl;
            cout << TerminalColors::Yellow;
            cout << setw(20) << "Nao Direcionado:" << setw(10) << "(nao direcionado) ou (0)" << endl;
            cout << setw(20) << "Direcionado:" << setw(10) << "(direcionado) ou (1)" << endl;

        }
    }
    cout << TerminalColors::White;
    cout << endl;
}

void generateGrafo()
{
    generateGrafo(NumVertices, TipoDeEstrutura);
}

void printaEmulatorMenu()
{
    cout << TerminalColors::Green;
    cout << "Escolha a opção dentre as seguintes:" << endl;
    cout << TerminalColors::Yellow;
    cout << setw(20) << "Criar arresta:" << setw(10) << "(0)" << endl;
    cout << TerminalColors::Red;
    cout << "Para sair clique (Q)" << endl;
    cout << TerminalColors::White;
    cout << endl;
}

void adicionaArresta()
{
    int pontoA = -1;
    int pontoB = -1;
    while(pontoA == -1 || pontoB == -1)
    {
        if(pontoA == -1)
        {
            try
            {
                cout << TerminalColors::Green;
                cout << "Entre com o ponto A" << endl;
                cout << TerminalColors::White;
                string auxEntrada;
                cin >> auxEntrada;
                pontoA = stoi(auxEntrada);

                if(pontoA < 0 || pontoA >= NumVertices)
                {
                    pontoA = -1;
                    throw exception();
                }
            }
            catch(exception ex)
            {
                cout << TerminalColors::Red;
                cout << "Ponto A invalido!!!" << endl;
                cout << TerminalColors::White;
            }
        }
        if(pontoB == -1)
        {
            try
            {
                cout << TerminalColors::Green;
                cout << "Entre com o ponto B" << endl;
                cout << TerminalColors::White;

                string auxEntrada;
                cin >> auxEntrada;
                pontoB = stoi(auxEntrada);
                if(pontoB < 0 || pontoB >= NumVertices)
                {
                    pontoB = -1;
                    throw exception();
                }
            }
            catch(exception ex)
            {
                cout << TerminalColors::Red;
                cout << "Ponto B invalido!!!" << endl;
                cout << TerminalColors::White; 
            }
        }
    }
    adicionaArresta(pontoA, pontoB, NumVertices, TipoDeEstrutura, TipoGrafo);
}

void startEmulator()
{
    string entrada = "";
    cout << "" << endl;

    while(entrada != "q")
    {
        printaEmulatorMenu();
        cin >> entrada;
        transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
        if(entrada != "q")
        {
            try
            {
                int opcaoMenu = stoi(entrada);

                switch(opcaoMenu)
                {
                    case 0:
                        adicionaArresta();
                    break;
                    default:
                    throw exception();
                    break;
                }
            }
            catch(exception ex)
            {
            cout << TerminalColors::Red;
            cout << "Tipo invalido" << endl;
            cout << endl;
            }
        }
    }
    cout << endl;
    cout << TerminalColors::White;
}
