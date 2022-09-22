// include the library code:
#include <LiquidCrystal.h>
#include <Bounce2.h>
#include <Keypad.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

//LiquidCrystal(rs, rw, enable, d4, d5, d6, d7) 
LiquidCrystal lcd(12,11,5,4,3,2);


// Instantiate a Bounce object
Bounce startDebouncer1 = Bounce(); 


// Instantiate another Bounce object
Bounce resetDebouncer2 = Bounce();  
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'.','0','#','D'}
};
byte rowPins[ROWS] = {13, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 22, 23}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup() {  
   char customKey = customKeypad.getKey();
 
  // After setting up the button, setup the Bounce instance :
  startDebouncer1.attach('A');
  startDebouncer1.interval(5); // interval in ms
    

  // After setting up the button, setup the Bounce instance :
  resetDebouncer2.attach('B');
  resetDebouncer2.interval(5); // interval in ms
 
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.print("*** StopWatch **");
  lcd.setCursor(0, 1);
  lcd.print("***  Project ***");

  delay(500);

  // clear screen for the next loop:


  Serial.begin(9600);

  Serial.println("StopWatch using Arduino Nano");
  Serial.println("Press Following Switches:- ");
  Serial.println("Black Switch for Start/Stop");
  Serial.println("Red Switch for Reset");
}


bool startState = LOW;
bool resetState = LOW;

unsigned long startMillis;
unsigned long currentMillis;
unsigned long elapsedMillis;

void loop() {

  // Update the Bounce instances :
  startDebouncer1.update();

   if ( startDebouncer1.fell() ) {     // Call code if button transitions from HIGH to LOW
     startState = !startState;         // Toggle start button state
     startMillis = millis();
   }

  if (startState)
  {
    currentMillis = millis();
    elapsedMillis = (currentMillis - startMillis);
    
    lcd.setCursor(0, 0);
    lcd.print("SW (hh:mm:ss:ms)");
    lcd.setCursor(0, 1);
    lcd.print("                ");

    Serial.print("elapsedMillis: ");
    Serial.print(elapsedMillis);
    Serial.println("");
    
    unsigned long durMS = (elapsedMillis%1000);       //Milliseconds
    unsigned long durSS = (elapsedMillis/1000)%60;    //Seconds
    unsigned long durMM = (elapsedMillis/(60000))%60; //Minutes
    unsigned long durHH = (elapsedMillis/(3600000));  //Hours
    durHH = durHH % 24; 
    
    Serial.print("Time: ");
    Serial.print(durHH);
    Serial.print(" : ");
    Serial.print(durMM);
    Serial.print(" : ");
    Serial.print(durSS);
    Serial.print(" : ");
    Serial.print(durMS);
    Serial.println("");
    
    String durMilliSec = timeMillis(durHH, durMM, durSS,durMS);
    lcd.setCursor(0, 1);
    lcd.print(durMilliSec);
    
    Serial.println("******************************");
    Serial.println("");
    
    delay(150);
  }
  
  resetDebouncer2.update();

  if (resetDebouncer2.fell())
  {
    resetState = HIGH;
  }

  if (resetState)
  {
    // clear screen for the next loop:
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Press B-Strt/Stp");
    
    lcd.setCursor(0, 1);
    lcd.print("Press R-Reset");

    Serial.println("StopWatch using Arduino Nano");
    Serial.println("Press Following Switches:- ");
    Serial.println("Black Switch for Start/Stop");
    Serial.println("Red Switch for Reset");
    Serial.println("");

    delay(100);
    
    resetState = LOW;
  }
     
}

String timeMillis(unsigned long Hourtime,unsigned long Mintime,unsigned long Sectime,unsigned long MStime)
{
  String dataTemp = "";

  if (Hourtime < 10)
  {
    dataTemp = dataTemp + "0" + String(Hourtime)+ "h:";
  }
  else{
    dataTemp = dataTemp + String(Hourtime)+ "h:";
  }
  
  if (Mintime < 10)
  {
    dataTemp = dataTemp + "0" + String(Mintime)+ "m:";
  }
  else{
    dataTemp = dataTemp + String(Mintime)+ "m:";
  }
  
  if (Sectime < 10)
  {
    dataTemp = dataTemp + "0" + String(Sectime)+ "s:";
  }
  else{
    dataTemp = dataTemp + String(Sectime)+ "s:";
  }
  
  dataTemp = dataTemp + String(MStime);

  Serial.print("String Time: ");
  Serial.println(dataTemp);
  
  return dataTemp;
}
