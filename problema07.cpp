#include <iostream>
using namespace std;

// Función para eliminar caracteres duplicados de una cadena
void eliminarDuplicados(char cadena[]) {
    int longitud = 0;

    // Calcular la longitud de la cadena manualmente
    while (cadena[longitud] != '\0') {
        longitud++;
    }

    if (longitud <= 1) {
        return; // La cadena tiene 0 o 1 caracteres, no hay duplicados que eliminar
    }

    int nuevaLongitud = 1; // Longitud de la cadena resultante
    for (int i = 1; i < longitud; ++i) {
        bool esRepetido = false;

        // Verificar si el carácter actual está duplicado
        for (int j = 0; j < nuevaLongitud; ++j) {
            if (cadena[i] == cadena[j]) {
                esRepetido = true;
                break;
            }
        }

        // Si no está duplicado, agregarlo a la cadena resultante
        if (!esRepetido) {
            cadena[nuevaLongitud] = cadena[i];
            nuevaLongitud++;
        }
    }

    // Terminar la cadena resultante
    cadena[nuevaLongitud] = '\0';
}

int main() {
    const int longitudMaxima = 100; // Longitud máxima de la cadena
    char cadena[longitudMaxima];

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, longitudMaxima);

    // Llamar a la función para eliminar caracteres duplicados
    eliminarDuplicados(cadena);

    cout << "Sin repetidos: " << cadena << endl;

    return 0;
}
