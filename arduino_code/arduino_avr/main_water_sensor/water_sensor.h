#define WATER_SENSOR_REC_PIN A0
#define WATER_SENSOR_DATA_FILTERING 10 //Use the number of data to make output more accurate
void water_sensor_init(){
    pinMode(WATER_SENSOR_REC_PIN, INPUT);
}
int read_water_sensor(){
    int out=0;
    for(int a=0;a<WATER_SENSOR_DATA_FILTERING;a++){
        out+=analogRead(WATER_SENSOR_REC_PIN);
        delay(1);
    }
    out/=WATER_SENSOR_DATA_FILTERING;
    return out; // return the calculated value
}