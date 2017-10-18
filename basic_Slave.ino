#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);// RX AND TX

int state = 0;
const int pushbutton = 2;
const int Vibrator = 8;
int pb = 0;
int vb = 0;

void setup() {
  // initialize digital pin 8 as an output.

  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(pushbutton , INPUT );
  pinMode(Vibrator , OUTPUT );



}

void loop() {
  pb = digitalRead(pushbutton);
 

  if(pb == HIGH){//masukakn digitalwrite dekat sini utk buzzer
    int h = 50;
    mySerial.write(h);
   // Serial.println( h);
    
    
    }
    if(pb == LOW){
      int o = 30;
      mySerial.write(o);
    // Serial.println(o);
      
      }

  if (mySerial.available() > 0) { // Checks whether data is comming from the serial port
    state = mySerial.read(); // Reads the data from the serial port
  }
  // Serial.println(state);
  // delay(1000);
   

  if(state == 0){
    Serial.println(" OFF" );
    
    digitalWrite(Vibrator, LOW);
    delay(20);
    
    }
    else if (state == 1){

      Serial.println("ON");
      
      digitalWrite(Vibrator, HIGH);
      delay(20);  
      }
     else if (state == 2){

      Serial.println("GAS");
     
      digitalWrite(Vibrator, HIGH);
      delay(20);
      }

  
}
