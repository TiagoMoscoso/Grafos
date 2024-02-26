#include <iostream>
#include "../Utils/TerminalColors.h"

class GrapMatriz
{
    private:
        int ** MatrizGrap;

    public:
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
};