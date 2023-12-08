#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#define baud_rate 115200

String command;             //String to store app command State.
const char* ssid = "Sashimi Auto Cook Ship";
ESP8266WebServer server(80);

void HTTP_handleRoot(void) {
    if( server.hasArg("State") ){
        Serial.println(server.arg("State"));
    }
    server.send ( 200, "text/html", "" );
    delay(1);
}

void go(String d){
    char d2=d[0];
    if(d2<='Z'&&d2>='A'){
        Serial.write((int)d2);
        delay(10);
    }
    return;
}

void setup(){
    Serial.begin(baud_rate);

    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    server.on ( "/", HTTP_handleRoot );
    server.onNotFound ( HTTP_handleRoot );
    server.begin();
}
void loop(){
    server.handleClient();
    command = server.arg("State");
    go(command);
    /*if (command == "F") goAhead();
    else if (command == "B") goBack();
    else if (command == "L") goLeft();
    else if (command == "R") goRight();
    else if (command == "I") goAheadRight();
    else if (command == "G") goAheadLeft();
    else if (command == "S") stopRobot();*/
}