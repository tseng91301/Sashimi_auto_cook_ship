#define TDS_SENSOR_READ_PIN A0
#define TDS_SENSOR_DATA_FILTERING 10 //Use the number of data to make output more accurate

void tds_init(){
    pinMode(TDS_SENSOR_READ_PIN,INPUT);
}
double get_tds_value(){
    double t1=0.0;
    for(int a=0;a<TDS_SENSOR_DATA_FILTERING;a++){
        int t2=analogRead(TDS_SENSOR_READ_PIN);
        if(!t2){
            t1+=0.001;
        }else{
            t1+=(double)t2;
        }
        delay(1);
    }
    t1/=TDS_SENSOR_DATA_FILTERING;
    t1=t1*5.0/1024.0;
    double tdsValue=(133.42/pow(t1,3) - 255.86*pow(t1,2) + 857.39*t1)*0.5; //Convert voltage value to TDS value
    return tdsValue+0.0001;
}