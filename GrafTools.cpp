#ifndef GRAFOTOOLS
#define GRAFOTOOLS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "TerminalColors.h"

#include "GrafList.cpp"
#include "GrafMatriz.cpp"

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

void adicionaArresta(int pontoA, int pontoB, int numVertices, short tipoDeEstrutura, bool tipoGrafo)
{
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        adicionaArrestaMatriz(pontoA,pontoB,tipoGrafo);
        printaMatriz(numVertices);
        cout << endl;
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        adicionaArrestaLista(pontoA,pontoB,tipoGrafo);
        printaLista(numVertices);
        cout << endl;
    }
}

void removeArresta(int pontoA, int pontoB, int numVertices, short tipoDeEstrutura, bool tipoGrafo)
{
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        removeArrestaMatriz(pontoA,pontoB,tipoGrafo);
        printaMatriz(numVertices);
        cout << endl;
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        removeArrestaLista(pontoA,pontoB,tipoGrafo);
        printaLista(numVertices);
        cout << endl;
    }
}

void identificacaoDeVizinhanca(int pontoA, int pontoB, int numVertices, short tipoDeEstrutura)
{
    bool validacao = false;
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        validacao = indentificaViziMatriz(pontoA,pontoB,numVertices);
        printaMatriz(numVertices);
        cout << endl;
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        validacao = indentificaViziLista(pontoA,pontoB,numVertices);
        printaLista(numVertices);
        cout << endl;
    }

    if(validacao)
    {
        cout << TerminalColors::Green;
        cout << "O ponto "<< pontoA << " e o ponto "<< pontoB << " sao vizinhos."<< endl;
        cout << endl;
    }
    else
    {
        cout << TerminalColors::Red;
        cout << "O ponto "<< pontoA << " e o ponto "<< pontoB << " sao nao vizinhos."<< endl;
        cout << endl;
    }
    cout << TerminalColors::White;
}


void indentificacaoPredececao(int pontoA, int pontoB, int numVertices, short tipoDeEstrutura)
{
    bool validacao = false;
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        validacao = indentificaPredeMatriz(pontoA,pontoB,numVertices);
        printaMatriz(numVertices);
        cout << endl;
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        validacao = indentificaPredeLista(pontoA,pontoB,numVertices);
        printaLista(numVertices);
        cout << endl;
    }

    if(validacao)
    {
        cout << TerminalColors::Green;
        cout << "O ponto "<< pontoA << " e precede do ponto "<< pontoB << "."<< endl;
        cout << endl;
    }
    else
    {
        cout << TerminalColors::Red;
        cout << "O ponto "<< pontoA << " nao e precede do ponto "<< pontoB << "."<< endl;
        cout << endl;
    }
    cout << TerminalColors::White;
}

void indentificacaoSucecao(int pontoA, int pontoB, int numVertices, short tipoDeEstrutura)
{
    int validacao;
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        validacao = indentificaSuceMatriz(pontoA,pontoB,numVertices);
        printaMatriz(numVertices);
        cout << endl;
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        validacao = indentificaSuceLista(pontoA,pontoB,numVertices);
        printaLista(numVertices);
        cout << endl;
    }

    if(validacao)
    {
        cout << TerminalColors::Green;
        cout << "O ponto "<< pontoA << " e sucede do ponto "<< pontoB << "."<< endl;
        cout << endl;
    }
    else
    {
        cout << TerminalColors::Red;
        cout << "O ponto "<< pontoA << " nao sucede do ponto "<< pontoB << "."<< endl;
        cout << endl;
    }
    cout << TerminalColors::White;
}

void indentificacaoGrau(int pontoA, int numVertices, short tipoDeEstrutura, bool tipoGrafo)
{
    int validacao;
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        validacao = indentificaGrauMatriz(pontoA,numVertices,tipoGrafo);
        printaMatriz(numVertices);
        cout<< TerminalColors::Red;
        cout<< "( Matriz )";
        cout << TerminalColors::Green;
        cout << "O grau do ponto "<< pontoA << " e: " << validacao << endl;
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        validacao = indentificaGrauLista(pontoA,numVertices,tipoGrafo);
        printaLista(numVertices);
        cout<< TerminalColors::Red;
        cout<< "( Lista )";
        cout << TerminalColors::Green;
        cout << "O grau do ponto "<< pontoA << " e: " << validacao << endl;
    }

    cout << TerminalColors::White;
    cout<< endl;
}

void indentificaSimples(int numVertices, short tipoDeEstrutura)
{
    bool validacao = false;
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        validacao = indentificaSimplesMatriz(numVertices);
        printaMatriz(numVertices);
        cout<< TerminalColors::Red;
        cout<< "( Matriz )";
        if(validacao)
        {
            cout << TerminalColors::Green;
            cout << "O grafo e simples"<< endl;
        }
        else
        { 
            cout << TerminalColors::Red;
            cout << "O grafo nao e simples"<< endl; 
        } 
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        validacao = indentificaSimplesLista(numVertices);
        printaLista(numVertices);
        cout<< TerminalColors::Red;
        cout<< "( Lista )";
        if(validacao)
        {
            cout << TerminalColors::Green;
            cout << "O grafo e simples"<< endl;
        }
        else
        { 
            cout << TerminalColors::Red;
            cout << "O grafo nao e simples"<< endl; 
        } 
    }
    cout << TerminalColors::White;
    cout<< endl;
}

void identificaCompleto(int numVertices, short tipoDeEstrutura , bool tipoGrafo)
{
        bool validacao = false;
    if(tipoDeEstrutura == 0 || tipoDeEstrutura == 2)
    {
        validacao = identificaCompletoMatriz(numVertices,tipoGrafo);
        printaMatriz(numVertices);
        cout<< TerminalColors::Red;
        cout<< "( Matriz )";
        if(validacao)
        {
            cout << TerminalColors::Green;
            cout << "O grafo e completo"<< endl;
        }
        else
        { 
            cout << TerminalColors::Red;
            cout << "O grafo nao e completo"<< endl; 
        } 
    }
    if(tipoDeEstrutura == 1 || tipoDeEstrutura == 2)
    {
        validacao = identificaCompletoLista(numVertices,tipoGrafo);
        printaLista(numVertices);
        cout<< TerminalColors::Red;
        cout<< "( Lista )";
        if(validacao)
        {
            cout << TerminalColors::Green;
            cout << "O grafo e completo"<< endl;
        }
        else
        { 
            cout << TerminalColors::Red;
            cout << "O grafo nao e completo"<< endl; 
        } 
    }
    cout << TerminalColors::White;
    cout<< endl;
}

#endif