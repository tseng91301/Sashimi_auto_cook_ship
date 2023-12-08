#define x_pin A1
#define y_pin A2
#define b_pin 6
#define readerr 40
int j_init(){
    pinMode(x_pin,INPUT);
    pinMode(y_pin,INPUT);
}
int read_x(){
    int r=analogRead(x_pin);
    if(abs(r-512)<=readerr){
        r=512;
    }
    
    r=map(r,0,1023,-100,100);
    return(r);
}
int read_y(){
    int r=analogRead(y_pin);
    if(abs(r-512)<=readerr){
        r=512;
    }
    
    r=map(r,0,1023,100,-100);
    return(r);
}
int read_b(){
    int r=digitalRead(b_pin);
    return r;
}