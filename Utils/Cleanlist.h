#include "..\Grafos\ListClass.cpp"
list<ListClass>** cleanItemList(int value, int tamanho, list<ListClass>** ListArray)
{

    for (auto it = ListArray[value]->end(); it != ListArray[value]->begin(); --it) 
    {
        if(it->vertice != ListArray[value]->end()->vertice)
            ListArray[value]->erase(it++);
    }
    
    return ListArray;
}