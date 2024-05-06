#include <iostream>
#include <list>
using namespace std;


list<int>** copyList(list<int>** original, int tamanho) {
    list<int>** copia = (list<int> **)malloc(tamanho * sizeof(int *));

    for (int i = 0; i < tamanho; i++)
    {
        copia[i] = new list<int>;

        for(auto it = original[i]->begin(); it != original[i]->end(); it++)
        {
           copia[i]->push_back(*it);
        }
    }

    return copia;
}