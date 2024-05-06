list<int>** cleanItemList(int value, int tamanho, list<int>** ListArray)
{

    for (auto it = ListArray[value]->end(); it != ListArray[value]->begin(); --it) 
    {
        if(it != ListArray[value]->end())
            ListArray[value]->erase(it++);
    }
    
    return ListArray;
}