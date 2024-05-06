#include <list>
list<int>** removeItemInList(int value, int tamanho, list<int>** ListArray)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (auto it = ListArray[i]->begin(); it != ListArray[i]->end(); ++it) 
        {
            if(*it==value && it != ListArray[i]->begin())
            {
                ListArray[i]->erase(it);
                break;
            }
        }
    }
    return ListArray;
}