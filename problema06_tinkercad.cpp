const int maxLongitudCadena = 100;
char cadena[maxLongitudCadena + 1]; // +1 para el carácter nulo

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese una cadena de caracteres:");
}

void loop() {
  if (Serial.available() > 0) {
    int longitud = Serial.readBytesUntil('\n', cadena, maxLongitudCadena);
    cadena[longitud] = '\0'; // Agregar el carácter nulo al final

    char cadenaEnMayusculas[maxLongitudCadena + 1]; // +1 para el carácter nulo

    // Convertir a mayúsculas sin usar <cctype>
    for (int i = 0; i < longitud; ++i) {
      char caracter = cadena[i];
      if (caracter >= 'a' && caracter <= 'z') {
        // Si es una letra minúscula ('a' a 'z'), convertir a mayúscula
        caracter = caracter - 'a' + 'A';
      }
      cadenaEnMayusculas[i] = caracter;
    }
    cadenaEnMayusculas[longitud] = '\0'; // Agregar el carácter nulo al final

    Serial.print("Original: ");
    Serial.println(cadena);
    Serial.print("En mayúscula: ");
    Serial.println(cadenaEnMayusculas);
    Serial.println("Ingrese una cadena de caracteres:");
  }
}
