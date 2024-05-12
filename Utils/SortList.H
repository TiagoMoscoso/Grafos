#ifndef SortList_h
#define SortList_h

#include <algorithm> 
#include "..\Grafos\ListClass.cpp"
#include <list>

using namespace std;

class ExtendedListClass : public ListClass 
{
public:
    int pai;
    ExtendedListClass(int vertice, int peso, int extra) : ListClass(vertice, peso), pai(extra) {}
};

bool contains(ListClass objList, list<ExtendedListClass> list, bool tipoGrafo)
{
    if(!tipoGrafo)
    {
        for(auto it = list.begin(); it != list.end(); it++)
        {
            if((objList.peso == it->peso) && (objList.vertice == it->vertice))
                return true;
        }
    }
    return false;
}

bool compareByValue(const ExtendedListClass& a, const ExtendedListClass& b) 
{
    return a.peso < b.peso;
}

list<ExtendedListClass> sortList(list<ListClass>** original, int tamanho, bool tipoGrafo) 
{
    list<ExtendedListClass> copia;
    
    for (int i = 0; i < tamanho; i++)
    {
        for(auto it = original[i]->begin(); it != original[i]->end(); it++)
        {
            if(!contains(ListClass(i, it->peso),copia,tipoGrafo) && it != original[i]->begin())
                copia.push_back(ExtendedListClass(it->vertice, it->peso, i));
        }
    }

    copia.sort(compareByValue);

    return copia;
}
#endif