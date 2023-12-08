#include <Wire.h>

#define I2C_SDA 14  
#define I2C_SCL 15  
#define I2C_ADDR 0X23

void setup(){
    Serial.begin(115200);
    Wire.begin(I2C_SDA,I2C_SCL);

}

void loop(){
    Wire.beginTransmission(I2C_ADDR);
    Serial.println("Transferring");
    Wire.write('a');
    Wire.endTransmission();
    delay(1000);
    
}