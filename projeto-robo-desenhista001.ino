#include <Servo.h>

#define SERVO 11 // Porta Digital 11
Servo s1; //variavel do servo
int s1Pos=0; //posicao do servo
int pinod0 = 3;
int button1 = 4;
int button2 = 13;
int button3 = 12;
volatile byte pulsos;
//unsigned long timeold;

unsigned int ppv = 20; //pulsos por volta

const int ena = 10;
const int p1ma = 8;
const int p2ma = 7;

const int enb = 9;
const int p1mb = 6;
const int p2mb = 5;

void setup() {
  Serial.begin(9600);
  s1.attach(SERVO);
  s1.write(s1Pos);
  pinMode(pinod0, INPUT);
  //timeold = 0;
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(p1ma, OUTPUT);
  pinMode(p2ma, OUTPUT);
  
  pinMode(enb, OUTPUT);
  pinMode(p1mb, OUTPUT);
  pinMode(p2mb, OUTPUT);

}

void loop() {
   
    if(digitalRead(button1)==1) {
      desenho1();
    }
    if (digitalRead(button2)==1) {
      desenho2();
    }
    if(digitalRead(button3)==1) {
      desenho3();
    }

}
    
void desenho1() {
    pulsos = 0;
    s1.write(90);
    
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
    
    RotacionaMotor(1, 1);
    RotacionaMotor(2, 1);
    
    digitalWrite(enb, HIGH);
    digitalWrite(ena, HIGH);

    while(pulsos < 20) {
      if(digitalRead(pinod0) == 1) {
        while(digitalRead(pinod0) == 1) {} 
        pulsos++;
        Serial.println(pulsos, DEC);
      }
    }
    
    pulsos = 0;
    s1.write(0);

    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);

    RotacionaMotor(1, 2);
    RotacionaMotor(2, 1);

    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);
    delay(150);
    Serial.println(pulsos, DEC);

    pulsos = 0;
    
    do{
      if(digitalRead(pinod0)){
        while(digitalRead(pinod0) == 1) {}
        pulsos++;
      }
      Serial.println(pulsos, DEC);
    } while(pulsos < 20);

    Serial.println("Morreu");
}

void desenho2 () {
    pulsos = 0;
    s1.write(90);
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
    
    RotacionaMotor(1, 1);
    RotacionaMotor(2, 2);
    
    digitalWrite(enb, HIGH);
    digitalWrite(ena, HIGH);

    while(pulsos < 40) {
      if(digitalRead(pinod0) == 1) {
        while(digitalRead(pinod0) == 1) {}
        pulsos++;
        Serial.println(pulsos, DEC);
      }
    }
    s1.write(0);
}

void desenho3 () {
    pulsos = 0;
    s1.write(90);
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);

    RotacionaMotor(1, 1);
    RotacionaMotor(2, 1);

    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    while(pulsos < 20) {
      if(digitalRead(pinod0) == 1) {
        while(digitalRead(pinod0) == 1) {}
        pulsos++;
        Serial.println(pulsos, DEC);
      }
    }
    pulsos = 0;
    s1.write(0);

    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);

    RotacionaMotor(1, 1);
    RotacionaMotor(2, 2);

    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    while(pulsos < 20) {
      if(digitalRead(pinod0)==1){
        while(digitalRead(pinod0) == 1) {}
        pulsos++;
      }
    }
    pulsos = 0;
    s1.write(0);

    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);

    RotacionaMotor(1, 2);
    RotacionaMotor(2, 2);

    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    while(pulsos <20) {
      if(digitalRead(pinod0)) {
        while(digitalRead(pinod0) ==1) {}
        pulsos++;
      }
    }
    pulsos = 0;
    s1.write(90);

    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);

    RotacionaMotor(1, 1);
    RotacionaMotor(2, 1);

    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    //while(pulsos < 20)
    

}

void RotacionaMotor (int motor, int sentido) {
  if(motor == 1) {
    if(sentido == 1) {
      digitalWrite(p1ma, 1);
      digitalWrite(p2ma, 0);
    } else {
      if(sentido == 2) {
        digitalWrite(p1ma, 0);
        digitalWrite(p2ma, 1);
      } else
          return;
    }
  } else {
    if(motor == 2) {
      if(sentido == 2) {
        digitalWrite(p1mb, 1);
        digitalWrite(p2mb, 0);
    } else {
      if(sentido == 1) {
        digitalWrite(p1mb, 0);
        digitalWrite(p2mb, 1);
      } else
          return;
    }
    } else
        return;
  }
}

