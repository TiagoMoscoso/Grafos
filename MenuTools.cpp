#include <algorithm>
#include <iomanip>
#include "Utils/TerminalColors.h"
#include "Grafos/GrafTools.cpp"
#include "Utils/GetPoints.h"
#include <string>


class Menu
{   private:
        GrafTools Gt;

    public:

        void setPrint()
        {
            cout << TerminalColors::Green;
            cout << "Voce deseja printar o grafo apos a execucao de uma acao?" << endl;

            string auxiliarNumVet = "";
            while(auxiliarNumVet == "")
            {

                cout << TerminalColors::White;
                cin>> auxiliarNumVet;
                    
                transform(auxiliarNumVet.begin(), auxiliarNumVet.end(), auxiliarNumVet.begin(), ::tolower);

                if(auxiliarNumVet == "sim" || auxiliarNumVet == "1")
                {
                    Gt.setPrint();
                    cout << TerminalColors::Green;
                    cout << "Print ativado" << endl;
                }
                else if(auxiliarNumVet == "nao" || auxiliarNumVet == "0")
                {
                    cout << TerminalColors::Green;
                    cout << "Print desativado" << endl;
                }
                else
                {
                    cout << TerminalColors::Red;
                    cout << "Resultado invalido" << endl;
                    cout << TerminalColors::Yellow;
                    cout << setw(20) << "Printar:" << setw(10) << "(sim) ou (1)" << endl;
                    cout << setw(20) << "Nao Printar:" << setw(10) << "(nao) ou (0)" << endl;
                    auxiliarNumVet = "";
                }
            }
            cout << TerminalColors::White;
            cout << endl;
        }
        void setNumVertices()
        {
            cout << TerminalColors::Green;
            cout << "Deseja criar um grafo de quantos vertices?" << endl;

            while(Gt.NumVertices <= 0)
            {
                try
                {
                    string auxiliarNumVet;

                    cout << TerminalColors::White;
                    cin>> auxiliarNumVet;

                    Gt.NumVertices = stoi(auxiliarNumVet);

                    if(Gt.NumVertices <= 0)
                    {
                        cout << TerminalColors::Red;
                        cout << "O numero deve ser maior que 0" << endl;
                    }
                }
                catch(exception ex)
                {
                    cout << TerminalColors::Red;
                    cout << "Deve inserir apenas numeros inteiros!!!" << endl;
                }
            }
            cout << TerminalColors::White;
            cout << endl;
        }

        void setTipoEstrutura()
        {
            cout << TerminalColors::Green;
            cout << "Deseja usar matriz, lista ou os dois para representar seu grafo?" << endl;

            while(Gt.TipoDeEstrutura <= -1)
            {
                string auxiliarTipoEstru = "";

                cout << TerminalColors::White;
                cin>> auxiliarTipoEstru;

                transform(auxiliarTipoEstru.begin(), auxiliarTipoEstru.end(), auxiliarTipoEstru.begin(), ::tolower);

                if(auxiliarTipoEstru == "matriz" || auxiliarTipoEstru == "mat" || auxiliarTipoEstru == "0")
                {
                    Gt.TipoDeEstrutura = 0;
                    cout << TerminalColors::Green;
                    cout << "Estrutura de grafo definida como matriz." << endl;
                }
                else if(auxiliarTipoEstru == "lista" || auxiliarTipoEstru == "list" || auxiliarTipoEstru == "1")
                {
                    Gt.TipoDeEstrutura = 1;
                    cout << TerminalColors::Green;
                    cout << "Estrutura de grafo definida como lista." << endl;
                }
                else if(auxiliarTipoEstru == "os dois" || auxiliarTipoEstru == "dois" || auxiliarTipoEstru == "2")
                {
                    Gt.TipoDeEstrutura = 2;
                    cout << TerminalColors::Green;
                    cout << "Estrutura de grafo definida como matriz e lista." << endl;
                }
                else
                {
                    cout << TerminalColors::Red;
                    cout << "Tipo invalido" << endl;
                    cout << "Use os seguintes tipos:" << endl;
                    cout << TerminalColors::Yellow;
                    cout << setw(20) << "Matriz:" << setw(10) << "(matriz) ou (0)" << endl;
                    cout << setw(20) << "Lista:" << setw(10) << "(lista) ou (1)" << endl;
                    cout << setw(20) << "Os dois:" << setw(10) << "(os dois) ou (2)" << endl;

                }
            }
            cout << TerminalColors::White;
            cout << endl;
        }

