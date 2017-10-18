# ASEF_D
This is a project for developing an alerting device which will alert its user especially those with vision and hearing impaired when someone tries to enter their house and to detect any gas leakage. This idea is presented in Assited System For Disabled (ASEF_D) as an alerting device. Bluetooth master and slave concept are used to complete this product where the master is placed at the entrance to detect obstacle and transmit to its slave which is mounted at the bracelet of the user with vibrators.   ASEF_D  is based on the Bluetooth master and slave concept. This product comes with a bracelet (slave) which vibrates as it receives information from the system (master) when it senses a motion at the door and if any dangerous gas is sensed . This project used two circuits which are Bluetooth Master Connection and Bluetooth Slave Connection.
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);// RX AND TX
const int IRsensor = 6;
const int sensorPin= 0; // the pin your gas sensor connected to
const int BuzzPin = 2;
int smoke_level;
int state;

int IRState = 0;
 
void setup() {

Serial.begin(9600);
mySerial.begin(9600);
pinMode(IRsensor,INPUT);
pinMode(sensorPin, INPUT);
pinMode(BuzzPin ,OUTPUT);
}

void loop() {


//Serial.println(smoke_level);
//delay(1000);
IRState = digitalRead(IRsensor);
smoke_level= analogRead(sensorPin);
if (IRState == LOW){
   int i =1;
   mySerial.write(i);
   
  digitalWrite(BuzzPin,LOW);
  Serial.println("IR HIGH");
  delay(1000);
}
if(smoke_level > 150){
  int k = 2;
  mySerial.write(k);
 digitalWrite(BuzzPin,HIGH);
  Serial.println("GAS ");
  delay(1000);
  }

if(IRState == HIGH )  {
   int j= 0;
   mySerial.write(j);
    
  digitalWrite(BuzzPin,LOW);
  Serial.println("IR LOW");
  delay(1000); 
  
}

}
