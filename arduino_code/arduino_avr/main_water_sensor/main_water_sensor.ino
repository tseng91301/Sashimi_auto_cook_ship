#include "water_sensor.h"
void setup(){
    water_sensor_init();
    Serial.begin(115200);
}
void loop(){
    Serial.println(read_water_sensor());
    delay(100);
}