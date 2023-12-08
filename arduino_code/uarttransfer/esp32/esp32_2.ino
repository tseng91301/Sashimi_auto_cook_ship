#include <Wire.h>

void setup(){
    Serial.begin(115200);

}

void loop(){
    int time1=millis();
    while(millis()-time1<500){
        Serial.write('F');
    }
    time1=millis();
    while(millis()-time1<500){
        Serial.write('B');
    }
    
}
