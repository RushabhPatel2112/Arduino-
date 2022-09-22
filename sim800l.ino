void setup()
{
 Serial.begin(9600);
 Serial.println("AT");
 delay(1000);
 Serial.println("AT+CMGF=1\r\n");//To set GSM in TEXT mode
 delay(500);
 Serial.println("AT+CMGS=\"+918160244827\"\r\n");//to send sms
 delay(2000);
 Serial.write("TEST");//SMS content
 delay(500);
 //Serial.println("ATD +919898367778;");//To make a call
 delay(2000);
//Serial.println((char)26);//ASCII value of ctrl+z to return from test mode(End of msg)
}
    void loop()
{}
 
