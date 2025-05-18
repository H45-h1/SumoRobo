#include <IRremote.h>

// C++ code
//

//IRrecv Sensor_I (10);
IRrecv Sensor_C (9);
IRrecv Sensor_D (8);

const int Motor_NI=4;
const int Motor_PI=5;
const int Motor_ND=6;
const int Motor_PD=7;


void setup()
{
  pinMode(Motor_NI,OUTPUT);
  pinMode(Motor_PI,OUTPUT);
  pinMode(Motor_ND,OUTPUT);
  pinMode(Motor_PD,OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(10, DISABLE_LED_FEEDBACK);
  Sensor_C.begin(9, DISABLE_LED_FEEDBACK);
  //Sensor_D.begin(8, DISABLE_LED_FEEDBACK);
}

void Revisar_Lineas();
void Avanzar();
void Retroceder();
void Izq(bool sentido);
void Der(bool sentido);
void girar();

void loop()
{
  
  Avanzar();
  if (IrReceiver.decode()) {
      	Serial.print("0x");
		Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
		IrReceiver.resume();
	}
  delay (100);
  
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

void Revisar_Lineas(){
	if (IrReceiver.decode()) {
      	Serial.print("0x");
		Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
		IrReceiver.resume();
	}
  delay (10);
}