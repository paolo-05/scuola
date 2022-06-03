/*Dichiarazione delle variabili*/
int ledEsterni = 1;
int ledCasa = 2;
int interruttoreLuceCasa = 3;
int fotoR = 0;

// nel setup seleziono i pin mode per i led (output) e il pulsante (input)
void setup() {
  pinMode(ledEsterni, OUTPUT);
  pinMode(ledCasa, OUTPUT);
  pinMode(interruttoreLuceCasa, INPUT);
}

void loop() {
  // dichiarazione iniziale per dire che il led inizialmente è spento
  bool attivo = false;
  // leggo il valore del fotoresistore in modo analogico
  int luce = analogRead(fotoR);
  // il valore va da 0 a 1023 dove 1023 è il più alto quindi con più luce
  // se la luce è minore di 300, c'è buio
  if (luce < 300) {
    // accendo i led esterni e li tengo accesi per almeno 1''
    digitalWrite(ledEsterni, HIGH);
    delay(1000);
  }
  // qui gestisco il pulsante per gli interni
  // se il pulsante è premuto
  if (digitalRead(interruttoreLuceCasa) == HIGH) {
    // se lo stato del led è spento..
    if (!attivo) {
      // cambio in acceso e accendo effettivamente il led
      attivo = true;
      digitalWrite(ledCasa, HIGH);
    }
    else {
      // altrimenti il led è già acceso e la pressione del pulsante
      // vuol dire spegnre la luce
      attivo = false;
      digitalWrite(ledCasa, LOW);
    }
  }
  // qui spengo per sicurezza i led esterni che altrimenti rimarrebbero accesi
  digitalWrite(ledEsterni, LOW);
}
