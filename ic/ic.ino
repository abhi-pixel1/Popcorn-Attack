#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h> 

struct can_frame canMsg;
 
MCP2515 mcp2515(10);


int motorPin1 = 6;
int motorPin2 = 7;
int motorPin3 = 8;
int motorPin4 = 9;
int delayTime = 50;
int flag = 0;
int RPM=0;
int pre_rpm=0;
int rpm=0;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();
}



void loop() {
  // put your main code here, to run repeatedly:
  if (mcp2515.readMessage(&canMsg)) // To receive data (Poll Read)
  {
    Serial.println(canMsg.data[0]);
    RPM=(canMsg.data[0]*0.57*10);
    rpm=RPM-pre_rpm;
    flag=0;
    if(rpm<0){
      flag=0-rpm;
      while(flag){
    digitalWrite(motorPin4, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin1, HIGH);
    delay(100);
    digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin1, LOW);
    delay(10);
    flag--;
      }}
      if(rpm>0){
        while(flag<=rpm){
    digitalWrite(motorPin4,LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin1, HIGH);
    delay(100);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin1, LOW);
    delay(10);
    flag++;
        }
        }
    if(rpm==0){}
    pre_rpm=RPM;
  }
}