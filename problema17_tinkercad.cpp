int limite = 0; // Variable para almacenar el número límite

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Ingrese un número límite: ");
    
    while (!Serial.available()) {
        // Espera a que haya datos disponibles en el monitor serial
    }

    // Lee el número ingresado por el usuario
    limite = Serial.parseInt();

    int sumaAmigables = 0;

    for (int a = 2; a < limite; ++a) {
        int b = SumaDivisores(a);
        if (a != b && a == SumaDivisores(b) && b < limite) {
            sumaAmigables += a;
        }
    }

    // Envía el resultado al monitor serial
    Serial.print("El resultado de la suma es: ");
    Serial.println(sumaAmigables);

    delay(1000); // Espera 1 segundo antes de volver a solicitar el número límite
}

// Función para calcular la suma de los divisores de un número
int SumaDivisores(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}