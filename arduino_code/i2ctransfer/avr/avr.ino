#include <Wire.h>

#define I2C_ADDR 0X23

void setup(){
  pinMode(13,OUTPUT);
    Serial.begin(9600);
    Wire.begin(I2C_ADDR);

}

void loop(){
    
    while (Wire.available()) {
      char c = Wire.read();
      if(c=='a'){
        digitalWrite(13,HIGH);
        delay (100);
        digitalWrite(13,LOW);
        delay(100);
        Serial.print(c);
      }
      
    }
    //Serial.println();
}
