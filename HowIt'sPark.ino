     
 
int trigPin = 3;    // Trigger
int echoPin = 2; 
int i=0;
int j=0;
int m = 0;
int pos = 90;  
long distance1=0;
long distance2 = 0;
long distance;
  int parkDistance;
#include <Servo.h>

Servo myservo; 



// Echo
long duration, cm;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
 pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object

}
 
void loop() {digitalWrite(trigPin, LOW);
//for(m;m<1;m++){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
  


    if(distance<12 && distance>0){
    Serial.println("Забелязано движение");
    delay(1000);
    for(int i = 10;i>0;i--){
    duration = pulseIn(echoPin, HIGH);


     if(distance==(duration*0.034/2)){
      Serial.println(i);
      delay(1000);
     }
    }
    delay(3000);
    Serial.println("Колата е паркирана");
   
 distance1 =servo1();
  Serial.println();
  Serial.print("Първа част ");
  Serial.print(distance1);
  Serial.println();
  distance2 =servo2();
  Serial.println();
  Serial.print("Втора част ");
  Serial.print(distance2);
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();


  if(distance1>distance2) {
    Serial.println("   Колата е паркирана напред ");
    Serial.println("            ___________");
    Serial.println("           //   |||   \\" );         
    Serial.println("__________//____|||____\\ __");   
    Serial.println("| _|             |       | _ |");
    Serial.println("|/ \_____________|_______|/ \|");
    Serial.println("_\_/______________________\_/_______");
  }else{
    Serial.println("   Колата е паркирана назад ");
    Serial.println("      ___________");
    Serial.println("     //   |||   \\" );         
    Serial.println("  __//____|||____\\__________");   
    Serial.println(" | _|      |          _     ||");
    Serial.println(" |/ \______|_________/ \_ _ || ");
    Serial.println(" _\_/________________\_/_______");
  
   } 
   }
   }
  

  


long first_half(){

  long sumFirstDistance=0;
  servo1();
  for(j;j<6;j++){
  long firstDistance[6];
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  cm = (((duration/2) / 29.1)*10); 
    if(cm<12){
    firstDistance[j]=cm;
    sumFirstDistance+=firstDistance[j];
    Serial.print(firstDistance[j]);
    Serial.print(",");
    }

  }
  return sumFirstDistance;
}

long secondHalf(){
  long sumSecondDistance=0;
    long secondDistance[6];

  for(j;j<6;j++){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  cm = ((duration/2) / 29.1)*10; 
    if(cm<140){
    secondDistance[j]=cm;
    sumSecondDistance+=secondDistance[j];
    Serial.print(secondDistance[j]);
    Serial.print(",");
    }

  }
  return sumSecondDistance;
}



long servo1() {
  
  j=0;
  long sumFirstDistance=0;
  long firstDistance[3];
  
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
     
   digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
  


    if(distance<12 && distance >0){
    firstDistance[j]=distance;
    sumFirstDistance+=firstDistance[j];
    Serial.print(firstDistance[j]);
    Serial.print(",");
    pos+=5;
           delay(200);

        j++;
  
  delay(1500);    

     if(j==5){
      pos=90;
  myservo.write(pos);
  
      break;
     }
                    

      

  
         
      

}

  
 
    pos=90;
  myservo.write(pos);
        return sumFirstDistance;

}

long servo2() {
  j=5;
  pos=90;
      long sumSecondDistance=0;
duration = pulseIn(echoPin, HIGH);
    for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
     
    long secondDistance[5];

    digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
  

 if(distance<12 && j>=5 && pos>90){
    secondDistance[j-5]=distance;
    sumSecondDistance+=secondDistance[j-5];
    Serial.print(secondDistance[j-5]);
    Serial.print(",");
    pos+=5;
            j++;


    
     if(j==10){
      pos=90;
  myservo.write(pos);
  
      break;
     }
    }
    delay(200);

 }
       

     pos=90;
       myservo.write(pos);
       return sumSecondDistance;

}
