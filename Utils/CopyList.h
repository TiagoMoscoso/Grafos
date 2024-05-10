#include <iostream>
#include <list>
#include "..\Grafos\ListClass.cpp"
using namespace std;


list<ListClass>** copyList(list<ListClass>** original, int tamanho) {
    list<ListClass>** copia = (list<ListClass> **)malloc(tamanho * sizeof(ListClass *));

    for (int i = 0; i < tamanho; i++)
    {
        copia[i] = new list<ListClass>;

        for(auto it = original[i]->begin(); it != original[i]->end(); it++)
        {
           copia[i]->push_back(*it);
        }
    }

    return copia;
}