#include "../GrafList.cpp"

class GrafListAdvanced : public GrafList
{
    public:
    queue<int> buscaProfundidade(int vertice, int numVertices)
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
};

