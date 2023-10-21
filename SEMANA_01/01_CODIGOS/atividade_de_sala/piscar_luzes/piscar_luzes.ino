const int pin25out = 25;
const int pin27out = 27;
const int pin26out = 26;

void setup() {
  pinMode(pin25out, OUTPUT);
  pinMode(pin27out, OUTPUT);
  pinMode(pin26out, OUTPUT);
  Serial.begin(115200);
  Serial.println("Iniciando a serial");
}

void loop() {
  // Envia 0V. para o pino 25
  digitalWrite(pin25out, LOW);
  Serial.println("Apagando");
  // Espera 1 segundo
  delay(100);

  // Envia 3.3V. para o pino 25
  digitalWrite(pin25out, HIGH);
  Serial.println("Acendendo");
  // Espera 1 segundo
  delay(100);

  // Envia 0V. para o pino 27
  digitalWrite(pin27out, LOW);
  Serial.println("Apagando");
  // Espera 1 segundo
  delay(100);

  // Envia 3.3V. para o pino 27
  digitalWrite(pin27out, HIGH);
  Serial.println("Acendendo");
  // Espera 2 segundos
  delay(200);

  // Envia 0V. para o pino 26
  digitalWrite(pin26out, LOW);
  Serial.println("Apagando");
  // Espera 1 segundo
  delay(100);

  // Envia 3.3V. para o pino 26
  digitalWrite(pin26out, HIGH);
  Serial.println("Acendendo");
  // Espera 2 segundos
  delay(200);
}

