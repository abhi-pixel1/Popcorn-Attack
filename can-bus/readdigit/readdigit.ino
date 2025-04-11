int pButton1=3;
int pButton2=4;
int pButton3=5;
int pButton4=6;

void setup() {

Serial.begin(9600);

pinMode(pButton1,INPUT);
pinMode(pButton2,INPUT);
pinMode(pButton3,INPUT);
pinMode(pButton4,INPUT);

}

void loop(){

int bState1=digitalRead(pButton1);
int bState2=digitalRead(pButton2);
int bState3=digitalRead(pButton3);
int bState4=digitalRead(pButton4);

Serial.print(bState1);
Serial.print(" ");
Serial.print(bState2);
Serial.print(" ");
Serial.print(bState3);
Serial.print(" ");
Serial.println(bState4);


delay(5000);

}