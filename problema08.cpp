#include <iostream>
using namespace std;

bool esDigito(char caracter) {
    return (caracter >= '0' && caracter <= '9');
}

int main() {
    const int longitudMaxima = 100; // Longitud máxima de la cadena
    char cadena[longitudMaxima];

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, longitudMaxima);

    char texto[longitudMaxima]; // Para almacenar el texto
    char numeros[longitudMaxima]; // Para almacenar los números
    int indiceTexto = 0; // Índice para texto
    int indiceNumeros = 0; // Índice para números

    for (int i = 0; cadena[i] != '\0'; ++i) {
        if (esDigito(cadena[i])) {
            // Si es un dígito, agregarlo a la cadena de números
            numeros[indiceNumeros] = cadena[i];
            indiceNumeros++;
        } else {
            // Si no es un dígito, agregarlo a la cadena de texto
            texto[indiceTexto] = cadena[i];
            indiceTexto++;
        }
    }

    // Terminar las cadenas con '\0'
    texto[indiceTexto] = '\0';
    numeros[indiceNumeros] = '\0';

    cout << "Original: " << cadena << "." << endl;
    cout << "Texto: " << texto << ". ";
    if (indiceNumeros > 0) {
        cout << "Numero: " << numeros << ".";
    } else {
        cout << "No se encontraron números.";
    }
    cout << endl;

    return 0;
}
