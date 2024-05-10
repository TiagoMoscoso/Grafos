#include <list>
#include "..\Grafos\ListClass.cpp"
int frequencyInTheList(int value, int tamanho, list<ListClass>** ListArray)
{
    int freq = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (auto it = ListArray[i]->begin(); it != ListArray[i]->end(); ++it) 
        {
            if(it->vertice==value)
              freq++;  
        }
    }
    return freq;
}