//Paolo Bianchessi 3ic 03/11/2021


int ledPin = 13;
int v;
void setup() {
  pinMode (ledPin, OUTPUT); //LED
}

void loop () {
  int luce = analogRead (A0);
  digitalWrite(ledPin, HIGH);
  delay(luce);
  digitalWrite(ledPin, LOW);
  delay(luce);
}
