#include <SPI.h>
#include <mcp2515.h>
#include<LiquidCrystal.h>


struct can_frame canMsg;
MCP2515 mcp2515(10);


// LiquidCrystal lcd(12,11,10,9,8,7);
float value=0;
float rev=0;
int rpm;
int oldtime=0;
int time;
int rpm1000;
 
void isr() //interrupt service routine
{
rev++;
}
 
void setup()
{
while (!Serial);
Serial.begin(9600);
// lcd.begin(16,2); //initialize LCD
mcp2515.reset();
mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
mcp2515.setNormalMode();
attachInterrupt(1,isr,RISING); //attaching the interrupt
// attachInterrupt(0,isr,RISING); //attaching the interrupt
}
 
void loop()
{
    delay(1000);
    detachInterrupt(1); //detaches the interrupt
    time=millis()-oldtime; //finds the time
    rpm=(rev/time)*60000*3; //calculates rpm for blades
    rpm1000=rpm/1000;
    oldtime=millis(); //saves the current time
    rev=0;
    Serial.println(rpm1000);
    attachInterrupt(1,isr,RISING);

    canMsg.can_id  = 0x01;           //CAN id as 0x036
    canMsg.can_dlc = 8;               //CAN data length as 8
    canMsg.data[0] = rpm1000;               //Update humidity value in [0]
    canMsg.data[1] = 0x00;               //Update temperature value in [1]
    canMsg.data[2] = 0x00;            //Rest all with 0
    canMsg.data[3] = 0x00;
    canMsg.data[4] = 0x00;
    canMsg.data[5] = 0x00;
    canMsg.data[6] = 0x00; 

  mcp2515.sendMessage(&canMsg);
  // delay(500); 
}