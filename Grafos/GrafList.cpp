#include <iostream>
#include <list>
#include "../Utils/TerminalColors.h"
#include "../Utils/GenerateValidation.h"
#include <queue>
#include "../Utils/GenerateRandomNum.h"
#include "../Utils/FrequencyInList.h"
#include "../Utils/RemoveItemList.h"
#include "../Utils/Cleanlist.h"
#include "../Utils/CopyList.h"
#include "ListClass.cpp"
#include "../Utils/SortList.H"
class GrafList
{
    protected:
        list<ListClass> ** ListGrap; //ListGrap[i]->push_back(2); to add
    public:
        bool verificaBipartido(int numVertices)
        {
            int *corArray = (int *)calloc(numVertices, sizeof(int *));

            for (int i = 0; i < numVertices; ++i)
                    corArray[i] = -1;

            queue<int> fila;
            
            GenerateRandomNum gen;
            ValidationClass valid(numVertices);

            int contador = numVertices;

            while (!fila.empty() || contador > 0)
            {
                    if(fila.empty() && contador > 0)
                    {
                        while(true)
                        {
                          int gerado = gen.GenerateRandomInt(numVertices-1);
                          if(valid.Validation[gerado] == 0)
                          {
                              fila.push(gerado);
                              contador--;
                              corArray[gerado] = 1;
                              break;
                          }
                        }
                    }
                    int primeiroFila = fila.front();
                    fila.pop();
                    valid.Validation[primeiroFila]++;
            
                        for (auto vert = ++ListGrap[primeiroFila]->begin(); vert != ListGrap[primeiroFila]->end(); ++vert) 
                        {
                            if(primeiroFila == vert->vertice)
                                return false;
                            if (corArray[vert->vertice] == -1)
                            {
                                corArray[vert->vertice] = 1 - corArray[primeiroFila];
                                fila.push(vert->vertice);
                                contador--;
                            }
                            else if(corArray[vert->vertice] == corArray[primeiroFila])
                                return false;
                        }
            }

            return true;
        }
        bool indentificaSimples(int numVertices)
        {
            ValidationClass valid(numVertices);
            for(int i = 0; i < numVertices; i++)
            {
                valid.resetValidation(numVertices);
                for (auto it = ++ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it) 
                {
                    valid.Validation[it->vertice]++;
                    if(valid.Validation[it->vertice] > 1 || it->vertice == i)
                    {
                        free(valid.Validation);
                        return false;
                    }
                }     
            }
            free(valid.Validation);  
            return true;
        }

        bool identificaCompleto(int numVertices, bool tipoGrafo)
        {
            if(!indentificaSimples(numVertices))return false;
            ValidationClass valid(numVertices);
            if(!tipoGrafo)
            {
                for(int i = 0; i < numVertices; i++)
                {
                    valid.resetValidation(numVertices);
                    for (auto it = ++ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it)
                    {
                        valid.Validation[it->vertice]++;
                    } 
                    for(int j = 0; j < numVertices; j++)
                    {
                        if((valid.Validation[j] == 0 && j != i) || ( valid.Validation[j] > 0 && j == i )){ 
                            free(valid.Validation);  
                            return false;
                        }
                    }
                }
            }
            else
            {
                for(int i = 0; i < numVertices; i++)
                {
                    valid.resetValidation(numVertices);
                    for (auto it = ++ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it)
                    {
                        valid.Validation[it->vertice]++;
                    }
                    
                    for(int j = 0; j < numVertices; j++)
                    {
                        if(valid.Validation[j] == 0 && j != i)
                        {
                            bool localValidation = false;
                            for (auto it = ++ListGrap[j]->begin(); it != ListGrap[j]->end(); ++it)
                            {
                                if(it->vertice == i) localValidation = true;
                            }
                            
                            if(!localValidation)
                            {
                                free(valid.Validation); 
                                return false; 
                            }
                        } 
                        else if(j == i && valid.Validation[j] > 0)
                        {
                            free(valid.Validation); 
                            return false; 
                        }
                    }
                }
            }
            free(valid.Validation); 
            return true;
        }