        void setTipoGrafo()
        {
            cout << TerminalColors::Green;
            cout << "Qual sera o tipo de grafo?" << endl;
            cout << "Nao Direcionado ou Direcionado" << endl;
            while(true)
            {
                string auxiliartipoGrafo = "";

                cout << TerminalColors::White;
                cin>> auxiliartipoGrafo;

                transform(auxiliartipoGrafo.begin(), auxiliartipoGrafo.end(), auxiliartipoGrafo.begin(), ::tolower);

                if(auxiliartipoGrafo == "nao direcionado" || auxiliartipoGrafo == "nao" || auxiliartipoGrafo == "0")
                {
                    Gt.TipoGrafo = false;//nao direcionado
                    cout << TerminalColors::Green;
                    cout << "Grafo definido como nao direcionado." << endl;
                    break;
                }
                else if(auxiliartipoGrafo == "direcionado" || auxiliartipoGrafo == "direc" || auxiliartipoGrafo == "1")
                {
                    Gt.TipoGrafo = true;//direcionado
                    cout << TerminalColors::Green;
                    cout << "Grafo definido como direcionado." << endl;
                    break;
                }
                else
                {
                    cout << TerminalColors::Red;
                    cout << "Tipo invalido" << endl;
                    cout << "Use os seguintes tipos:" << endl;
                    cout << TerminalColors::Yellow;
                    cout << setw(20) << "Nao Direcionado:" << setw(10) << "(nao direcionado) ou (0)" << endl;
                    cout << setw(20) << "Direcionado:" << setw(10) << "(direcionado) ou (1)" << endl;

                }
            }
            cout << TerminalColors::White;
            cout << endl;
        }

        void generateGrafo()
        {
            Gt.generateGrafo();
        }

        void indentificaVizinhanca()
        {
            cout << TerminalColors::Green;
            cout << "Entre com os pontos para buscar vizinhanca:" << endl;
            cout << TerminalColors::White;
            vector<int> pontos =  points::getPontos(Gt.NumVertices);
            Gt.identificacaoDeVizinhanca(pontos[0], pontos[1]);
        }

        void indentificacaoSucecao()
        {
            cout << TerminalColors::Green;
            cout << "Entre com os pontos para buscar sucecao:" << endl;
            cout << TerminalColors::White;
            vector<int> pontos =  points::getPontos(Gt.NumVertices);
            Gt.indentificacaoSucecao(pontos[0], pontos[1]);
        }

        void indentificacaoPredececao()
        {
            cout << TerminalColors::Green;
            cout << "Entre com os pontos para buscar predececao:" << endl;
            cout << TerminalColors::White;
            vector<int> pontos =  points::getPontos(Gt.NumVertices);
            Gt.indentificacaoPredececao(pontos[0], pontos[1]);
        }
        void identificaSucPre()
        {
            cout << TerminalColors::Green;
            cout << "Escolha a opcao dentre as seguintes:" << endl;
            cout << TerminalColors::Yellow;
            cout << setw(20) << "Identificar predececao:" << setw(10) << "(0)" << endl;
            cout << setw(20) << "Identificar sucecao:" << setw(10) << "(1)" << endl;

            int selecao = -1;

            while(selecao == -1)
            {
                string entrada;
                cin >> entrada;

                if(entrada == "0" || entrada == "1")
                {
                    selecao = stoi(entrada);
                }
                else
                {
                    cout << TerminalColors::Red;
                    cout << "Entrada invalida" << endl;
                    cout << endl;
                }
            }

            switch (selecao)
            {
            case 0:
                indentificacaoPredececao();
                break;
            case 1:
                indentificacaoSucecao();
                break;
            }
        }

