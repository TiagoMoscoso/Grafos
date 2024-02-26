#include <vector>
#include "TerminalColors.h"

using namespace std;

class points
{
    public:
    static vector<int> getPontos(int numVertices)
    {
        vector<int> pontos = {-1,-1};
        while(pontos[0] == -1 || pontos[1] == -1)
        {
            if(pontos[0] == -1)
            {
                try
                {
                    cout << TerminalColors::Green;
                    cout << "Entre com o ponto A" << endl;
                    cout << TerminalColors::White;
                    string auxEntrada;
                    cin >> auxEntrada;
                    pontos[0] = stoi(auxEntrada);

                    if(pontos[0] < 0 || pontos[0] >= numVertices)
                    {
                        pontos[0]  = -1;
                        throw exception();
                    }
                }
                catch(exception ex)
                {
                    cout << TerminalColors::Red;
                    cout << "Ponto A invalido!!!" << endl;
                    cout << TerminalColors::White;
                }
            }
            if(pontos[1] == -1)
            {
                try
                {
                    cout << TerminalColors::Green;
                    cout << "Entre com o ponto B" << endl;
                    cout << TerminalColors::White;

                    string auxEntrada;
                    cin >> auxEntrada;
                    pontos[1] = stoi(auxEntrada);
                    if(pontos[1] < 0 || pontos[1] >= numVertices)
                    {
                        pontos[1] = -1;
                        throw exception();
                    }
                }
                catch(exception ex)
                {
                    cout << TerminalColors::Red;
                    cout << "Ponto B invalido!!!" << endl;
                    cout << TerminalColors::White; 
                }
                    
            }
        }
        return pontos;
    }

    static int getPonto(int numVertices)
    {
        int pontos = -1;
        while(pontos == -1)
        {
            try
            {
                cout << TerminalColors::Green;
                cout << "Entre com o ponto A" << endl;
                cout << TerminalColors::White;
                string auxEntrada;
                cin >> auxEntrada;
                pontos = stoi(auxEntrada);
                if(pontos< 0 || pontos >= numVertices)
                {
                    pontos  = -1;
                    throw exception();
                }
            }                
            catch(exception ex)
            {
                    cout << TerminalColors::Red;
                    cout << "Ponto A invalido!!!" << endl;
                    cout << TerminalColors::White;
            }
           
        }
        return pontos;
    }
};