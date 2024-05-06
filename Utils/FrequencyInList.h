#include <list>
int frequencyInTheList(int value, int tamanho, list<int>** ListArray)
{
    int freq = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (auto it = ListArray[i]->begin(); it != ListArray[i]->end(); ++it) 
        {
            if(*it==value)
              freq++;  
        }
    }
    return freq;
}