        void printaEmulatorMenu()
        {
            cout << TerminalColors::Green;
            cout << "Escolha a opcao dentre as seguintes:" << endl;
            cout << TerminalColors::Yellow;
            cout << setw(20) << "Criar arresta:" << setw(10) << "(0)" << endl;
            cout << setw(20) << "Remover arresta:" << setw(10) << "(1)" << endl;
            if(!Gt.TipoGrafo)
            {
                cout << setw(20) << "Identificar vizinhança:" << setw(10) << "(2)" << endl;
            }
            else
            {
                cout << setw(20) << "Identificar Sucecao ou Predececao:" << setw(10) << "(2)" << endl;
            }
            cout << setw(20) << "Indetifica grau de um vertice:" << setw(10) << "(3)" << endl;
            cout << setw(20) << "Indetifica se o grafo e simples:" << setw(10) << "(4)" << endl;
            cout << setw(20) << "Indetifica se o grafo e completo:" << setw(10) << "(5)" << endl;
            cout << setw(20) << "Gerar grafo aleatorio:" << setw(10) << "(7)" << endl;
            cout << TerminalColors::Red;
            cout << "Para sair clique (Q)" << endl;
            cout << TerminalColors::White;
            cout << endl;
        }

        void adicionaArresta()
        {
            cout << TerminalColors::Green;
            cout << "Entre com os pontos para adicionar uma arresta:" << endl;
            cout << TerminalColors::White;
            vector<int> pontos =  points::getPontos(Gt.NumVertices);
            Gt.adicionaArresta(pontos[0], pontos[1]);
        }

        void identificaGrauDoVertice()
        {
            cout << TerminalColors::Green;
            cout << "Entre com os pontos para adicionar uma arresta:" << endl;
            cout << TerminalColors::White;
            int ponto =  points::getPonto(Gt.NumVertices);
            Gt.indentificacaoGrau(ponto);
        }

        void removeArresta()
        {
            cout << TerminalColors::Green;
            cout << "Entre com os pontos para remover uma arresta:" << endl;
            cout << TerminalColors::White;
            vector<int> pontos =  points::getPontos(Gt.NumVertices);
            Gt.removeArresta(pontos[0], pontos[1]);   
        }

        void criaGrafoAleatorio()
        {
            int numArrestas = -1;
            cout << TerminalColors::Green;
            cout << "Entre com o numero de arrestas para gerar o grafo aleatorio:" << endl;
            cout << TerminalColors::White;
            while(numArrestas < 0)
            {
                try
                {
                    string auxiliarNumVet;

                    cout << TerminalColors::White;
                    cin>> auxiliarNumVet;

                    numArrestas = stoi(auxiliarNumVet);

                    if(numArrestas <= 0)
                    {
                        cout << TerminalColors::Red;
                        cout << "O numero deve ser maior ou igual a 0" << endl;
                    }
                }
                catch(exception ex)
                {
                    cout << TerminalColors::Red;
                    cout << "Deve inserir apenas numeros inteiros!!!" << endl;
                }
            }
            Gt.criaGrafoAleatorio(numArrestas);
        }
        void startEmulator()
        {
            string entrada = "";
            cout << "" << endl;

            while(entrada != "q")
            {
                printaEmulatorMenu();
                cin >> entrada;
                transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
                if(entrada != "q")
                {
                    try
                    {
                        int opcaoMenu = stoi(entrada);

                        switch(opcaoMenu)
                        {
                            case 0:
                                adicionaArresta();
                            break;
                            case 1:
                                removeArresta();
                            break;
                            case 2:
                                if(!Gt.TipoGrafo)
                                {
                                    indentificaVizinhanca();
                                }
                                else
                                {
                                    identificaSucPre();
                                }
                            break;
                            case 3:
                                identificaGrauDoVertice();
                            break;
                            case 4:
                                Gt.indentificaSimples();
                            break;
                            case 5:
                                Gt.identificaCompleto();
                            break;
                            case 7:
                                criaGrafoAleatorio();
                            break;
                            default:
                            throw exception();
                            break;
                        }
                    }
                    catch(exception ex)
                    {
                    cout << TerminalColors::Red;
                    cout << "Tipo invalido" << endl;
                    cout << endl;
                    }
                }
            }
            cout << endl;
            cout << TerminalColors::White;
        }
};