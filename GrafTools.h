#ifndef GRAFOTOOLS
#define GRAFOTOOLS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "TerminalColors.h"

list<int> ** ListGrap; //ListGrap[i]->push_back(2); to add
int ** MatrizGrap;

void aumentaTamanhoMatriz(int numVertices)
{
    MatrizGrap = (int **)malloc(numVertices * sizeof(int *));//linhas
    for (int i = 0; i < numVertices; i++) {
        MatrizGrap[i] = (int *)malloc(numVertices * sizeof(int));//colunas
        for (int j = 0; j < numVertices; j++)
        {
            MatrizGrap[i][j] = 0;
        }
    }

}

void printaMatriz(int numVertices)
{
    cout << TerminalColors::White;
    cout << "[" << " " << "]";
    
    for(int i = 0; i < numVertices; i++)
    {
        cout << "[" << i << "]";
    }

    cout<< endl;

    for(int i = 0; i < numVertices; i++)
    {
       cout << "[" << i << "]";
       for(int j = 0; j < numVertices; j++)
       {
            cout << "[" << MatrizGrap[i][j] << "]";
       } 
       cout<< endl;
    }
}

void aumentaTamanhoLista(int numVertices)
{
    ListGrap = (list<int> **)malloc(numVertices * sizeof(int *));//colunas
    for (int i = 0; i < numVertices; i++)
    {
        ListGrap[i] = new list<int>;
        ListGrap[i]->insert(ListGrap[i]->begin(), i);
    }
}

void printaLista(int numVertices)
{
    cout << TerminalColors::White;
    for (int i = 0; i < numVertices; i++)
    {
        for (auto it = ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it) 
        {
            cout << "[" << *it << "] -->";
        }
        cout<< endl;
    }
}

void generateGrafo(int numVertices, short tipoDeEstrutura)
{
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        aumentaTamanhoMatriz(numVertices);
        printaMatriz(numVertices);
        cout << TerminalColors::Green;
        cout << "Matriz criada com sucesso." << endl;
        cout << endl;
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        aumentaTamanhoLista(numVertices);
        printaLista(numVertices);
        cout << TerminalColors::Green;
        cout << "Lista criada com sucesso." << endl;
        cout << endl;
    }
}

void adicionaArrestaMatriz(int pontoA, int pontoB, bool tipoGrafo)
{
    MatrizGrap[pontoA][pontoB] = 1;

    if(!tipoGrafo)
        MatrizGrap[pontoB][pontoA] = 1;
}

void adicionaArrestaLista(int pontoA, int pontoB, bool tipoGrafo)
{
    ListGrap[pontoA]->push_back(pontoB);

    if(!tipoGrafo)
        ListGrap[pontoB]->push_back(pontoA);
}

void adicionaArresta(int pontoA, int pontoB, int numVertices, short tipoDeEstrutura, bool tipoGrafo)
{
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        adicionaArrestaMatriz(pontoA,pontoB,tipoGrafo);
        printaMatriz(numVertices);
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        adicionaArrestaLista(pontoA,pontoB,tipoGrafo);
        printaLista(numVertices);
    }
}

#endif