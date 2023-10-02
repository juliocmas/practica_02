#include <iostream>

using namespace std;

const int tamano = 5;

// Función para llenar la matriz con números del 1 al 25
void LlenarMatriz(int matriz[][tamano]) {
    int numero = 1;
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            matriz[i][j] = numero++;
        }
    }
}

// Función para imprimir la matriz
void ImprimirMatriz(int matriz[][tamano]) {
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << std::endl;
    }
}

// Función para rotar la matriz 90 grados
void Rotar90Grados(int matriz[][tamano]) {
    int matrizRotada[tamano][tamano];

    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            matrizRotada[j][tamano - 1 - i] = matriz[i][j];
        }
    }

    // Copiar la matriz rotada de nuevo a la matriz original
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            matriz[i][j] = matrizRotada[i][j];
        }
    }
}

int main() {
    int matriz[tamano][tamano];

    // Llenar la matriz con números del 1 al 25
    LlenarMatriz(matriz);

    // Imprimir la matriz original
    cout << "Matriz Original:" << std::endl;
    ImprimirMatriz(matriz);

    // Rotar 90 grados y imprimir
    Rotar90Grados(matriz);
    cout << "\nMatriz Rotada 90 grados:" << std::endl;
    ImprimirMatriz(matriz);

    // Rotar 180 grados y imprimir
    Rotar90Grados(matriz);
    cout << "\nMatriz Rotada 180 grados:" << std::endl;
    ImprimirMatriz(matriz);

    // Rotar 270 grados y imprimir
    Rotar90Grados(matriz);
    cout << "\nMatriz Rotada 270 grados:" << std::endl;
    ImprimirMatriz(matriz);

    return 0;
}
