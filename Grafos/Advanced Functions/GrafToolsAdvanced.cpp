#include "..\GrafTools.cpp"
class GrafToolsAdvanced : public GrafTools
{
    public:
    void buscaLargura(int vertice)
    {
        queue<int> largura;

        if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
        {
            largura = GfMt.buscaLargura(vertice, NumVertices);    
            if(Print)
                GfMt.printaMatriz(NumVertices);

        }
        if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
        {
            largura = GfLs.buscaLargura(vertice, NumVertices);
            if(Print)
                GfLs.printaLista(NumVertices);
        }
            
        cout << TerminalColors::Green;
        cout << "A quantidade de nos vizitados a partir de "<< vertice << " é de "<< largura.size()-1 << endl;
        cout << endl;

        cout << TerminalColors::Green;
        cout << "A fila da busca deu: "<< endl;
        while (!largura.empty())
        {
            std::cout<<"[" << largura.front() << "] -->";
            cout << TerminalColors::White;
            largura.pop();
        }
        
    }

    void buscaProfundidade(int vertice)
    {
        queue<int> profundidade;

        if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
        {
            profundidade = GfMt.buscaProfundidade(vertice, NumVertices);    
            if(Print)
                GfMt.printaMatriz(NumVertices);

        }
        if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
        {
            profundidade = GfLs.buscaProfundidade(vertice, NumVertices);
            if(Print)
                GfLs.printaLista(NumVertices);
        }
            
        cout << TerminalColors::Green;
        cout << "A quantidade de nos vizitados a partir de "<< vertice << " é de "<< profundidade.size()-1 << endl;
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