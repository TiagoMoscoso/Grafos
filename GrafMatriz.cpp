#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "TerminalColors.h"

int ** MatrizGrap;


int indentificaGrauMatriz(int pontoA, int numVertices, bool tipoGrafo)
{
    int counter = 0;
    for(int i = 0; i < numVertices; i++)
    {
        counter += MatrizGrap[pontoA][i];
    }
    if(tipoGrafo)
    {
        for(int i = 0; i < numVertices; i++)
        {
            if(i != pontoA)
                counter += MatrizGrap[i][pontoA];
        }
    }
    counter+= MatrizGrap[pontoA][pontoA];
    return counter;
}

bool indentificaSimplesMatriz(int numVertices)
{
    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numVertices; j++)
        {
            if((MatrizGrap[i][j] > 1) || (i==j && MatrizGrap[i][j] > 0))
            {
                return false;
            }
            
        }
    }
    return true;
}

bool identificaCompletoMatriz(int numVertices, bool tipoGrafo)
{
    if(!indentificaSimplesMatriz(numVertices))return false;
    if(!tipoGrafo)
    {
        for(int i = 0; i < numVertices; i++)
        {
            for(int j = 0; j < numVertices; j++)
            {
                if((i == j && MatrizGrap[i][j] > 0) || (i != j && MatrizGrap[i][j] == 0))return false;
            }
        }
    }
    else
    {
        for(int i = 0; i < numVertices; i++)
        {
            for(int j = 0; j < numVertices; j++)
            {
                if(i != j && MatrizGrap[i][j] == 0)
                {
                    if(MatrizGrap[j][i] == 0) return false;
                }
                else if(i == j && MatrizGrap[i][j] > 0)return false;
            }
        }
    }
    return true;
}

bool indentificaSuceMatriz(int pontoA, int pontoB, int numVertices)
{
    if(MatrizGrap[pontoB][pontoA] > 0) return true;
    return false;
}
bool indentificaPredeMatriz(int pontoA, int pontoB, int numVertices)
{   
    if(MatrizGrap[pontoA][pontoB] > 0) return true;
    return false;
}

bool indentificaViziMatriz(int pontoA, int pontoB, int numVertices)
{
    if(MatrizGrap[pontoA][pontoB] > 0) return true;
    return false;
}

void removeArrestaMatriz(int pontoA, int pontoB, bool tipoGrafo)
{
    if(MatrizGrap[pontoA][pontoB] > 0)
        MatrizGrap[pontoA][pontoB]--;

    if(!tipoGrafo && MatrizGrap[pontoB][pontoA] > 0)
        MatrizGrap[pontoB][pontoA]--;
        
}

void adicionaArrestaMatriz(int pontoA, int pontoB, bool tipoGrafo)
{
    MatrizGrap[pontoA][pontoB]++;

    if(!tipoGrafo && pontoA != pontoB)
        MatrizGrap[pontoB][pontoA]++;
}

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