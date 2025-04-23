//? AP = Positivo || AN = Negativo
//? AD = ADelante || AT = ATras

#define MotorAP_1 2 //MotorAP Izquierdo
#define MotorAN_1 3
#define MotorAP_2 4 //MotorAP Derecho
#define MotorAN_2 5

void setup(){
  // put your setup code here, to run once:
  pinMode(MotorAP_1, OUTPUT); // Motor A hacia adelante
  pinMode(MotorAN_1, OUTPUT); // Motor A hacia atrás
  pinMode(MotorAP_2, OUTPUT); // Motor B hacia adelante
  pinMode(MotorAN_2, OUTPUT); // Motor B hacia atrás

  digitalWrite(MotorAP_1,LOW);
  digitalWrite(MotorAN_1,LOW);
  digitalWrite(MotorAP_2,LOW);
  digitalWrite(MotorAN_2,LOW),

  Serial.begin(9600);
}

void adelante(){
  // Avanza el robot
  digitalWrite(MotorAP_1, HIGH); // Motor A hacia adelante
  digitalWrite(MotorAN_1, LOW);  // Motor A hacia atrás
  digitalWrite(MotorAP_2, HIGH); // Motor B hacia adelante
  digitalWrite(MotorAN_2, LOW);  // Motor B hacia atrás
}

void atras(){
  // Retrocede el robot
  digitalWrite(MotorAP_1, LOW);  // Motor A hacia adelante
  digitalWrite(MotorAN_1, HIGH); // Motor A hacia atrás
  digitalWrite(MotorAP_2, LOW);  // Motor B hacia adelante
  digitalWrite(MotorAN_2, HIGH); // Motor B hacia atrás
}

void derechaAD(){
  digitalWrite(MotorAP_1, HIGH);  // Motor A hacia adelante
  digitalWrite(MotorAN_1, LOW); // Motor A hacia atrás
  digitalWrite(MotorAP_2, LOW);  // Motor B hacia adelante
  digitalWrite(MotorAN_2, LOW); // Motor B hacia atrás
}

void izquierdaAD(){
  digitalWrite(MotorAP_1, LOW);  // Motor A hacia adelante
  digitalWrite(MotorAN_1, LOW); // Motor A hacia atrás
  digitalWrite(MotorAP_2, HIGH);  // Motor B hacia adelante
  digitalWrite(MotorAN_2, LOW); // Motor B hacia atrás
}

void derechaAT(){
  digitalWrite(MotorAP_1, LOW);  // Motor A hacia adelante
  digitalWrite(MotorAN_1, HIGH); // Motor A hacia atrás
  digitalWrite(MotorAP_2, LOW);  // Motor B hacia adelante
  digitalWrite(MotorAN_2, LOW); // Motor B hacia atrás
}

void izquierdaAT(){
  digitalWrite(MotorAP_1, LOW);  // Motor A hacia adelante
  digitalWrite(MotorAN_1, LOW); // Motor A hacia atrás
  digitalWrite(MotorAP_2, LOW);  // Motor B hacia adelante
  digitalWrite(MotorAN_2, HIGH); // Motor B hacia atrás
}

void toro(){
  //place holder 
}

void girar(){
  derechaAD();
  delay(500);
}

void test(){
  adelante();
  delay(100);
  atras();
  delay(100);
  izquierdaAT();
  delay(100);
  derechaAD();
  delay(100);
  derechaAT();
  delay(100);
  izquierdaAD();
  delay(100);
}

void loop(){
  test();
}