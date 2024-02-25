#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "TerminalColors.h"

list<int> ** ListGrap; //ListGrap[i]->push_back(2); to add

int * generateValidation(int num)
{
    int * Validation = (int *)malloc(num * sizeof(int *));
    for(int i = 0; i < num; i++)
    {
        Validation[i] = 0;
    }
    return Validation;
}

bool indentificaSimplesLista(int numVertices)
{
    int * Validation;
    for(int i = 0; i < numVertices; i++)
    {
        Validation = generateValidation(numVertices);
        for (auto it = ++ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it) 
        {
            Validation[*it]++;
            if(Validation[*it] > 1 || *it == i)
            {
                free(Validation);
                return false;
            }
        }     
    }
    free(Validation);  
    return true;
}

bool identificaCompletoLista(int numVertices, bool tipoGrafo)
{
    if(!indentificaSimplesLista(numVertices))return false;
    int * Validation;
    if(!tipoGrafo)
    {
        for(int i = 0; i < numVertices; i++)
        {
            Validation = generateValidation(numVertices);
            for (auto it = ++ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it)
            {
                Validation[*it]++;
            } 
            for(int j = 0; j < numVertices; j++)
            {
                if((Validation[j] == 0 && j != i) || ( Validation[j] > 0 && j == i )) return false; 
            }
        }
    }
    else
    {
        for(int i = 0; i < numVertices; i++)
        {
            Validation = generateValidation(numVertices);
            for (auto it = ++ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it)
            {
                Validation[*it]++;
            }
             
            for(int j = 0; j < numVertices; j++)
            {
                if(Validation[j] == 0 && j != i)
                {
                    bool localValidation = false;
                    for (auto it = ++ListGrap[j]->begin(); it != ListGrap[j]->end(); ++it)
                    {
                        if(*it == i) localValidation = true;
                    }
                    
                    if(!localValidation) return false;
                } 
                else if(j == i && Validation[j] > 0)
                {
                    return false; 
                }
            }
        }
    }
    return true;
}

int indentificaGrauLista(int pontoA, int numVertices, bool tipoGrafo)
{
    int counter = 0;
    for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
    {
        if (*it == pontoA)
        {
            counter++;
        }
        counter++;
    }
    if(tipoGrafo)
    {
        for(int x = 0; x < numVertices; ++x)
        {
            if(x!=pontoA)
            {
                for (auto it = ListGrap[x]->begin(); it != ListGrap[x]->end(); ++it) 
                {
                    if (*it == pontoA)
                    {
                        counter++;
                    }
                }
            }
        }
    }
    return counter;
}

bool indentificaSuceLista(int pontoA,int pontoB,int numVertices)
{
    for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
    {
        if(*it == pontoB)
        {
            return true;
        }
    }
    return false;
}
bool indentificaPredeLista(int pontoA,int pontoB,int numVertices)
{
    for (auto it = ++ListGrap[pontoB]->begin(); it != ListGrap[pontoB]->end(); ++it) 
    {
        if(*it == pontoA)
        {
            return true;
        }
    }
    return false;
}
void removeArrestaLista(int pontoA, int pontoB, bool tipoGrafo)
{
    
    for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
    {
        if(*it == pontoB)
        {
            ListGrap[pontoA]->erase(it);
            break;
        }
    }


    if(!tipoGrafo && pontoA != pontoB)
    {
        for (auto it = ++ListGrap[pontoB]->begin(); it != ListGrap[pontoB]->end(); ++it) 
        {
            if(*it == pontoA)
            {
                ListGrap[pontoB]->erase(it);
                break;
            }
        }
    }
}

void adicionaArrestaLista(int pontoA, int pontoB, bool tipoGrafo)
{
    ListGrap[pontoA]->push_back(pontoB);

    if(!tipoGrafo && pontoA != pontoB)
        ListGrap[pontoB]->push_back(pontoA);
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

bool indentificaViziLista(int pontoA, int pontoB, int numVertices)
{
    for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
    {
        if(*it == pontoB)
        {
            return true;
        }
    }
    return false;
}