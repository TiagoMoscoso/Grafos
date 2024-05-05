#include <iostream>
#include "../Utils/TerminalColors.h"
#include "../Utils/MergeGrafos.h"
#include "../Utils/GenerateValidation.h"
#include <queue>
#include "../Utils/GenerateRandomNum.h"

class GrapMatriz
{
    private:
        int ** MatrizGrap;

    public:
        bool verificaBipartido(int numVertices)
        {
            int *corArray = (int *)calloc(numVertices, sizeof(int *));

            for (int i = 0; i < numVertices; ++i)
                    corArray[i] = -1;
            

            queue <int> fila;

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
                    
                    if (MatrizGrap[primeiroFila][primeiroFila] > 0)
                        return false; 

                    for (int vert = 0; vert < numVertices; vert++)
                    {
                        if(MatrizGrap[primeiroFila][vert] > 0)
                        {
                            if (corArray[vert] == -1)
                            {
                                corArray[vert] = 1 - corArray[primeiroFila];
                                fila.push(vert);
                                contador--;
                            }
                            else if(corArray[vert] == corArray[primeiroFila])
                                return false;
                        }
                    }
                }

            return true;
        }
        int retornaSubConjuntos(int numVertices)
        {
            int numDeGrafos = 1;
            int ** Grafos;

            Grafos[0] = MatrizGrap[0];
            for (int j = 1; j < numVertices; j++)
            {
                int adicionado = 0;
                for (int i = 0; i < numDeGrafos; i++)
                {
                    if(Grafos[i][j] >= 1)
                    {
                        adicionado++;
                        Grafos[i] = mergeGrafos(numVertices, Grafos[i], MatrizGrap[j]);
                    }
                }
                if(adicionado == 0)
                {
                    Grafos[numDeGrafos] = MatrizGrap[j];
                    numDeGrafos++;
                }
                else if(adicionado > 1)
                {
                    int GrafoContain = -1;
                    for(int i = 0; i < numDeGrafos; i++)
                    {
                        if(Grafos[i][j]>=1)
                        {
                            if(GrafoContain>-1)
                            {
                                Grafos[GrafoContain] = mergeGrafos(numVertices, Grafos[GrafoContain], Grafos[i]);
                                if(i+1 != numDeGrafos)
                                {
                                    Grafos[i] = Grafos[numDeGrafos-1];
                                    free(Grafos[numDeGrafos-1]);
                                    i--;
                                }
                                numDeGrafos--;
                            }
                            else
                            {
                                GrafoContain = i;
                            }
                        }
                    }    
                }
            }
            free(Grafos);
            return numDeGrafos;
        }
        int indentificaGrau(int pontoA, int numVertices, bool tipoGrafo)
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

        bool indentificaSimples(int numVertices)
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

        bool identificaCompleto(int numVertices, bool tipoGrafo)
        {
            if(!indentificaSimples(numVertices))return false;
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

        bool indentificaSuce(int pontoA, int pontoB, int numVertices)
        {
            if(MatrizGrap[pontoB][pontoA] > 0) return true;
            return false;
        }
        bool indentificaPrede(int pontoA, int pontoB, int numVertices)
        {   
            if(MatrizGrap[pontoA][pontoB] > 0) return true;
            return false;
        }

        bool indentificaVizi(int pontoA, int pontoB, int numVertices)
        {
            if(MatrizGrap[pontoA][pontoB] > 0) return true;
            return false;
        }

        void removeArresta(int pontoA, int pontoB, bool tipoGrafo)
        {
            if(MatrizGrap[pontoA][pontoB] > 0)
                MatrizGrap[pontoA][pontoB]--;

            if(!tipoGrafo && MatrizGrap[pontoB][pontoA] > 0)
                MatrizGrap[pontoB][pontoA]--;
                
        }

        void adicionaArresta(int pontoA, int pontoB, bool tipoGrafo)
        {
            MatrizGrap[pontoA][pontoB]++;

            if(!tipoGrafo && pontoA != pontoB)
                MatrizGrap[pontoB][pontoA]++;
        }

        void aumentaTamanho(int numVertices)
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
            cout << TerminalColors::Green;
            if(numVertices < 10)
                cout << "[" << " " << "]";
            else
                cout << "[" << "  " << "]";
            
            for(int i = 0; i < numVertices; i++)
            {
                if(numVertices < 10 ||  i >= 10 )
                    cout << "[" << i << "]";
                else
                    cout << "[ " << i << "]";
            }

            cout<< endl;

            for(int i = 0; i < numVertices; i++)
            {
                cout << TerminalColors::Green;
                if(numVertices < 10 ||  i >= 10 ) 
                    cout << "[" << i << "]";
                else
                    cout << "[ " << i << "]";
                for(int j = 0; j < numVertices; j++)
                {  
                    cout << TerminalColors::White;
                    if(numVertices < 10 ||  MatrizGrap[i][j] >= 10 ) 
                        cout << "[" << MatrizGrap[i][j] << "]";
                    else
                        cout << "[ " << MatrizGrap[i][j] << "]";
                } 
            cout<< endl;
            }
        }
        void adicionaVertice(int numVertices, int numAdicionar)
        {
            int ** MatrizGrapAux;

            MatrizGrapAux = (int **)malloc((numVertices+numAdicionar) * sizeof(int *));//linhas
            for (int i = 0; i < (numVertices+numAdicionar); i++) {
                MatrizGrapAux[i] = (int *)malloc((numVertices+numAdicionar) * sizeof(int));//colunas
                for (int j = 0; j < numVertices+numAdicionar; j++)
                {
                    if(j >= numVertices || i >= numVertices)
                    {
                        MatrizGrapAux[i][j] = 0;
                    }
                    else
                    {
                        MatrizGrapAux[i][j] = MatrizGrap[i][j];
                    }
                }
            }

            MatrizGrap = MatrizGrapAux;
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