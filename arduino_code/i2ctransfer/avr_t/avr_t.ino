#include<Wire.h>
void setup(){
    Wire.begin();

}
void loop(){
    Wire.beginTransmission(0x23);
    Wire.write('a');
    Wire.endTransmission();
    delay(1000);
}