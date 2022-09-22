int jx=A0;
int jy=A1;
int l1=8;
int l2=9;
int l3=10;
int l4=11;
int l5=12;

void led1(){
  digitalWrite(l1,1);
  return 0;
}
void led2(){
  digitalWrite(l2,1);
  return 0;
}
void led3(){
  digitalWrite(l3,1);
  return 0;
}
void led4(){
  digitalWrite(l4,1);
  return 0;
}
void led5(){
  digitalWrite(l5,1);
  return 0;
}

void setup() {
  
Serial.begin(9600);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(l5,OUTPUT);
pinMode(jx,INPUT);
pinMode(jy,INPUT);
}

void loop() {
int x=analogRead(jx);
int y=analogRead(jy);
//Serial.println(x);
//Serial.println(y);
if(x>=450&&x<=550){
  if(y>=450&&y<=550){
    led1();
  delay(50);
  }
}
if(x<=200){
  if(y>=450&&y<=550){
    led2();
  delay(50);
  }
}
if(x>=800){
  if(y>=450&&y<=550){
    led3();
  delay(50);
  }
}
if(x>=450&&x<=550){
  if(y<=200){
    led4();
  delay(50);
  }
}
if(x>=450&&x<=550){
  if(y>=800){
    led5();
  delay(50);
  }
}
else{
  digitalWrite(l1,0);
  digitalWrite(l2,0);
  digitalWrite(l3,0);
  digitalWrite(l4,0);
  digitalWrite(l5,0);
}
}
