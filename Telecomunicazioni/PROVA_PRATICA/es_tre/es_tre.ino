int leds[]={12, 11, 10, 9, 8, 7, 6, 5, 4, 3};

int led_dispari[] = { 12, 10, 8, 6, 4 };  // array di pin di arduino collegati a led dispani in ordine crescente
int led_pari[] = { 3, 5, 7, 9, 11 };      //array dei pin di arduino collegati a led pari in ordine descrescente

int led = 1;

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  for(int i = 0; i<10; i++){
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for(int j = 0;j<10; j++){
    digitalWrite(leds[j], LOW);
  }
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
  for (int i = 0; i < 5; i++) {
    digitalWrite(led_dispari[i], HIGH);
    delay(1000);
    digitalWrite(led_dispari[i], LOW);
  }
  delay(500);
  for (int j = 0; j < 5; j++) {
    digitalWrite(led_pari[j], HIGH);
    delay(1000);
    digitalWrite(led_pari[j], LOW);
  }
  delay(500);
  
}
