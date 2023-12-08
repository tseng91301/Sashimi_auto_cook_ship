//define pins of left motor
#define ml1 2
#define ml2 3

//define pins of right motor
#define mr1 4
#define mr2 5

void m_init(){
    //Set motor pins as output
    pinMode(ml1,OUTPUT);
    pinMode(ml2,OUTPUT);
    pinMode(mr1,OUTPUT);
    pinMode(mr2,OUTPUT);
}

void stop(){
    digitalWrite(ml1,LOW);
    digitalWrite(ml2,LOW);
    digitalWrite(mr1,LOW);
    digitalWrite(mr2,LOW);
}

void move(int dir,int mode=0/*If mode is 1, turn rapidly*/){
    if(dir==0){//move front
        digitalWrite(ml1,HIGH);
        digitalWrite(ml2,LOW);
        digitalWrite(mr1,HIGH);
        digitalWrite(mr2,LOW);
    }else if(dir==1){//move back
        digitalWrite(ml1,LOW);
        digitalWrite(ml2,HIGH);
        digitalWrite(mr1,LOW);
        digitalWrite(mr2,HIGH);
    }else if(dir==2){//move left
        digitalWrite(ml1,LOW);
        digitalWrite(ml2,HIGH);
        digitalWrite(mr1,HIGH);
        digitalWrite(mr2,LOW);
    }else if(dir==3){//move right
        digitalWrite(ml1,HIGH);
        digitalWrite(ml2,LOW);
        digitalWrite(mr1,LOW);
        digitalWrite(mr2,HIGH);
    }else if(dir==4){//front left
        digitalWrite(ml1,LOW);
        digitalWrite(ml2,LOW);
        digitalWrite(mr1,HIGH);
        digitalWrite(mr2,LOW);
    }else if(dir==5){//front right
        digitalWrite(ml1,HIGH);
        digitalWrite(ml2,LOW);
        digitalWrite(mr1,LOW);
        digitalWrite(mr2,LOW);
    }else{
        stop();
    }
    
}
