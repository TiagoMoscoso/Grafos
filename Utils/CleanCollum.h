int ** cleanCollum(int tamanho, int coluna,int ** matriz)
{
    for(int i = 0; i < tamanho; i++)
    {
        matriz[i][coluna] = 0;
    }

    return matriz;
}