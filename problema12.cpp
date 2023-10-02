#include <iostream>

using namespace std;

// Función para verificar si una matriz es un cuadrado mágico
bool EsCuadradoMagico(int* matrizUnidimensional, int dimension) {
    // Crear una matriz bidimensional a partir del arreglo unidimensional
    int** matriz = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        matriz[i] = new int[dimension];
        for (int j = 0; j < dimension; ++j) {
            matriz[i][j] = matrizUnidimensional[i * dimension + j];
        }
    }

    // Calcular la suma objetivo (la suma de la primera fila)
    int sumaObjetivo = 0;
    for (int j = 0; j < dimension; ++j) {
        sumaObjetivo += matriz[0][j];
    }

    // Verificar la suma de las filas y columnas
    for (int i = 0; i < dimension; ++i) {
        int sumaFila = 0;
        int sumaColumna = 0;
        for (int j = 0; j < dimension; ++j) {
            sumaFila += matriz[i][j];
            sumaColumna += matriz[j][i];
        }
        if (sumaFila != sumaObjetivo || sumaColumna != sumaObjetivo) {
            // Liberar la memoria de la matriz antes de retornar false
            for (int i = 0; i < dimension; ++i) {
                delete[] matriz[i];
            }
            delete[] matriz;
            return false;
        }
    }

    // Verificar la suma de las diagonales
    int sumaDiagonalPrincipal = 0;
    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < dimension; ++i) {
        sumaDiagonalPrincipal += matriz[i][i];
        sumaDiagonalSecundaria += matriz[i][dimension - 1 - i];
    }

    // Liberar la memoria de la matriz
    for (int i = 0; i < dimension; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return sumaDiagonalPrincipal == sumaObjetivo && sumaDiagonalSecundaria == sumaObjetivo;
}

int main() {
    int dimension;

    cout << "Ingrese la dimensión de la matriz cuadrada: ";
    cin >> dimension;

    // Verificar si la dimensión es válida
    if (dimension < 2) {
        cout << "La dimensión debe ser al menos 2." << endl;
        return 1;
    }

    // Crear un arreglo unidimensional para ingresar los valores
    int* arreglo = new int[dimension * dimension];

    // Ingresar los valores en el arreglo unidimensional
    cout << "Ingrese " << dimension * dimension << " números para la matriz cuadrada(ingrese numeros por filas de la matriz):" << endl;
    for (int i = 0; i < dimension * dimension; ++i) {
        cin >> arreglo[i];
    }

    // Verificar si es un cuadrado mágico y mostrar el resultado
    if (EsCuadradoMagico(arreglo, dimension)) {
        cout << "La matriz es un cuadrado mágico." << endl;
    } else {
        cout << "La matriz NO es un cuadrado mágico." << endl;
    }

    // Liberar la memoria del arreglo unidimensional
    delete[] arreglo;

    return 0;
}

    