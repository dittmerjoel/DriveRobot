

  int trigger=8; //ULRASCHALL
  int echo=9;  //ULRASCHALL
  long dauer=0; //reflektionsdauer

const int AIA = 3;
const int AIB = 4;
const int BIA = 5;
const int BIB = 6;
byte gesch = 255;



 
  long entfernung=0; //VAR Entfernung nach Vorne
  

 //------------------------------------------------------------

  
 
void setup() {
 
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(10,OUTPUT);
 Serial.begin(9600);
 

 }
 
void loop(){

  Serial.println(entfernung);
  
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  
  entfernung = (dauer/2) / 29.1;
  
  if (entfernung<20){
    analogWrite(AIA, 0);
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);
    digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  
  entfernung = (dauer/2) / 29.1;
  digitalWrite(10,HIGH);
}
else{
    analogWrite(AIA, 0);
    analogWrite(AIB, gesch);
    analogWrite(BIA, gesch);
    analogWrite(BIB, 0);
    digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  
  entfernung = (dauer/2) / 29.1;
  digitalWrite(10,LOW);
}
}

  
  
  

  
