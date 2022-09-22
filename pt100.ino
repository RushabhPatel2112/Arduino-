#include <Adafruit_MAX31865.h>
#include<LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(12,11,5,4,3,2);
//Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 thermo = Adafruit_MAX31865(53, 51, 50, 52);
// use hardware SPI, just pass in the CS pin
//Adafruit_MAX31865 thermo = Adafruit_MAX31865(53);
float y=0;
float x=0;
float k=0;
String z;
float c;
char a1[8];
int i1;
// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {13, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 22, 23}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
  
  //Serial.println("Adafruit MAX31865 PT100 Sensor Test!");
lcd.begin(16,2);
  thermo.begin(MAX31865_3WIRE);  // set to 2WIRE or 4WIRE as necessary
}


void loop() {
  char customKey = customKeypad.getKey();

  uint16_t rtd = thermo.readRTD();

 // Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  //Serial.print("Ratio = "); Serial.println(ratio,8);
  //Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature = "); 
  x=thermo.temperature(RNOMINAL, RREF);
  k=x+y;
  lcd.setCursor(0,1);
  
 lcd.print(k,1);
   //lcd.setCursor(5,1);
  //lcd.print("(char) 223"); 
  
     lcd.setCursor(6,1);
  lcd.print("C "); 

  // Check and print any faults
  uint8_t fault = thermo.readFault();
  if (fault) {
    lcd.print("Fault 0x"); lcd.print(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      lcd.print("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      lcd.print("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      lcd.print("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      lcd.print("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      lcd.print("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      lcd.print("Under/Over voltage"); 
    }
    thermo.clearFault();
  }

}

float calbration2(){
lcd.clear();
lcd.print(x);
 if (customKey&&i1<7){
     a1[i1]=customKey;
     i1++;
 lcd.setCursor(i1,1);
      lcd.print(customKey);
  }

z=z+a1;
if(i1==7){

i1++;
y = a1.toFloat();
lcd.print(y);
}
