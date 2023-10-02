#include <iostream>
using namespace std;

// Función para calcular la suma de los divisores de un número
int SumaDivisores(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

int main() {
    int limite;
    cout << "Ingrese un número límite: ";
    cin >> limite;

    int sumaAmigables = 0;

    for (int a = 2; a < limite; ++a) {
        int b = SumaDivisores(a);
        if (a != b && a == SumaDivisores(b) && b < limite) {
            sumaAmigables += a;
        }
    }

    cout << "El resultado de la suma es: " << sumaAmigables << endl;

    return 0;
}
