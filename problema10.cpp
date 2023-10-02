#include <iostream>
using namespace std;

int ConvertirRomanoAArabigo(const char* numeroRomano) {
    // Definir arreglos de caracteres para representar números romanos y sus valores correspondientes
    char simbolosRomanos[] = "MDCLXVI";
    int valoresRomanos[] = {1000, 500, 100, 50, 10, 5, 1};

    int resultado = 0;
    int valorAnterior = 0;

    int longitud = 0;

    // Calcular la longitud de la cadena manualmente
    while (numeroRomano[longitud] != '\0') {
        longitud++;
    }

    for (int i = longitud - 1; i >= 0; --i) {
        char caracter = numeroRomano[i];
        int valorActual = 0;

        // Buscar el valor del carácter romano en el arreglo de símbolos
        for (int j = 0; j < 7; ++j) {
            if (caracter == simbolosRomanos[j]) {
                valorActual = valoresRomanos[j];
                break;
            }
        }

        if (valorActual == 0) {
            // Carácter romano no válido
            cout << "Número romano no válido." << endl;
            return -1; // Valor de error
        }

        if (valorActual < valorAnterior) {
            resultado -= valorActual;
        } else {
            resultado += valorActual;
        }

        valorAnterior = valorActual;
    }

    return resultado;
}

int main() {
    const int longitudMaxima = 100; // Longitud máxima de la cadena
    char numeroRomano[longitudMaxima];

    cout << "Ingrese un número romano: ";
    cin >> numeroRomano;

    int numeroArabigo = ConvertirRomanoAArabigo(numeroRomano);

    if (numeroArabigo != -1) {
        cout << "El número ingresado fue: " << numeroRomano << " Que corresponde a: " << numeroArabigo << "." << endl;
    }

    return 0;
}
