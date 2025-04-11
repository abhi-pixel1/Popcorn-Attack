#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>          //Library for using SPI Communication 
#include <mcp2515.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

struct can_frame canMsg;

MCP2515 mcp2515(10);

void setup() {
  while (!Serial);
  Serial.begin(9600);
  SPI.begin();               //Begins SPI communication
  // dht.begin();               //Begins to read temperature & humidity sesnor value
 
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();

}

void loop() {
   sensors.requestTemperatures();
  //  int sensorValue = analogRead(sensorPin);
   int Celsius = sensors.getTempCByIndex(0);
   int Fahrenheit = sensors.toFahrenheit(Celsius);
   Celsius = Celsius*(-1);
   Fahrenheit = Fahrenheit*(-1);

     
  //  checksum = canMsg.can_id + canMsg.can_dlc + canMsg.data[3] + canMsg.data[6]; 

  canMsg.can_id  = 0x036;           //CAN id as 0x036
  canMsg.can_dlc = 8;               //CAN data length as 8
  canMsg.data[0] = 0x00;               //Update humidity value in [0]
  canMsg.data[1] = 0x00;               //Update temperature value in [1]
  canMsg.data[2] = 0x00;            //Rest all with 0
  canMsg.data[3] = Celsius;
  canMsg.data[4] = 0x00;
  canMsg.data[5] = 0x00;
  canMsg.data[6] = Fahrenheit;

  int checksum = (canMsg.can_id) + (canMsg.can_dlc) + (canMsg.data[0]) + (canMsg.data[1])+(canMsg.data[2])+(canMsg.data[3])+(canMsg.data[4])+(canMsg.data[5])+(canMsg.data[6]);
  // canMsg.data[7] = checksum/3;
canMsg.data[7] = 8

   Serial.print(canMsg.can_id);
   Serial.print(" ");
   Serial.print(canMsg.can_dlc);
   Serial.print(" ");
   Serial.print(canMsg.data[3]+canMsg.data[6]+canMsg.can_dlc+canMsg.can_id);
   Serial.print(" ");
   Serial.print(canMsg.data[5]);
   Serial.print(" ");
   Serial.print(canMsg.data[6]);
   Serial.print(" ");
   Serial.println(canMsg.data[7]);


  mcp2515.sendMessage(&canMsg);

  //  Serial.print(Celsius);
  //  Serial.print(" C  ");
  //  Serial.print(Fahrenheit);
  //  Serial.println(" F");

   delay(500);
  }