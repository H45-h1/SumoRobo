#Define Motor_PI = 2;
#Define Motor_NI = 3;
#Define Motor_PD = 4;
#Define Motor_ND = 5; 
#Define Sensor_D = 8; 
#Define Sensor_C = 9;
#Define Sensor_I = 10;
#Define trigPin = 11;
#Define echoPin = 12;

int Data_I=0;
int Data_C=0;
int Data_D=0;

//IRrecv Sensor_I (10);
IRrecv Sensor_C (9);
IRrecv Sensor_D (8);

void Retroceder();
float ultrasonido();
void infrarojo();
bool Norte= true;


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
  
  short integer tiempo = pulseIn(echoPin,HIGH);
  
  return tiempo*0.034/2;

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
