#include "..\GrafTools.cpp"
class GrafToolsAdvanced : public GrafTools
{
    public:
    void buscaProfundidade(int vertice)
    {
        queue<int> profundidade = GfLs.buscaProfundidade(vertice, NumVertices);
        if(Print)
            GfLs.printaLista(NumVertices);
            
        cout << TerminalColors::Green;
        cout << "A quantidade de nos vizitados a partir de"<< vertice << " é de "<< profundidade.size()-1 << endl;
        cout << endl;

        cout << TerminalColors::Green;
        cout << "A fila da busca deu: "<< endl;
        while (!profundidade.empty())
        {
            std::cout<<"[" << profundidade.front() << "] -->";
            cout << TerminalColors::White;
            profundidade.pop();
        }
        
    }
};