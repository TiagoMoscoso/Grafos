int * mergeGrafos(int numVertices, int * grafos, int * adicionaAoGrafo)
{
    for(int i = 0; i < numVertices; i++)
    {
        if(adicionaAoGrafo[i] >= 1) grafos[i] = 1;
    }

    return grafos;
}