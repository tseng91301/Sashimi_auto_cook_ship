#include "motors.h"
#include "ir_sensor.h"
#include "general_conf.h"
#include "joystick.h"
#include "uartrec.h"

char state='S';
void setup(){
    j_init();
    m_init();
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
    move(data_to_motor(state));
    /*int x=read_x();
    int y=read_y();
    if(x>0){
        if(y>0){
            move(5);
        }else if(y==0){
            move(3);
        }        
    }else if(x<0){
        if(y>0){
            move(4);
        }else if(y==0){
            move(2);
        } 
    }else if(y<0){
        move(1);
    }else if(y>0){
        move(0);
    }else{
        stop();
    }*/
}