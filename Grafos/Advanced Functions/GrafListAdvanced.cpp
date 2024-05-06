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
                if(val.Validation[*it] == 0)
                {
                    queue.push(*it);
                    val.Validation[*it]++;
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
                if(val.Validation[*it] == 0)
                {
                    stack.push(*it);
                    val.Validation[*it]++;
                }
            }
            control.push(verticeAux);
        }

        return control;
    }
};

