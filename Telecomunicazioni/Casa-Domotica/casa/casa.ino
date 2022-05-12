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
  bool attivo = false;
  int luce = analogRead(fotoR);
  if(luce < 300){
    digitalWrite(ledEsterni, HIGH);
    delay(1000);
    }

    if(digitalRead(interruttoreLuceCasa) == HIGH){
      if(!attivo){
        attivo = true;
        digitalWrite(ledCasa, HIGH);
      }
      else{
        attivo = false;
        digitalWrite(ledCasa, LOW);
      }
    }
    digitalWrite(ledEsterni, LOW);
}