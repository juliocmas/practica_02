#include <iostream>

using namespace std;

// Función para calcular el factorial de un número
unsigned long long Factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Función para encontrar la enésima permutación lexicográfica de números del 0 al 9
string EnesimaPermutacion(int n) {
   string resultado;
    int numerosDisponibles[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    n--; // Ajustamos n para que comience desde 0

    for (int i = 9; i >= 0; --i) {
        unsigned long long factorial = Factorial(i);
        int indice = n / factorial;
        resultado += to_string(numerosDisponibles[indice]);

        // Eliminamos el elemento seleccionado
        for (int j = indice; j < 9; ++j) {
            numerosDisponibles[j] = numerosDisponibles[j + 1];
        }

        n %= factorial;
    }

    return resultado;
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    if (n < 1 || n > Factorial(10)) {
        cout << "El valor de n debe estar entre 1 y " << Factorial(10) <<endl;
    } else {
        string permutacion = EnesimaPermutacion(n);
        cout << "La permutación número " << n << " es: " << permutacion <<endl;
    }

    return 0;
}


