int ledEsterni = 1;
int ledCasa = 2;
int interruttoreLuceCasa = 3;
int fotoR = 0;
void setup(){
  pinMode(ledEsterni, OUTPUT);
  pinMode(ledCasa, OUTPUT);
  pinMode(interruttoreLuceCasa, INPUT);
}
void loop(){
  int attivo = 0;
  int luce = analogRead(fotoR);
  if(luce < 300){
    digitalWrite(ledEsterni, HIGH);
    delay(1000);
    }

    if(digitalRead(interruttoreLuceCasa) == HIGH){
      if(attivo == 0){
        attivo = 1;
        digitalWrite(ledCasa, HIGH);
      }
      else{
        attivo = 0;
        digitalWrite(ledCasa, LOW);
      }
    }
    digitalWrite(ledEsterni, LOW);
}