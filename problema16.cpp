#include <iostream>
using namespace std;

// Función para calcular el número de caminos de Euler (Número Central de los Números Triangulares)
unsigned long long CalcularCaminosEuler(int n) {
    unsigned long long factorial2n = 1;
    unsigned long long factorialn = 1;

    // Calcula (2n)!
    for (int i = 1; i <= 2 * n; ++i) {
        factorial2n *= i;
    }

    // Calcula n!
    for (int i = 1; i <= n; ++i) {
        factorialn *= i;
    }

    // Calcula C(n)
    unsigned long long caminos = factorial2n / (factorialn * factorialn);
    return caminos;
}

int main() {
    int n;

    cout << "Ingrese el tamaño de la matriz cuadrada (n x n): ";
    cin >> n;

    if (n < 0) {
        cout << "El tamaño de la matriz debe ser un número positivo." << endl;
        return 1;
    }

    // Calcula el número de caminos de Euler
    unsigned long long caminos = CalcularCaminosEuler(n);

    cout << "Número de caminos posibles en una matriz " << n << "x" << n << ": " << caminos << endl;

    return 0;
}
