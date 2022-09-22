
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A15,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


Serial.println(analogRead(A15));

}
