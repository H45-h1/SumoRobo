#include <IRremote.h>

// C++ code
//

const int Motor_NI=3;
const int Motor_PI=2;
const int Motor_ND=5;
const int Motor_PD=4;

const int Sensor_I= 10;
const int Sensor_C= 9;
const int Sensor_D= 8;
int Data_I=0;
int Data_C=0;
int Data_D=0;

const int trigPin= 11;
const int echoPin=12;

void setup()
{
  pinMode(Motor_NI,OUTPUT);
  pinMode(Motor_PI,OUTPUT);
  pinMode(Motor_ND,OUTPUT);
  pinMode(Motor_PD,OUTPUT);
  
  pinMode(Sensor_I,INPUT);
  pinMode(Sensor_C,INPUT);
  pinMode(Sensor_D,INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  Serial.begin(9600);
}

void Revisar_Lineas();
void Avanzar();
void Retroceder();
void Izq(bool sentido);
void Der(bool sentido);
void girar();
float ultrasonido();
void infrarojo();

void loop()
{
  
  float distancia= ultrasonido();
  infrarojo();
  Serial.print(Data_I);
  Serial.print(Data_C);
  Serial.println(Data_D);
  
  Serial.println(distancia);
  if(distancia>120){
    Avanzar();
    delay(10);
  }else if(distancia<60){
  	Atras();
    delay(10);
  }else{
  	girar();
    delay(100);
  }
  delay(500);
  
}

void infrarojo(){
	Data_I=digitalRead(Sensor_I);
	Data_C=digitalRead(Sensor_C);
	Data_D=digitalRead(Sensor_D);
}

float ultrasonido(){
  digitalWrite(trigPin,LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  
  long tiempo = pulseIn(echoPin,HIGH);
  
  return tiempo*0.034/2;

}

void Avanzar(){
  digitalWrite(Motor_NI,LOW);
  digitalWrite(Motor_ND,LOW);
  digitalWrite(Motor_PI,HIGH);
  digitalWrite(Motor_PD,HIGH);
}

void Atras(){
  digitalWrite(Motor_PI,LOW);
  digitalWrite(Motor_PD,LOW);
  digitalWrite(Motor_NI,HIGH);
  digitalWrite(Motor_ND,HIGH);
}

void Izq(bool sentido){
  if(sentido==true){
  	digitalWrite(Motor_NI,LOW);
  	digitalWrite(Motor_ND,LOW);
  	digitalWrite(Motor_PD,LOW);
  	digitalWrite(Motor_PI,HIGH);
  }else{
  	digitalWrite(Motor_PI,LOW);
  	digitalWrite(Motor_ND,LOW);
  	digitalWrite(Motor_PD,LOW);
  	digitalWrite(Motor_NI,HIGH);
  }
}

void Der(bool sentido){
  if(sentido==true){
  	digitalWrite(Motor_NI,LOW);
  	digitalWrite(Motor_PI,LOW);
  	digitalWrite(Motor_ND,LOW);
  	digitalWrite(Motor_PD,HIGH);
  }else{
  	digitalWrite(Motor_NI,LOW);
  	digitalWrite(Motor_PI,LOW);
  	digitalWrite(Motor_PD,LOW);
    digitalWrite(Motor_ND,HIGH);
  }
}

void girar(){
	digitalWrite(Motor_PI,LOW);
  	digitalWrite(Motor_ND,LOW);
  	digitalWrite(Motor_PD,HIGH);
  	digitalWrite(Motor_NI,HIGH);
}