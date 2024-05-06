int sumLine(int tamanho, int linha,int ** matriz)
{
    int sum = 0;
    for(int i = 0; i < tamanho; i++)
    {
        sum += matriz[linha][i];
    }

    return sum;
}