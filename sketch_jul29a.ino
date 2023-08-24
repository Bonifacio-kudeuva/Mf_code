
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 7;
int ENA = 5;
int ENB = 6;

int triger = 8;
int echo = 9;

int velocidadeB = 120;
float velocidadeM = 140;
int velocidadeA = 255;
int velocidadeD = 135;

double distancia;
long tempo;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

  digitalWrite(triger, LOW);
}

void loop() {

 readdistance();

if (distancia < 15) {
  desviar();
}
  else {
    frente();
  }
  frente();
  
}

void readdistance() {
  digitalWrite(triger, HIGH);
  delay(10);
  digitalWrite(triger, LOW);


  tempo = pulseIn(echo, HIGH);  //tira os 2000 se meu fi quisé
  distancia = tempo / 58;
  
}

void distanciaA() {

  if (distancia = 10) {
    float r = 0.7;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENA, velocidadeM);
    analogWrite(ENB, velocidadeM * r);
  }
}

void frente() {
  digitalWrite(in1,LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ENA, velocidadeB);
  analogWrite(ENB, velocidadeB );
  Serial.println("indo em frente");
}

void tras() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ENA, -velocidadeM);
  analogWrite(ENB, -velocidadeM);
}

void esquerda() {
  float r = 0.7;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ENA, velocidadeM);
  analogWrite(ENB, velocidadeM * r);
  Serial.println("esquerda");
}

void direita() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ENA, velocidadeM);
  analogWrite(ENB, velocidadeM);
}

void debug() {
  while (true) {
    Serial.println("parado");


    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}

void desviar(){
  esquerda();
    delay(380);
    frente ();
    delay(320);
    direita();
    delay(380);
    frente();
    delay(800);
    direita();
    delay(500);
    frente();
    delay(300);
    esquerda();
    delay(400);
}