/*
Demo with Arduino Car (an Android app)

the Serial read input:
Forward: 70 'F'
Backward: 71 'B'
Left: 83 'L'
Right: 82 'R'
Left Front: 81 'G'
Right Front: 69 'I'
Left Back: 90 'Z'
Right Back: 67 'C'
Stop: 83 'S'

Front light (switch) 77 'M'
Back light (switch) 78 'N'

Mode X: 88 'X'
Mode Y: 89 'Y'
 */
#include <BluetoothSerial.h> 
#include "ble.h"
BluetoothSerial SerialBT; 

void setup() {
    Serial.begin(115200);
    SerialBT.begin(BLUETOOTH_NAME); //name the bluetooth and initialize
}

void loop() {
    if (SerialBT.available()) {
        char dat=SerialBT.read();
        if(dat>='A'&&dat<='Z'){
            Serial.write(dat);
        }
        
    }
}
