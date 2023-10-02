//Rectángulo A (x1 y1 ancho altura): 0 0 8 4
//Rectángulo B (x1 y1 ancho altura): 5 2 6 7


#include <iostream>

using namespace std;

// Estructura para representar un rectángulo
struct Rectangulo {
    int x1, y1; // Coordenadas de la esquina superior izquierda
    int ancho, altura;
};

// Función para calcular la intersección entre dos rectángulos
Rectangulo CalcularInterseccion(const Rectangulo& A, const Rectangulo& B) {
    Rectangulo C;

    // Encontrar las coordenadas de la esquina superior izquierda de C
    C.x1 = std::max(A.x1, B.x1);
    C.y1 = std::max(A.y1, B.y1);

    // Encontrar las coordenadas de la esquina inferior derecha de C
    int x2A = A.x1 + A.ancho;
    int x2B = B.x1 + B.ancho;
    int y2A = A.y1 + A.altura;
    int y2B = B.y1 + B.altura;
    C.ancho = std::min(x2A, x2B) - C.x1;
    C.altura = std::min(y2A, y2B) - C.y1;

    // Verificar si hay intersección (si ancho o altura es negativo, no hay intersección)
    if (C.ancho < 0 || C.altura < 0) {
        C.ancho = 0;
        C.altura = 0;
    }

    return C;
}

int main() {
    Rectangulo A, B, C;

    // Solicitar los datos de los rectángulos A y B
    cout << "Ingrese los datos del Rectángulo A (x1 y1 ancho altura): ";
    cin >> A.x1 >> A.y1 >> A.ancho >> A.altura;

    cout << "Ingrese los datos del Rectángulo B (x1 y1 ancho altura): ";
    cin >> B.x1 >> B.y1 >> B.ancho >> B.altura;

    // Calcular la intersección entre A y B
    C = CalcularInterseccion(A, B);

    // Verificar si hay intersección
    if (C.ancho == 0 && C.altura == 0) {
        cout << "No se forma intersección." << std::endl;
    } else {
        // Imprimir el rectángulo de intersección C
        cout << "Rectángulo de intersección C: { " << C.x1 << ", " << C.y1 << ", " << C.ancho << ", " << C.altura << " }" << std::endl;
    }

    return 0;
}
