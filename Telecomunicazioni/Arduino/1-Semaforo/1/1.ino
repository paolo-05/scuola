#define VERDE 0
#define GIALLO 1
#define ROSSO 2

int semaforoPrincipale[] = { 2, 3, 4 };
int semaforo2[] = {5, 6, 7};
int semaforoPedonale[] = { 11, 12, 13 };
int ritardo = 2000;
int pulsantePin = 9;
int attesaChiamata = 3000;

void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(semaforoPrincipale[i], OUTPUT);
    pinMode(semaforo2[i], OUTPUT);
    pinMode(semaforoPedonale[i], OUTPUT);
  }
  pinMode(pulsantePin, INPUT);
  cambiaLuce(semaforoPedonale, ROSSO);
  cambiaLuce(semaforoPrincipale, VERDE);
  cambiaLuce(semaforo2, ROSSO);
}

void loop(){
  if(digitalRead(pulsantePin) == HIGH){
    delay(attesaChiamata);
    cambiaLuce(semaforoPrincipale, GIALLO);
    delay(ritardo/2);
    cambiaLuce(semaforoPrincipale, ROSSO);
    cambiaLuce(semaforo2, ROSSO);
    cambiaLuce(semaforoPedonale, VERDE);
    delay(ritardo);
    cambiaLuce(semaforoPedonale, GIALLO);
    delay(ritardo/2);
    cambiaLuce(semaforoPedonale, ROSSO);
    cambiaLuce(semaforoPrincipale, VERDE);
  }
  else{
    cambiaLuce(semaforo2, ROSSO);
  cambiaLuce(semaforoPrincipale, VERDE);
  delay(ritardo);
  cambiaLuce(semaforoPrincipale, GIALLO);
  delay(ritardo/2);
  cambiaLuce(semaforoPrincipale, ROSSO);
  cambiaLuce(semaforo2, VERDE);
  delay(ritardo);
  cambiaLuce(semaforo2, GIALLO);
  delay(ritardo/2);
  }
}

void cambiaLuce(int semaforo[], int luce){
  for(int i = 0; i < 3; i++){
    if(i == luce){
      digitalWrite(semaforo[i], HIGH);
    }else{
      digitalWrite(semaforo[i], LOW);
    }
  }
}