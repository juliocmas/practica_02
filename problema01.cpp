//determinar la mínima combinación de billetes y monedas para una cantidad de dinero determinada.

String input;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  while (!Serial);    // Espera a que la comunicación serial esté lista
}

void loop() {
  // Espera a que se ingrese la cantidad de dinero a través del puerto serial
  Serial.println("Ingrese la cantidad de dinero:");
  while (!Serial.available()); // Espera hasta que se reciba algún dato

  // Lee la cantidad de dinero ingresada como una cadena
  input = Serial.readStringUntil('\n');
  
  // Limpia la cadena de caracteres no deseados
  input.trim();
  
  // Convierte la cadena a un valor numérico (entero largo)
  long cantidad = input.toInt();
  
  // Imprimir la cantidad de dinero ingresada
  Serial.print("Cantidad ingresada: "); 
  Serial.println(cantidad);

  // Verificar si la cantidad ingresada es negativa
  if (cantidad < 0) {
    Serial.println("¡Advertencia! La cantidad ingresada es negativa.");
  } else {
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
    Serial.println("Desglose de billetes y monedas:");
    Serial.print("50000 : "); Serial.println(billete50k);
    Serial.print("20000 : "); Serial.println(billete20k);
    Serial.print("10000 : "); Serial.println(billete10k);
    Serial.print("5000 : "); Serial.println(billete5k);
    Serial.print("2000 : "); Serial.println(billete2k);
    Serial.print("1000 : "); Serial.println(billete1k);
    Serial.print("500 : "); Serial.println(moneda500);
    Serial.print("200 : "); Serial.println(moneda200);
    Serial.print("100 : "); Serial.println(moneda100);
    Serial.print("50 : "); Serial.println(moneda50);

    // Calcular y mostrar el faltante
    Serial.print("Faltante: "); Serial.println(cantidad);
  }
}
