int ledPin = 13;
int pulsante = 7;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pulsante, INPUT);
}

void loop() {
  int acceso = digitalRead(pulsante);
  if (acceso == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
