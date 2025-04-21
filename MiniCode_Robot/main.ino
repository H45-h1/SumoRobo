int MotorAP_1=2;
int MotorAN_1=3;
int MotorAP_2=4;
int MotorAN_2=5;

void setup(){
  // put your setup code here, to run once:
  pinMode(MotorAP_1, OUTPUT); // Motor A hacia adelante
  pinMode(MotorAN_1, OUTPUT); // Motor A hacia atrás
  pinMode(MotorAP_2, OUTPUT); // Motor B hacia adelante
  pinMode(MotorAN_2, OUTPUT); // Motor B hacia atrás

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

void loop(){
  // put your main code here, to run repeatedly:

}