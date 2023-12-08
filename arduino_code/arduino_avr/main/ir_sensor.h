#define ir_rec A0
int ir_data_adoption=10;

void ir_init(){
    pinMode(ir_rec,INPUT);
}
int get_ir_val(){
    int getv=0;
    for(int a=0;a<ir_data_adoption;a++){
        getv+=analogRead(ir_rec);
        delay(1);
    }
    getv/=ir_data_adoption;
    return getv;
}