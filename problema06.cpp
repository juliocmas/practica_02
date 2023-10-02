#include <iostream>
using namespace std;

int main() {
    const int longitudMaxima = 100; // Longitud máxima de la cadena
    char cadena[longitudMaxima];

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, longitudMaxima);

    char cadenaEnMayusculas[longitudMaxima]; // Para almacenar la cadena en mayúsculas

    // Convertir a mayúsculas sin usar <cctype>
    for (int i = 0; cadena[i] != '\0'; ++i) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            // Si es una letra minúscula ('a' a 'z'), convertir a mayúscula
            cadenaEnMayusculas[i] = cadena[i] - 'a' + 'A';
        } else {
            // Mantener otros caracteres sin cambios
            cadenaEnMayusculas[i] = cadena[i];
        }
    }
    cadenaEnMayusculas[longitudMaxima - 1] = '\0'; // Asegurarse de que la cadena en mayúsculas esté terminada

    cout << "Original: " << cadena << endl;
    cout << "En mayúscula: " << cadenaEnMayusculas << endl;

    return 0;
}
