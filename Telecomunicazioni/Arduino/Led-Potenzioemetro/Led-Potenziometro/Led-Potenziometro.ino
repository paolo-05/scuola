int ledPin = 13;
int v;
void setup() {
  pinMode (ledPin, OUTPUT); //LED
}

void loop () {
  int potenza = analogRead (A0);
  digitalWrite(ledPin, HIGH);
  delay(potenza);
  digitalWrite(ledPin, LOW);
  delay(potenza);
}