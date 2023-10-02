#include <iostream>
using namespace std;

// Función para calcular la longitud de un número entero
int longitudEntero(int numero) {
    int longitud = 0;
    if (numero == 0) {
        return 1; // El número 0 tiene una longitud de 1
    }
    while (numero != 0) {
        numero /= 10;
        longitud++;
    }
    return longitud;
}

// Función para convertir un número entero a una cadena de caracteres
void enteroACadena(int numero, char cadena[], int longitud) {
    cadena[longitud] = '\0'; // Establecer el carácter nulo al final de la cadena

    // Verificar si el número es negativo
    bool esNegativo = false;
    if (numero < 0) {
        esNegativo = true;
        numero = -numero; // Hacer el número positivo
    }

    // Construir la cadena de caracteres desde el final
    for (int i = longitud - 1; i >= 0; i--) {
        cadena[i] = '0' + (numero % 10); // Convertir el dígito en carácter
        numero /= 10;
    }

    // Agregar el signo '-' si el número era negativo
    if (esNegativo) {
        cadena[0] = '-';
    }
}

int main() {
    // Solicitar al usuario que ingrese un número entero
    cout << "Ingrese un número entero: ";
    int numero;
    cin >> numero;

    // Calcular la longitud del número entero
    int longitud = longitudEntero(numero);

    // Crear un arreglo de caracteres con la longitud adecuada
    char cadena[longitud + 1]; // +1 para el carácter nulo

    // Convertir el número entero a una cadena de caracteres
    enteroACadena(numero, cadena, longitud);

    // Imprimir la cadena resultante
    cout << "Cadena resultante: " << cadena << endl;

    return 0;
}
