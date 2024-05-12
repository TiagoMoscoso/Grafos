
#include "AdvancedFunctions\GrafListAdvanced.cpp"
#include "AdvancedFunctions\GrafMatrizAdvanced.cpp"
#include <random>
#include "../Utils/GenerateValidation.h"

class GrafTools
{
    protected:
    GrafListAdvanced GfLs;
    GrafMatrizAdvanced GfMt;
    bool Print = false;
    public:
        int NumVertices = 0;
        short TipoDeEstrutura = -1;//0 matriz, 1 lista, 2 matriz e lista
        bool TipoGrafo;// true direcionado, false nao direcionado
        bool Ponderado = false;
        
        void setPrint()
        {
            Print = !Print;
        }

        void setPonderador()
        {
            Ponderado = !Ponderado;
        }

        void verificaBipartido()
        {
            bool validacao = false;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.verificaBipartido(NumVertices);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.verificaBipartido(NumVertices);
                if(Print)
                    GfLs.printaLista(NumVertices,NumVertices);
                cout << endl;
            }

            if(validacao)
            {
                cout << TerminalColors::Green;
                cout << "Sim e bipartido." << endl;
                cout << endl;
            }
            else
            {
                cout << TerminalColors::Green;
                cout << "Nao e bipartido." << endl;
                cout << endl;
            }
        }

        void generateGrafo()
        {
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                GfMt.aumentaTamanho(NumVertices);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << TerminalColors::Green;
                cout << "Matriz criada com sucesso." << endl;
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                GfLs.aumentaTamanho(NumVertices);
                if(Print)
                    GfLs.printaLista(NumVertices,NumVertices);
                cout << TerminalColors::Green;
                cout << "Lista criada com sucesso." << endl;
                cout << endl;
            }
        }

        void adicionaAresta(int pontoA, int pontoB, int valueAresta)
        {
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                GfMt.adicionaAresta(pontoA,pontoB,TipoGrafo,valueAresta);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                GfLs.adicionaAresta(pontoA,pontoB,TipoGrafo,valueAresta,Ponderado);
                if(Print)
                    GfLs.printaLista(NumVertices,NumVertices);
                cout << endl;
            }
        }

        void criaGrafoAleatorio(int numAresta)
        {
            random_device rd;
            mt19937 gerador(rd());
            uniform_int_distribution<int> distribuicao(0, NumVertices-1);
            uniform_int_distribution<int> ponderador(0, 10);
            for(int i = 0; i < numAresta; i++)
            {
                int pontoA = distribuicao(gerador);
                int pontoB = distribuicao(gerador);
                int value = 1;
                if(Ponderado)
                {
                    value = ponderador(gerador);
                    if(value == 0)
                        value = 1;
                }

                if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
                {
                    GfMt.adicionaAresta(pontoA,pontoB,TipoGrafo,value);
                }
                if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
                {
                    GfLs.adicionaAresta(pontoA,pontoB,TipoGrafo,value,Ponderado);
                }
            }

            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout << endl;
            }
            cout << TerminalColors::Green;
            cout << "Grafo randomico gerado com sucesso."<< endl;
            cout << endl;
            cout << TerminalColors::White;
        }
        void removeAresta(int pontoA, int pontoB)
        {
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                GfMt.removeAresta(pontoA,pontoB,TipoGrafo,Ponderado);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                GfLs.removeAresta(pontoA,pontoB,TipoGrafo);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout << endl;
            }
        
        }

        void identificacaoDeVizinhanca(int pontoA, int pontoB)
        {
            bool validacao = false;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.indentificaVizi(pontoA,pontoB,NumVertices);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.indentificaVizi(pontoA,pontoB,NumVertices);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout << endl;
            }

            if(validacao)
            {
                cout << TerminalColors::Green;
                cout << "O ponto "<< pontoA << " e o ponto "<< pontoB << " sao vizinhos."<< endl;
                cout << endl;
            }
            else
            {
                cout << TerminalColors::Red;
                cout << "O ponto "<< pontoA << " e o ponto "<< pontoB << " sao nao vizinhos."<< endl;
                cout << endl;
            }
            cout << TerminalColors::White;
        }


        void indentificacaoPredececao(int pontoA, int pontoB)
        {
            bool validacao = false;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.indentificaPrede(pontoA,pontoB,NumVertices);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.indentificaPrede(pontoA,pontoB,NumVertices);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout << endl;
            }

            if(validacao)
            {
                cout << TerminalColors::Green;
                cout << "O ponto "<< pontoA << " e precede do ponto "<< pontoB << "."<< endl;
                cout << endl;
            }
            else
            {
                cout << TerminalColors::Red;
                cout << "O ponto "<< pontoA << " nao e precede do ponto "<< pontoB << "."<< endl;
                cout << endl;
            }
            cout << TerminalColors::White;
        }

        void indentificacaoSucecao(int pontoA, int pontoB)
        {
            int validacao;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.indentificaSuce(pontoA,pontoB,NumVertices);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.indentificaSuce(pontoA,pontoB,NumVertices);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout << endl;
            }

            if(validacao)
            {
                cout << TerminalColors::Green;
                cout << "O ponto "<< pontoA << " e sucede do ponto "<< pontoB << "."<< endl;
                cout << endl;
            }
            else
            {
                cout << TerminalColors::Red;
                cout << "O ponto "<< pontoA << " nao sucede do ponto "<< pontoB << "."<< endl;
                cout << endl;
            }
            cout << TerminalColors::White;
        }

        void indentificacaoGrau(int pontoA)
        {
            int validacao;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.indentificaGrau(pontoA,NumVertices,TipoGrafo);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout<< TerminalColors::Red;
                cout<< "( Matriz )";
                cout << TerminalColors::Green;
                cout << "O grau do ponto "<< pontoA << " e: " << validacao << endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.indentificaGrau(pontoA,NumVertices,TipoGrafo);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout<< TerminalColors::Red;
                cout<< "( Lista )";
                cout << TerminalColors::Green;
                cout << "O grau do ponto "<< pontoA << " e: " << validacao << endl;
            }

            cout << TerminalColors::White;
            cout<< endl;
        }

        void indentificaSimples()
        {
            bool validacao = false;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.indentificaSimples(NumVertices);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout<< TerminalColors::Red;
                cout<< "( Matriz )";
                if(validacao)
                {
                    cout << TerminalColors::Green;
                    cout << "O grafo e simples"<< endl;
                }
                else
                { 
                    cout << TerminalColors::Red;
                    cout << "O grafo nao e simples"<< endl; 
                } 
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.indentificaSimples(NumVertices);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout<< TerminalColors::Red;
                cout<< "( Lista )";
                if(validacao)
                {
                    cout << TerminalColors::Green;
                    cout << "O grafo e simples"<< endl;
                }
                else
                { 
                    cout << TerminalColors::Red;
                    cout << "O grafo nao e simples"<< endl; 
                } 
            }
            cout << TerminalColors::White;
            cout<< endl;
        }

        void identificaCompleto()
        {
                bool validacao = false;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.identificaCompleto(NumVertices,TipoGrafo);
                if(Print)
                    GfMt.printaMatriz(NumVertices);
                cout<< TerminalColors::Red;
                cout<< "( Matriz )";
                if(validacao)
                {
                    cout << TerminalColors::Green;
                    cout << "O grafo e completo"<< endl;
                }
                else
                { 
                    cout << TerminalColors::Red;
                    cout << "O grafo nao e completo"<< endl; 
                } 
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.identificaCompleto(NumVertices,TipoGrafo);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);
                cout<< TerminalColors::Red;
                cout<< "( Lista )";
                if(validacao)
                {
                    cout << TerminalColors::Green;
                    cout << "O grafo e completo"<< endl;
                }
                else
                { 
                    cout << TerminalColors::Red;
                    cout << "O grafo nao e completo"<< endl; 
                } 
            }
            cout << TerminalColors::White;
            cout<< endl;
        }

        void adicionaVertice(int numAdicionar)
        {
            string adicionado = "";
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                GfMt.adicionaVertice(NumVertices,numAdicionar);
                if(Print)
                    GfMt.printaMatriz(NumVertices+numAdicionar);
                adicionado += "Matriz";
                if(TipoDeEstrutura == 2)
                    adicionado += " e ";
                cout<<endl;
            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                GfLs.adicionaVertice(NumVertices,numAdicionar);
                if(Print)
                    GfLs.printaLista(NumVertices+numAdicionar,Ponderado);
                adicionado += "Lista";
            }
            NumVertices+=numAdicionar;
            cout << TerminalColors::Green;
            cout << "Adicionado "<< numAdicionar << " vertice";
            if(numAdicionar > 1)
                cout << "s";
            cout << " em "<< TerminalColors::Red << adicionado <<endl;    
        }

        void verificaRegular()
        {
            bool validacao = false;
            if(TipoDeEstrutura == 0 || TipoDeEstrutura == 2)
            {
                validacao = GfMt.verificaRegular(NumVertices, TipoGrafo);
                if(Print)
                    GfMt.printaMatriz(NumVertices);

            }
            if(TipoDeEstrutura == 1 || TipoDeEstrutura == 2)
            {
                validacao = GfLs.verificaRegular(NumVertices, TipoGrafo);
                if(Print)
                    GfLs.printaLista(NumVertices,Ponderado);

            }  

           if(validacao)
            {
                cout << TerminalColors::Green;
                cout << "O grafo e regular"<< endl;
            }
            else
            { 
                cout << TerminalColors::Red;
                cout << "O grafo nao e regular"<< endl; 
            } 
        }
};
