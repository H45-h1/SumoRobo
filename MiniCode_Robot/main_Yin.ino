//? AP = Positivo || AN = Negativo
//? AD = ADelante || AT = ATras
#include <Sensores.h>



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

void loop() {
  // put your main code here, to run repeatedly:
  test();
}