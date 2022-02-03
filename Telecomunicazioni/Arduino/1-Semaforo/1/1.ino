int carRed = 4;
int carYellow = 3;
int carGreen = 2;
int carRed1 = 7;
int carYel1 = 6;
int carGreen1 = 5;
int pedRed = 13;
int pedYel = 12;
int pedGreen = 11;
int button = 9;
int crossTime = 5000;
unsigned long changeTime;

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedYel, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop() {
  int state = digitalRead(button);
  if ((state == HIGH) && ((millis() - changeTime)) > 5000) {
    changeLights();
  }
  else{

  }
}

void changeLights() {
  int x;
  digitalWrite(carGreen, LOW); // green off
  digitalWrite(carGreen1, LOW);
  digitalWrite(carYellow, HIGH); // yellow on
  digitalWrite(, HIGH);
  delay(2000); // wait 2 seconds

  digitalWrite(carYellow, LOW); // yellow off
  digitalWrite(carRed, HIGH); // red on
  delay(1000); // wait 1 second till its safe

  digitalWrite(pedRed, LOW); // ped red off
  digitalWrite(pedGreen, HIGH); // ped green on
  delay(crossTime); // wait for preset time period
  digitalWrite(pedGreen, LOW);
  digitalWrite(pedYel, HIGH);
  delay(1000);
  digitalWrite(pedYel, LOW);
  
  digitalWrite(pedRed, HIGH);
  delay(500);

  //digitalWrite(carYellow, HIGH); // yellow on
  digitalWrite(carRed, LOW); //
  delay(1000);

  digitalWrite(carGreen, HIGH);
  digitalWrite(carYellow, LOW);

  changeTime = millis();
}
