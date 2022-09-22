int x=A1;
  int y=A2;


void setup() {
 
Serial.begin(9600);
pinMode(y,INPUT);
pinMode(x,INPUT);

}



void loop() {
 
int a=analogRead(y);
int b=analogRead(x);
Serial.println(a);
Serial.println(b);
delay(500);

}
