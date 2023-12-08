#define WATER_TRANS_SENSOR_READ_PIN A2
#define WATER_TRANS_SENSOR_DATA_FILTERING 10 //Use the number of data to make output more accurate

void water_trans_init(){
    pinMode(WATER_TRANS_SENSOR_READ_PIN,INPUT);
}
double get_water_trans_value(){
    int t1=0;
    for(int a=0;a<WATER_TRANS_SENSOR_DATA_FILTERING;a++){
        t1+=analogRead(WATER_TRANS_SENSOR_READ_PIN);
        delay(1);
    }
    t1/=WATER_TRANS_SENSOR_DATA_FILTERING;
    return t1;
}