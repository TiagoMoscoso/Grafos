#include "../GrafMatriz.cpp"
#include <stack>

class GrafMatrizAdvanced : public GrapMatriz
{
    public:
    queue<int> buscaLargura(int vertice, int numVertices)
    {
        queue<int> control;
        queue<int> queue;

        ValidationClass val = ValidationClass(numVertices);
        
        queue.push(vertice);

        while(queue.size() > 0)
        {
            int verticeAux = queue.front();
            val.Validation[verticeAux]++;
            queue.pop();

            for (int i = 0; i < numVertices; i++) 
            
            {
                if(MatrizGrap[verticeAux][i] > 0 && val.Validation[i] == 0)
                {
                    queue.push(i);
                    val.Validation[i]++;
                }
            }
            control.push(verticeAux);
        }

        return control;
    }

    queue<int> buscaProfundidade(int vertice, int numVertices)
    {
        queue<int> control;
        stack<int> stack;

        ValidationClass val = ValidationClass(numVertices);
        
        stack.push(vertice);

        while(stack.size() > 0)
        {
            int verticeAux = stack.top();
            val.Validation[verticeAux]++;
            stack.pop();

            for (int i = 0; i < numVertices; i++) 
            
            {
                if(MatrizGrap[verticeAux][i] > 0 && val.Validation[i] == 0)
                {
                    stack.push(i);
                    val.Validation[i]++;
                }
            }
            control.push(verticeAux);
        }

        return control;
    }

    int dijkstra(int pontoA, int pontoB,int numVertices)
    {
        ValidationClass val = ValidationClass(numVertices);
        list<int> control;
        control.push_back(pontoA);
        while(!control.empty())
        {
            int vert = control.front();
            control.pop_front();
            for(int j = 0; j < numVertices; j++)
            {
                if(vert == j || j == pontoA) continue;
                if(MatrizGrap[vert][j] > 0 && (val.Validation[j] == 0 || val.Validation[j] > (MatrizGrap[vert][j] + val.Validation[vert])))
                {
                    control.push_back(j);
                    val.Validation[j] = MatrizGrap[vert][j] + val.Validation[vert];
                }
            }
            
        }
        return val.Validation[pontoB];
    }

    bool grafoConexo(int numVertices)
    {
        int globalComponent = 0;
        ValidationClass val = ValidationClass(numVertices);
        val.negativeValidation(numVertices);

        for (int i = 0; i < numVertices; i++) 
        {
            queue<int> control = buscaProfundidade(i, numVertices);
            int internalComponent = -1;

            while (!control.empty()) 
            {
                int vertex = control.front();
                control.pop();

                if(val.Validation[vertex] >= 0)
                {
                    if(internalComponent == -1)
                    {
                        internalComponent = val.Validation[vertex];
                    }
                    else if(val.Validation[vertex] != internalComponent)
                    {
                        for(int x= 0; x < numVertices; x++)
                        {
                            if(val.Validation[x] == internalComponent)
                            {
                                val.Validation[x] = val.Validation[vertex];
                            }
                        }
                        internalComponent = val.Validation[vertex];
                    }

                    val.Validation[vertex] = internalComponent;
                }
                else
                {
                    if(internalComponent == -1)
                    {
                        internalComponent = globalComponent;
                        globalComponent++;
                    }
                    val.Validation[vertex] = internalComponent;
                }
            }
        }
        val.printValidation(numVertices);
        return val.verifyValidationDiferentZero(numVertices);
    }
    ValidationClass kruskal(int pontoA, int pontoB,int numVertices, bool tipoGrafo)
    {
        list<ExtendedListClass> auxGrafList = sortedListByArray(MatrizGrap,numVertices,tipoGrafo);
        int numArestas = auxGrafList.size();
        ValidationClass val = ValidationClass(numVertices);
        val.negativeValidation(numVertices);
        while(!auxGrafList.empty())
        {
            ExtendedListClass lc = auxGrafList.front();
            auxGrafList.pop_front();

            list<int> queuePai;
            list<int> queuefilho;
            int valuePai = lc.pai;
            int valueFilho = lc.vertice;

            while (valuePai >= 0)
            {
                queuePai.push_front(valuePai);
                valuePai = val.Validation[valuePai];


                if (!queuePai.empty() && valuePai >= 0)
                {
                    for(auto it = queuePai.begin(); it != queuePai.end(); it++)
                    {
                        if(*it == valuePai)
                        {
                            queuePai.clear();
                            valuePai = -1;
                        }
                        }
                } 
            }

            while (valueFilho >= 0)
            {
                queuefilho.push_front(valueFilho);
                valueFilho = val.Validation[valueFilho];


                if (!queuefilho.empty() && valueFilho >= 0)
                {
                    for(auto it = queuefilho.begin(); it != queuefilho.end(); it++)
                    {
                        if(*it == valueFilho)
                        {
                            queuefilho.clear();
                            valueFilho = -1;
                        }
                        }
                } 
            }



            if(!queuePai.empty() && !queuefilho.empty())
            {
                int auxPai = *queuePai.begin();
                int auxFilho = *queuefilho.begin();
                val.Validation[auxFilho]+=val.Validation[auxPai];
                val.Validation[auxPai]=auxFilho;
            }
            
            
            
        }
        return val;
    }

    queue<int> ordenacaoTopologica(int numVertices)
    {
        queue<int> control;

        int** auxGrafMat = copyMatrix(MatrizGrap,numVertices);
        int toBevisited = numVertices;
        int tentativas = numVertices;

        ValidationClass val = ValidationClass(numVertices);
        
        while(toBevisited > 0 && tentativas > 0)
        {
            for(int i = 0; i < numVertices; i++)
            {
                if(val.Validation[i] == 0 && sumCollum(numVertices,i,auxGrafMat)==0)
                {
                    val.Validation[i]++;
                    auxGrafMat = cleanLine(numVertices, i,auxGrafMat);
                    control.push(i);
                    toBevisited--;
                }
            }
            tentativas--;
        }


        return control;
    }
    
};