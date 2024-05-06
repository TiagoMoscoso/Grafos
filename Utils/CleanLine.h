int ** cleanLine(int tamanho, int linha,int ** matriz)
{
    for(int i = 0; i < tamanho; i++)
    {
        matriz[linha][i] = 0;
    }

    return matriz;
}