#define LDS 6
int xPin = 0;
int yPin = 1;
int zPin  = 1;
int xVal = 0, yVal = 0, zVal = 1;

int xLed[LDS] = {2, 3, 4, 5, 6, 7}; // verde - rosso
int yLed[LDS] = {8, 9, 10, 11, 12, 13}; // iallo - blu

void setup(){
  pinMode(zPin, INPUT);
  for(int i = 0; i < LDS; i++){
    pinMode(xLed[i], OUTPUT);
    pinMode(yLed[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  xVal = map(analogRead(xPin), 0, 1023, 0, 6);
  yVal = map(analogRead(yPin), 0, 1023, 0, 6);
  zPin = digitalRead(zPin);

  for(int i = 0; i < xVal; i++)
    digitalWrite(xLed[i], HIGH);

  for(int i = 0; i < yVal; i++)
    digitalWrite(yLed[i], HIGH);


  if (zPin != HIGH){
    accendiLed(HIGH);
    delay(1000);
  }
  accendiLed(LOW);
}

void accendiLed(int val){
  for(int i = 0; i < LDS; i++){
    digitalWrite(xLed[i], val);
    digitalWrite(yLed[i], val);
  }
}