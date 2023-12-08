#include <ArduinoJson.h>

#include "motors.h"
#include "general_conf.h"
#include "uarttransfer.h"
#include "tds.h"
#include "water_temp.h"
#include "water_trans.h"

long unsigned int time_now;
char state='S';
void setup(){
    // Initialize sensor/motor's pins
    time_now=millis();
    m_init();
    tds_init();
    water_temp_init();
    water_trans_init();

    Serial.begin(baud_rate);
    stop();
}
void loop(){
    while(Serial.available()){
        char t1=Serial.read();
        if(t1<='Z'&&t1>='A'){
            state=t1;
            move(data_to_motor(state));
            delay(10);
        }
    }
    long unsigned int time_tmp=millis();
    if((time_tmp-time_now)>=(int)sensor_detect_T){
        time_now=time_tmp;
        DynamicJsonDocument values(200);
        values["time"]=time_now;
        values["tds"]=get_tds_value();
        values["water_temp"]=get_water_temp_value();
        values["water_trans"]=get_water_trans_value();

        String values_o;
        serializeJson(values,values_o);
        uartsend(values_o);
    }
    move(data_to_motor(state));
}