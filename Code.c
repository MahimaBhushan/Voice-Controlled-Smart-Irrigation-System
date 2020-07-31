


 #include <Servo.h>

int motor_input1=2;
int motor_input2=4;
int motor_input3=7;
int motor_input4=8;
int j=1; 
int k=1;
int m=1;
int LS=12;      // left sensor
int RS=13;      // right sensor
int sensor_pin = A0; 
int output_value;
int relay=6;
int pos=0;
int servopin=9;


Servo mypointer;
String voice;
String Voice;
void setup() 
{
  Serial.begin(9600);
  pinMode(motor_input1, OUTPUT);   //RIGHT MOTOR
  pinMode(motor_input2, OUTPUT);   //RIGHT MOTOR
  pinMode(motor_input3, OUTPUT);   //LEFT MOTOR
  pinMode(motor_input4, OUTPUT);   //LEFT MOTOR
  pinMode(6,OUTPUT);
  pinMode(servopin,OUTPUT);
    
  mypointer.attach(servopin);
   
pinMode(LS, INPUT);
pinMode(RS, INPUT);   
}

void loop() 
{  
  digitalWrite(6,HIGH);
  while(Serial.available()>0)
  {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {
      break;
    }
    voice+=c;
    }

   
   if(voice=="forward"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, HIGH);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, HIGH);
    delay(8000);  
    }
  else
    if(voice=="back"){
    digitalWrite(motor_input1, HIGH);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, LOW);  
    delay(5000);}
else  
   if(voice=="right"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, HIGH);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, LOW);
    delay(800); 
    }
   else
   if(voice=="left"){
    digitalWrite(motor_input1, HIGH);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, HIGH);
    delay(800);   }

else
   if(voice=="stop"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, LOW);
          }
    
else
if(voice=="follow")

    { 
 
 k=1;
   

 while(k)
 {
   
   
   
   while(Serial.available()>0)
  {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {
      break;
    }
    Voice+=c;
    }
 
   
  

if(digitalRead(LS) && digitalRead(RS))     // Move Forward
{
digitalWrite(motor_input4, HIGH);
digitalWrite(motor_input3, LOW);
digitalWrite( motor_input2, HIGH);
digitalWrite( motor_input1, LOW);
}

if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
{
digitalWrite( motor_input3, HIGH);
digitalWrite(motor_input4, LOW);
digitalWrite(motor_input1, LOW);
digitalWrite(motor_input2, LOW);
}

if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
{
digitalWrite(motor_input3, LOW);
digitalWrite(motor_input4, LOW);
digitalWrite(motor_input1, HIGH);
digitalWrite(motor_input2, LOW);
}

if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
{
j=1;
digitalWrite(motor_input3, LOW);
digitalWrite(motor_input4, LOW);
digitalWrite(motor_input1, LOW);
digitalWrite(motor_input2, LOW);

delay(1000);
 
 while(j)
 {
 mypointer.write(10);
 output_value= analogRead(sensor_pin);

   

   Serial.print("Mositure : ");

   Serial.print(output_value);

   Serial.println("");

   delay(1000);
    if(output_value<900)
    {
      digitalWrite(6,HIGH);
      mypointer.write(90);
      j=0;
      delay(2000);    
    }
    else
    {
      digitalWrite(6,LOW) ;
    }
    delay(1000);
 }
   digitalWrite(motor_input4, HIGH);
   digitalWrite(motor_input3, LOW);
   digitalWrite( motor_input2, HIGH);
   digitalWrite( motor_input1, LOW);
   delay(1000);
 
 
 }

if(Voice=="close")
  {
 digitalWrite(motor_input3, LOW);
digitalWrite(motor_input4, LOW);
digitalWrite(motor_input1, LOW);
digitalWrite(motor_input2, LOW); 
  k=0;
    }    
 }
 }
 
     
if(voice=="check"){
    m=1;
    while(m)
    {
      
    mypointer.write(10);
   
   output_value= analogRead(sensor_pin);

   

   Serial.print("Mositure : ");

   Serial.print(output_value);

   Serial.println("");

   delay(1000);
    if(output_value<900)
    {
      digitalWrite(6,HIGH);
      mypointer.write(90);
      m=0;    
    }
    else
    {
      digitalWrite(6,LOW) ;
    }
    delay(1000);
 


    
       }
}

  
    
   if(voice.length()>0)
    {
      Serial.println(voice);
       voice="";
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, LOW);
    }

     if(Voice.length()>0)
    {
      Serial.println(Voice);
       Voice="";
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, LOW);
    }
    
    }
