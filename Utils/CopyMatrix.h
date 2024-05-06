int** copyMatrix(int** original, int tamanho) {
    int** copia = new int*[tamanho];

    for (int i = 0; i < tamanho; ++i) {
        copia[i] = new int[tamanho];

        for (int j = 0; j < tamanho; ++j) {
            copia[i][j] = original[i][j];
        }
    }

    return copia;
}