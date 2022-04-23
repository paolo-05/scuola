#define LDS 6
int xPin = 0;
int yPin = 1;
int zPin = 1;
int xVal = 0, yVal = 0, zVal = 1;

typedef struct bar {
  int pin;
  int posLog;
} Bar;
// utlizzo delle struct perché consentono di associare il numero di pin e la posizione logica di un LED
Bar xLed[LDS] = { { 2, -3 }, { 3, -2 }, { 4, 1 }, { 5, 1 }, { 6, 2 }, { 7, 3 } };       // verde - rosso
Bar yLed[LDS] = { { 8, -3 }, { 9, -2 }, { 10, -1 }, { 11, 1 }, { 12, 2 }, { 13, 3 } };  // giallo - blu

void setup() {
  pinMode(zPin, INPUT);
  for (int i = 0; i < LDS; i++) {
    pinMode(xLed[i].pin, OUTPUT);
    pinMode(yLed[i].pin, OUTPUT);
  }
}

void loop() {
  // tramtite la funzione map() possiamo fare la proporzione del valore in input, al numero del LED da accendere.
  xVal = map(analogRead(xPin), 0, 1023, -3, 3);
  yVal = map(analogRead(yPin), 0, 1023, -3, 3);
  // lettura del valore HIGH - LOW del pulsante centrale
  zPin = digitalRead(zPin);

  for (int i = 0; i < LDS; i++) {
    for (int x = -3; x < 3; x++)
      if (xLed[i].posLog == xVal)
        digitalWrite(xLed[i].pin, HIGH); // accendo il LED numero i 

    for (int y = -3; y < 3; y++)
      if (yLed[i].posLog == yVal)
        digitalWrite(yLed[i].pin, HIGH);
  }

  if (zPin != HIGH) { // il valore del pulsante è invertito (premuto -> LOW; non premuto -> HIGH)
    accendiLed(HIGH);
    delay(1000);
  }
  accendiLed(LOW);
}
// utilizza il valore (HIGH - LOW) per accedenre - spegnere tutti i led
void accendiLed(int val) {
  for (int i = 0; i < LDS; i++) {
    digitalWrite(xLed[i].pin, val);
    digitalWrite(yLed[i].pin, val);
  }
}
