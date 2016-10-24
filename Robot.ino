int trigger=8; //ULRASCHALL
int echo=9;  //ULRASCHALL
long dauer=0; //reflektionsdauer

const int AIA = 3; //Motor A Ausgang A
const int AIB = 4; //Motor A Ausgang B
const int BIA = 5; //Motor B Ausgang A
const int BIB = 6; //Motor B Ausgang B
byte gesch = 255; // Geschwindigkeit (Analog)
long entfernung=0; //Entfernungsvariable als long, also lange Variante abgespeichert 
  

 //------------------------------------------------------------

  
 
void setup() {                        //Läuft beim anschalten, bzw beim Reset einmal
 
  pinMode(trigger, OUTPUT);           //PWM ausgabesignal als Schall
  pinMode(echo, INPUT);               //PWM aufzeichnen des Ausgabesignals
  pinMode(AIA, OUTPUT);               //Alle Motorausgänge als Ausgang definieren
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(10,OUTPUT);                 //LED an Pin 10 als OUTPUT
  Serial.begin(9600);                 //Daten über USB an Monitoring senden mit 9600 Boardrate
 

 }
 
void loop(){                          //Läuft für immer

  Serial.println(entfernung);         //Schreibe die Variable entfernung im Monitoring
  
  digitalWrite(trigger, LOW);         //Messvorgang und Umrechnung in cm
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  
  entfernung = (dauer/2) / 29.1;
  
  if (entfernung<20){                 //Falls die Entfernung kleiner als 20 ist, wird follgendes ausgeführt
    analogWrite(AIA, 0);              //Alle Ausgänge auf Gesch. 0 also Stopp
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);
    digitalWrite(trigger, LOW);       //Entfernung messen....
    delay(5);
    digitalWrite(trigger, HIGH);
    delay(10);
    digitalWrite(trigger, LOW);
    dauer = pulseIn(echo, HIGH);
    entfernung = (dauer/2) / 29.1;
    
    digitalWrite(10,HIGH);            //LED an
}
else{                                 //Sonst, also falls if() nicht ausgeführt wird
    analogWrite(AIA, 0);              //Forwärtsfahren...
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
  
    digitalWrite(10,LOW);             //LED aus.
}
}

  
  
  

  
