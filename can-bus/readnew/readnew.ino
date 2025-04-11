#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  while (!Serial);
  Serial.begin(9600);
  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();
}



void loop() {
  char incomingByte;
  int num;
  // Serial.print("-->");
  // if(Serial.available()){  
    digitalWrite(LED_BUILTIN, HIGH);
    incomingByte = Serial.read();
    num = incomingByte - '0';

    canMsg.can_id  = 0x035;           //CAN id as 0x036
    canMsg.can_dlc = 8;               //CAN data length as 8
    canMsg.data[0] = num;               //Update humidity value in [0]
    canMsg.data[1] = 0x00;               //Update temperature value in [1]
    canMsg.data[2] = 0x00;            //Rest all with 0
    canMsg.data[3] = 0x00;
    canMsg.data[4] = 0x00;
    canMsg.data[5] = 0x00;
    canMsg.data[6] = 0x00; 

  if(canMsg.data[0] <= 26){
    mcp2515.sendMessage(&canMsg);
  }

  delay(500);  
  digitalWrite(LED_BUILTIN, LOW);    
}