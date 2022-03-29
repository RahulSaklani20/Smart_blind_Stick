#define WaterSensorPin A0 
const int trigPin1 = 3;
const int echoPin1 = 2;
const int trigPin2 = 5;
const int echoPin2 = 4;
const int trigPin3 = 7;
const int echoPin3 = 6;
const int buzzer1 = 8;
const int motor = 9;
const int buzzer2 = 10;


long Firstduration;
long Secondduration;
long Thirdduration;
float distance1;
float distance2;
float distance3;
float WatersensorValue = 0; 
int safetyDistanceA;
int safetyDistanceB;
int safetyDistanceC;


void setup() {
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT);  
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT); 
pinMode(echoPin3, INPUT); 
pinMode(buzzer1, OUTPUT);
pinMode(buzzer2, OUTPUT);
pinMode(motor, OUTPUT);
Serial.begin(9600); 
}


void loop() {
//1
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);


digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);


digitalWrite(trigPin1, LOW);



Firstduration = pulseIn(echoPin1, HIGH);

distance1= Firstduration*0.034/2;

//2
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);


digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);


digitalWrite(trigPin2, LOW);

Secondduration = pulseIn(echoPin2, HIGH);


distance2= Secondduration*0.034/2;

//3

digitalWrite(trigPin3, LOW);
delayMicroseconds(2);



digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);


digitalWrite(trigPin3, LOW);


Thirdduration = pulseIn(echoPin3, HIGH);

distance3= Thirdduration*0.034/2;


safetyDistanceA = distance1;
safetyDistanceB = distance2;
safetyDistanceC = distance3;


for (int i = 0; i <= 100; i++) 
 { 
   WatersensorValue = WatersensorValue + analogRead(WaterSensorPin);  
 } 
 WatersensorValue = WatersensorValue/100.0; 

 if(safetyDistanceC>400){
  digitalWrite(buzzer1,HIGH);
  
 }


if (safetyDistanceA<50 || safetyDistanceB<50 || safetyDistanceC>30){
  digitalWrite(buzzer1,HIGH);
  digitalWrite(motor,HIGH);
  }

  else {
   digitalWrite(buzzer1,LOW);
  digitalWrite(motor,LOW);
  }
if (WatersensorValue<950){
  tone(buzzer2,1000);
  digitalWrite(motor,HIGH);}
  else{
  noTone(buzzer2);}

  
  

Serial.print("Distance1: ");
Serial.println(distance1);
Serial.print("Distance2: ");
Serial.println(distance2);
Serial.print("Distance3: ");
Serial.println(distance3);
Serial.print("WaterValue: ");
Serial.println(WatersensorValue); 
}
