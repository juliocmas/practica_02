#include <iostream>

using namespace std;

// Función para calcular la combinación de billetes y monedas
void calcularCombinacion(long cantidad) {
    // Definir los valores de los billetes y monedas disponibles
    long billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    long monedas[] = {500, 200, 100, 50};

    // Inicializar variables para contar la cantidad de cada billete o moneda
    int billete50k = 0, billete20k = 0, billete10k = 0, billete5k = 0, billete2k = 0, billete1k = 0;
    int moneda500 = 0, moneda200 = 0, moneda100 = 0, moneda50 = 0;

    // Calcular la cantidad de cada billete o moneda
    for (int i = 0; i < 6; i++) {
        while (cantidad >= billetes[i]) {
            cantidad -= billetes[i];
            switch (billetes[i]) {
                case 50000: billete50k++; break;
                case 20000: billete20k++; break;
                case 10000: billete10k++; break;
                case 5000: billete5k++; break;
                case 2000: billete2k++; break;
                case 1000: billete1k++; break;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        while (cantidad >= monedas[i]) {
            cantidad -= monedas[i];
            switch (monedas[i]) {
                case 500: moneda500++; break;
                case 200: moneda200++; break;
                case 100: moneda100++; break;
                case 50: moneda50++; break;
            }
        }
    }

    // Imprimir el desglose de billetes y monedas
    cout << "Desglose de billetes y monedas:" << std::endl;
    cout << "50000 : " << billete50k <<endl;
    cout << "20000 : " << billete20k <<endl;
    cout << "10000 : " << billete10k <<endl;
    cout << "5000 : " << billete5k <<endl;
    cout << "2000 : " << billete2k <<endl;
    cout << "1000 : " << billete1k <<endl;
    cout << "500 : " << moneda500 <<endl;
    cout << "200 : " << moneda200 <<endl;
    cout << "100 : " << moneda100 <<endl;
    cout << "50 : " << moneda50 <<endl;

    // Calcular y mostrar el faltante
    cout << "Faltante: " << cantidad << std::endl;
}

int main() {
    long cantidad;

    // Solicitar la cantidad de dinero al usuario
    cout << "Ingrese la cantidad de dinero: ";
    cin >> cantidad;

    // Llamar a la función para calcular la combinación de billetes y monedas
    calcularCombinacion(cantidad);

    return 0;
}
