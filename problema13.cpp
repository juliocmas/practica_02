#include <iostream>

using namespace std;

// Función para contar estrellas en la matriz
int ContarEstrellas(int** matriz, int filas, int columnas) {
    int contadorEstrellas = 0;

    for (int i = 1; i < filas - 1; ++i) {
        for (int j = 1; j < columnas - 1; ++j) {
            int sumaVecinos = matriz[i][j] + matriz[i][j - 1] + matriz[i][j + 1] + matriz[i - 1][j] + matriz[i + 1][j];
            if (sumaVecinos / 5 > 6) {
                contadorEstrellas++;
            }
        }
    }

    return contadorEstrellas;
}

int main() {
    // Definir las dimensiones de la matriz
    const int filas = 6;
    const int columnas = 8;

    // Crear una matriz dinámica de números enteros (simulando la imagen)
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }

    // Inicializar la matriz con los valores dados
    int valores[filas][columnas] = {
        {0, 3, 4, 0, 0, 0, 6, 8},
        {5, 13, 6, 0, 0, 0, 2, 3},
        {2, 6, 2, 7, 3, 0, 10, 0},
        {0, 0, 4, 15, 4, 1, 6, 0},
        {0, 0, 7, 12, 6, 9, 10, 4},
        {5, 0, 6, 10, 6, 4, 8, 0}
    };

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = valores[i][j];
        }
    }

    // Contar estrellas en la matriz
    int estrellas = ContarEstrellas(matriz, filas, columnas);

    cout << "Número de estrellas encontradas en la imagen: " << estrellas << std::endl;

    // Liberar la memoria de la matriz
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

