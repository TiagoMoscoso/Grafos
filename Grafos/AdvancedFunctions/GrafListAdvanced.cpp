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

