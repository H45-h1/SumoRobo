#include <IRremote.h>

// C++ code
//



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