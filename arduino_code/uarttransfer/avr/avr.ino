void setup(){
    Serial.begin(115200);
    pinMode(13,OUTPUT);
}
void loop(){
    if(Serial.available()){
        int data=Serial.read();
        if(data==123){
            digitalWrite(13,HIGH);
            delay(50);
            digitalWrite(13,LOW);
            delay(50);
            digitalWrite(13,HIGH);
            delay(50);
            digitalWrite(13,LOW);
            delay(50);
        }
    }
}