        int indentificaGrau(int pontoA, int numVertices, bool tipoGrafo)
        {
            int counter = 0;
            for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
            {
                if (it->vertice == pontoA)
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
                            if (it->vertice == pontoA)
                            {
                                counter++;
                            }
                        }
                    }
                }
            }
            return counter;
        }

        bool indentificaPrede(int pontoA,int pontoB,int numVertices)
        {
            for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
            {
                if(it->vertice== pontoB)
                {
                    return true;
                }
            }
            return false;
        }
        bool indentificaSuce(int pontoA,int pontoB,int numVertices)
        {
            //todo
            for (auto it = ++ListGrap[pontoB]->begin(); it != ListGrap[pontoB]->end(); ++it) 
            {
                if(it->vertice == pontoA)
                {
                    return true;
                }
            }
            return false;
        }
        void removeAresta(int pontoA, int pontoB, bool tipoGrafo)
        {
            
            for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
            {
                if(it->vertice == pontoB)
                {
                    ListGrap[pontoA]->erase(it);
                    break;
                }
            }


            if(!tipoGrafo && pontoA != pontoB)
            {
                for (auto it = ++ListGrap[pontoB]->begin(); it != ListGrap[pontoB]->end(); ++it) 
                {
                    if(it->vertice == pontoA)
                    {
                        ListGrap[pontoB]->erase(it);
                        break;
                    }
                }
            }
        }

        void adicionaAresta(int pontoA, int pontoB, bool tipoGrafo, int valueAresta, bool ponderado)
        {
            if(ponderado)
                removeAresta(pontoA, pontoB, tipoGrafo);//motivo matriz so suporta 1 aresta ponderada
            
            ListGrap[pontoA]->push_back(ListClass(pontoB,valueAresta));

            if(!tipoGrafo && pontoA != pontoB)
                ListGrap[pontoB]->push_back(ListClass(pontoA,valueAresta));
        }


        void aumentaTamanho(int numVertices)
        {
            ListGrap = (list<ListClass> **)malloc(numVertices * sizeof(int *));//colunas
            for (int i = 0; i < numVertices; i++)
            {
                ListGrap[i] = new list<ListClass>;
                ListGrap[i]->insert(ListGrap[i]->begin(), i);
            }
        }

        void printaLista(int numVertices, bool ponderado)
        {
            for (int i = 0; i < numVertices; i++)
            {
                cout << TerminalColors::Green;
                for (auto it = ListGrap[i]->begin(); it != ListGrap[i]->end(); ++it) 
                {
                    if(numVertices < 10 ||  i >= 10 )
                    {
                        if(ponderado && it != ListGrap[i]->begin())
                        {
                            cout << TerminalColors::Red;
                            cout << "{" << it->peso << "}->";
                            cout << TerminalColors::White;
                        }
                        cout << "[" << it->vertice << "] -->";
                    }
                    else
                    {
                        if(ponderado && it != ListGrap[i]->begin())
                        {
                            cout << TerminalColors::Red;
                            cout << "{" << it->peso << "}->";
                            cout << TerminalColors::White;
                        }
                        cout << "[ " << it->vertice << "] -->";
                    }
                    cout << TerminalColors::White;
                }
                cout<< endl;
            }
            
        }

        bool indentificaVizi(int pontoA, int pontoB, int numVertices)
        {
            for (auto it = ++ListGrap[pontoA]->begin(); it != ListGrap[pontoA]->end(); ++it) 
            {
                if(it->vertice == pontoB)
                {
                    return true;
                }
            }
            return false;
        }

        void adicionaVertice(int numVertices, int numAdicionar)
        {
            list<ListClass> ** ListGrapAux;

            ListGrapAux = (list<ListClass> **)malloc((numVertices+numAdicionar) * sizeof(int *));//colunas
            for (int i = 0; i < (numVertices+numAdicionar); i++)
            {
                if(i >= numVertices)
                {
                    ListGrapAux[i] = new list<ListClass>;
                    ListGrapAux[i]->insert(ListGrapAux[i]->begin(), i);
                }
                else
                {
                    ListGrapAux[i] = ListGrap[i];   
                }
            }
            
            ListGrap = ListGrapAux;
        }

        bool verificaRegular(int numVertices, bool tipoGrafo)
        {
            GenerateRandomNum gen;
            int numeroDeGraus = indentificaGrau(gen.GenerateRandomInt(numVertices-1),numVertices,tipoGrafo); 
            for(int i = 0; i < numVertices; i++)
            {
                if(numeroDeGraus != indentificaGrau(i,numVertices,tipoGrafo))
                    return false;
            }
            return true;
        }
};