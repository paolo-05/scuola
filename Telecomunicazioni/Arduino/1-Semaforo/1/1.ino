int verde1 = 2, giallo1 = 3, rosso1 = 4;
int verde2 = 5, giallo2 = 6, rosso2 = 7;

void setup() {
  pinMode(verde1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(rosso1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(rosso2, OUTPUT);
}

void loop() {
  digitalWrite (verde1, HIGH);
  digitalWrite (rosso2, HIGH);
  delay (3500);
  digitalWrite (giallo1, HIGH);
  digitalWrite (verde1, LOW);
  delay (1500);
  digitalWrite (giallo1, LOW);
  digitalWrite (rosso1, HIGH);
  digitalWrite (rosso2, LOW);
  digitalWrite (verde2, HIGH);
  delay (4000);
  digitalWrite (giallo2, HIGH);
  digitalWrite (verde2, LOW);
  delay (1500);
  digitalWrite (giallo2, LOW);
  digitalWrite (rosso2, HIGH);
  digitalWrite (rosso1, LOW);
  digitalWrite (verde1, HIGH);
}
