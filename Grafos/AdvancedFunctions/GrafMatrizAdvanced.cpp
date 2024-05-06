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