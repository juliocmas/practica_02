#include <iostream>

const int filas = 15;
const int columnas = 20;

using namespace std; // Agregamos esta línea

void InicializarSala(char sala[filas][columnas]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            sala[i][j] = '0'; // Todos los asientos disponibles
        }
    }
}

void MostrarSala(const char sala[filas][columnas]) {
    cout << "Estado de la sala de cine:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << sala[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char sala[filas][columnas];
    InicializarSala(sala);

    while (true) {
        MostrarSala(sala);

        char fila;
        int numeroAsiento;

        cout << "Ingrese la fila (A-O) y el número de asiento (1-20) o 'Q' para salir: ";
        cin >> fila;
        
        if (fila == 'Q' || fila == 'q') {
            break; // Salir del programa si el usuario ingresa 'Q' o 'q'
        }

        cin >> numeroAsiento;

        // Verificar la entrada del usuario
        if (fila >= 'A' && fila <= 'O' && numeroAsiento >= 1 && numeroAsiento <= 20) {
            int filaIndex = fila - 'A';
            int asientoIndex = numeroAsiento - 1;

            if (sala[filaIndex][asientoIndex] == '0') {
                sala[filaIndex][asientoIndex] = 'X'; // Marcar el asiento como ocupado
                cout << "Reserva exitosa para el asiento F" << fila << "C" << numeroAsiento << endl;
            } else {
                cout << "El asiento F" << fila << "C" << numeroAsiento << " ya está ocupado." << endl;
            }
        } else {
            cout << "Entrada inválida. Asegúrese de ingresar una fila válida (A-O) y un número de asiento válido (1-20)." << endl;
        }
    }

    return 0;
}
