//? AP = Positivo || AN = Negativo
//? AD = ADelante || AT = ATras

#define MotorI_P 2 //MotorAP Izquierdo
#define MotorI_N 3
#define MotorD_P 4 //MotorAP Derecho
#define MotorD_N 5

bool Norte= true;

void setup(){
  // put your setup code here, to run once:
  pinMode(MotorI_P, OUTPUT); // Motor A hacia adelante
  pinMode(MotorI_N, OUTPUT); // Motor A hacia atrás
  pinMode(MotorD_P, OUTPUT); // Motor B hacia adelante
  pinMode(MotorD_N, OUTPUT); // Motor B hacia atrás

  digitalWrite(MotorI_P,LOW);
  digitalWrite(MotorI_N,LOW);
  digitalWrite(MotorD_P,LOW);
  digitalWrite(MotorD_N,LOW),

  Serial.begin(9600);
}

void adelante(){
  digitalWrite(MotorI_P,HIGH);
  digitalWrite(MotorI_N,LOW);
  digitalWrite(MotorD_P,HIGH);
  digitalWrite(MotorD_N,LOW);
  Norte=true;
}

void atras(){
  digitalWrite(MotorI_P,LOW);
  digitalWrite(MotorI_N,HIGH);
  digitalWrite(MotorD_P,LOW);
  digitalWrite(MotorD_N,HIGH);
  Norte=false;
}

void izquierda(int time){
  if(Norte==true)
    digitalWrite(MotorI_P,LOW);
  else
    digitalWrite(MotorI_N,LOW);
  delay(time);
}

void derecha(int time){
  if(Norte==true)
    digitalWrite(MotorD_P,LOW);
  else
    digitalWrite(MotorD_N,LOW);
  delay(time);
}

void girar(){
  derecha(500);
}

void test(){
  adelante();
  delay(500);
  atras();
  delay(500);
  adelante();
  derecha(250);
  izquierda(250);
  atras();
  izquierda(250);
  derecha(250);

}

void loop() {
  // put your main code here, to run repeatedly:
  test();
}