#include <algorithm> 
#include "..\Grafos\ListClass.cpp"
#include <list>
#include "SortList.H"
using namespace std;

list<ExtendedListClass> sortedListByArray(int ** original, int tamanho, bool tipoGrafo) 
{
    list<ExtendedListClass> copia;
    
    for (int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < tamanho; j++)
        {
            if(original[i][j]!= 0 && !contains(ListClass(i, original[i][j]),copia,tipoGrafo))
                copia.push_back(ExtendedListClass(j, original[i][j], i));
        }
    }

    copia.sort(compareByValue);
    return copia;
}