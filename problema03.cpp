#include <iostream>
using namespace std;

bool sonCadenasIguales(const char* cadena1, const char* cadena2) {
    while (*cadena1 != '\0' && *cadena2 != '\0') {
        if (*cadena1 != *cadena2) {
            return false; // Si los caracteres son diferentes, las cadenas no son iguales
        }
        cadena1++;
        cadena2++;
    }
    return (*cadena1 == '\0' && *cadena2 == '\0'); // Verificar si ambas cadenas llegaron al final juntas
}

int main() {
    const int longitudCadena = 10;
    char cadena1[longitudCadena + 1]; // +1 para el carácter nulo
    char cadena2[longitudCadena + 1];

    // Solicitar al usuario que ingrese la primera cadena
    cout << "Ingrese la primera cadena de 10 caracteres: ";
    cin.getline(cadena1, longitudCadena + 1);

    // Solicitar al usuario que ingrese la segunda cadena
    cout << "Ingrese la segunda cadena de 10 caracteres: ";
    cin.getline(cadena2, longitudCadena + 1);

    // Imprimir las cadenas ingresadas
    cout << "Cadena 1: " << cadena1 << endl;
    cout << "Cadena 2: " << cadena2 << endl;

    // Comparar las cadenas utilizando la función personalizada
    if (sonCadenasIguales(cadena1, cadena2)) {
        cout << "Las cadenas son iguales." << endl;
    } else {
        cout << "Las cadenas no son iguales." << endl;
    }

    return 0;
}
