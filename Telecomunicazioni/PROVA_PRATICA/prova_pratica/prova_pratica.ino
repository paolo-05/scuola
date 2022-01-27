int led_dispari[] = { 12, 10, 8, 6, 4 };  // array di pin di arduino collegati a led dispani in ordine crescente
int led_pari[] = { 3, 5, 7, 9, 11 };      //array dei pin di arduino collegati a led pari in ordine descrescente


void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(led_dispari[i], OUTPUT);
    pinMode(led_pari[i], OUTPUT);
  }
}

void loop() {
  int v = analogRead(A0); // leggo il valore del potenziometro per aumentare/diminuire il delay
  for (int i = 0; i < 5; i++) {
    digitalWrite(led_dispari[i], HIGH);
    delay(v);
    digitalWrite(led_dispari[i], LOW);
  }
  delay(v);
  for (int j = 0; j < 5; j++) {
    digitalWrite(led_pari[j], HIGH);
    delay(v);
    digitalWrite(led_pari[j], LOW);
  }
  delay(v);
}
