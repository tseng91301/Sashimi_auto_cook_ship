void setup(){
    Serial.begin(9600);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
}
void loop(){
    Serial.println("abc");
    String a1="(";
    a1+=String(analogRead(A1));
    a1+=", ";
    a1+=String(analogRead(A2));
    a1+=")";
    Serial.println(a1.c_str());
    delay(200);
}