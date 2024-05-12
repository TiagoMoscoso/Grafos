#include "../GrafList.cpp"
#include <stack>
class GrafListAdvanced : public GrafList
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

            for (auto it = ++ListGrap[verticeAux]->begin(); it != ListGrap[verticeAux]->end(); ++it) 
            {
                if(val.Validation[it->vertice] == 0)
                {
                    queue.push(it->vertice);
                    val.Validation[it->vertice]++;
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

            for (auto it = ++ListGrap[verticeAux]->begin(); it != ListGrap[verticeAux]->end(); ++it) 
            {
                if(val.Validation[it->vertice] == 0)
                {
                    stack.push(it->vertice);
                    val.Validation[it->vertice]++;
                }
            }
            control.push(verticeAux);
        }
        
        return control;
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


    int dijkstra(int pontoA, int pontoB,int numVertices)
    {
        ValidationClass val = ValidationClass(numVertices);
        list<int> control;
        control.push_back(pontoA);
        while(!control.empty())
        {
            int vert = control.front();
            control.pop_front();
            for(auto it = ++ListGrap[vert]->begin(); it != ListGrap[vert]->end(); ++it)
            {
                if(val.Validation[it->vertice] == 0 || val.Validation[it->vertice] > (it->peso + val.Validation[vert]) && it->vertice != pontoA && it->vertice != ListGrap[vert]->begin()->vertice)
                {

                    control.push_back(it->vertice);
                    val.Validation[it->vertice] = it->peso + val.Validation[vert];
                }
            }
        }
        return val.Validation[pontoB];
    }
    ValidationClass kruskal(int pontoA, int pontoB,int numVertices, bool tipoGrafo)
    {
        list<ExtendedListClass> auxGrafList = sortList(ListGrap,numVertices,tipoGrafo);
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

        list<ListClass>** auxGrafList = copyList(ListGrap,numVertices);
        int toBevisited = numVertices;
        int tentativas = numVertices;

        ValidationClass val = ValidationClass(numVertices);
        
        while(toBevisited > 0 && tentativas > 0)
        {
            for(int i = 0; i < numVertices; i++)
            {
                if(val.Validation[i] == 0 && frequencyInTheList(i,numVertices,auxGrafList)==1)
                {
                    val.Validation[i]++;
                    auxGrafList = cleanItemList(i, numVertices,auxGrafList);
                    control.push(i);
                    toBevisited--;
                }
            }
            tentativas--;
        }


        return control;
    }
};

