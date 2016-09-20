#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int pinod0 = 2;
int rpm;
volatile byte pulsos;
//unsigned long timeold;

unsigned int ppv = 6; //pulsos por volta

const int ena = 10;
const int p1ma = 8;
const int p2ma = 7;

const int enb = 9;
const int p1mb = 6;
const int p2mb = 5;

void contador ()
{
  pulsos--;
  
}

void setup() {
  Serial.begin(9600);
  pinMode(pinod0, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinod0), contador, CHANGE);
  pulsos = 0;
  rpm = 0;
  //timeold = 0;
  lcd.begin(16, 2);
  pinMode(ena, OUTPUT);
  pinMode(p1ma, OUTPUT);
  pinMode(p2ma, OUTPUT);
  
  pinMode(enb, OUTPUT);
  pinMode(p1mb, OUTPUT);
  pinMode(p2mb, OUTPUT);

}

void loop() {

  
  
  
  do {
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
  
    RotacionaMotor(1, 1);
    RotacionaMotor(2, 2);
  
    digitalWrite(enb, HIGH);
    digitalWrite(ena, HIGH);
    delay(150);
    Serial.println(pulsos, DEC);
  } while (pulsos > 0);
  //delay(2000);
/*
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);

  RotacionaMotor(1, 2);
  RotacionaMotor(2, 1);

  digitalWrite(enb, HIGH);
  digitalWrite(ena, HIGH);
  delay(2000);

  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("teste1");
  lcd.setCursor(0,1);
  lcd.print("teste2");
  delay(1000);

    rpm = pulsos/(millis() * 1000);
    pulsos = 0;

    Serial.print("pulsos = ");
    Serial.println(pulsos, DEC);
    Serial.print("Hz = ");
    Serial.println(rpm, DEC);
*/
    //attachInterrupt(0, contador, FALLING);

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
      if(sentido == 1) {
        digitalWrite(p1mb, 1);
        digitalWrite(p2mb, 0);
    } else {
      if(sentido == 2) {
        digitalWrite(p1mb, 0);
        digitalWrite(p2mb, 1);
      } else
          return;
    }
    } else
        return;
  }
}

