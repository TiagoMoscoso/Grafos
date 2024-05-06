int sumCollum(int tamanho, int coluna,int ** matriz)
{
    int sum = 0;
    for(int i = 0; i < tamanho; i++)
    {
        sum += matriz[i][coluna];
    }

    return sum;
}