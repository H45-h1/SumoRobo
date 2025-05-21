#include <IRremote.h>
#include <Sensores.h>

// C++ code
//



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
