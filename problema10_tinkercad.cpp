const int maxNumeroRomanoLength = 10;
char numeroRomano[maxNumeroRomanoLength + 1]; // +1 para el carácter nulo

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese un número romano:");
}

void loop() {
  if (Serial.available() > 0) {
    int length = Serial.readBytesUntil('\n', numeroRomano, maxNumeroRomanoLength);
    numeroRomano[length] = '\0'; // Agregar el carácter nulo al final

    int numeroArabigo = ConvertirRomanoAArabigo(numeroRomano);

    Serial.print("El número ingresado fue: ");
    Serial.print(numeroRomano);
    Serial.print(" Que corresponde a: ");
    Serial.println(numeroArabigo);

    Serial.println("Ingrese un número romano:");
  }
}

int ConvertirRomanoAArabigo(const char* numeroRomano) {
  // El código para convertir números romanos es el mismo que en la versión en C++
  // Solo asegúrate de que la función ConvertirRomanoAArabigo está definida antes de setup().
  // ...
}
