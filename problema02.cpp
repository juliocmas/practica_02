#include <iostream>
#include <cstdlib> // Incluimos la biblioteca cstdlib
using namespace std;

int main() {
    // Semilla para generar números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    // Tamaño del nuevo arreglo (200 caracteres)
    const int tamano = 200;

    // Arreglo para almacenar las letras aleatorias
    char arreglo[tamano];

    // Genera y muestra el arreglo de letras aleatorias
    cout << "Arreglo de letras aleatorias:" << endl;
    for (int i = 0; i < tamano; ++i) {
        char letra = 'A' + (rand() % 26); // Genera una letra aleatoria de la A a la Z
        arreglo[i] = letra;
        cout << letra;
    }
    cout << endl;

    // Usar un arreglo para contar la frecuencia de cada letra en el arreglo
    int contador[26] = {0}; // Inicializa el contador a cero para cada letra

    for (int i = 0; i < tamano; ++i) {
        if (isalpha(arreglo[i])) {
            char letra = toupper(arreglo[i]) - 'A'; // Convierte la letra a mayúscula y ajusta el índice
            contador[letra]++;
        }
    }

    // Imprimir solo las letras que se repiten y cuántas veces se repiten
    cout << "Frecuencia de letras que se repiten:" << endl;
    for (int i = 0; i < 26; ++i) {
        char letra = 'A' + i;
        if (contador[i] > 1) {
            cout << letra << ": " << contador[i] << endl;
        }
    }

    return 0;
}
