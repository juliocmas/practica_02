#include <iostream>
using namespace std;

int main() {
    // Solicitar al usuario que ingrese la cadena de caracteres numéricos
    cout << "Ingrese una cadena de caracteres numéricos: ";
    
    char caracter;
    int numero = 0;

    // Leer y procesar cada carácter hasta que se ingrese Enter
    while (true) {
        caracter = cin.get(); // Leer un carácter
        
        // Verificar si el carácter es Enter (final de línea)
        if (caracter == '\n') {
            break; // Salir del bucle si se presionó Enter
        }
        
        // Verificar si el carácter es un dígito numérico
        if (caracter >= '0' && caracter <= '9') {
            numero = numero * 10 + (caracter - '0');
        } else {
            cout << "La cadena contiene caracteres no numéricos." << endl;
            return 1; // Salir del programa con un código de error
        }
    }

    // Imprimir el número entero resultante
    cout << "Número entero resultante: " << numero << endl;

    return 0;
}