#include <Wire.h>
#include "rgb_lcd.h"
#include "TM1637.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2


OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

const int CLK = 7;
const int DIO = 8;
TM1637 tm1637(CLK, DIO);  

int LEDAV = 9;
int LEDAR = 3;


int DCY = 4;
int FCG = 5;
int FCD = 6;

int BUZ = 10;

int DCYState;
int FCGState;
int FCDState;

void setup()
 { 
     pinMode(9, OUTPUT);
     pinMode(3, OUTPUT);
     pinMode(4, INPUT);     
     pinMode(5, INPUT);       
     pinMode(6, INPUT);
     pinMode(10, OUTPUT);
     DCYState = digitalRead(DCY);
     FCGState = digitalRead(FCG);
     FCDState = digitalRead(FCD);
     tm1637.init();
     tm1637.set(BRIGHTEST);
     lcd.clear();
     lcd.begin(16, 2);
     lcd.setRGB(colorR, colorG, colorB);
     Serial.begin(9600);
     Serial.println("Dallas Temperature IC Control Library Demo");
     sensors.begin();
  }
     
     void avant() {  
      
          lcd.clear();
          digitalWrite(LEDAV,HIGH);
          lcd.print("Marche avant");
          
     }
     
     void arr() {  
      
          lcd.clear();
          digitalWrite(LEDAR,HIGH);
          lcd.print("Marche arriere");
          
     }
     
     void attendre() {  
      
           lcd.clear();
           lcd.print("Chariot point B");
           for (int i = 1; i<=8;i++){
           digitalWrite(LEDAV,HIGH);
           delay(50);
           digitalWrite(LEDAV,LOW);
           delay(50);
           digitalWrite(LEDAV,HIGH);
           delay(50);
           digitalWrite(LEDAV,LOW);   
            
     }
     }  

     void attendre2() {  
           lcd.clear();
           lcd.print("Chariot point A");
           for (int i = 1; i<=8;i++){
           digitalWrite(LEDAR,HIGH);
           delay(50);
           digitalWrite(LEDAR,LOW);
           delay(50);
           digitalWrite(LEDAR,HIGH);
           delay(50);
           digitalWrite(LEDAR,LOW);    
     }
     }  
      
      void stop() {  
          digitalWrite(LEDAR,LOW);
     }
     
     //======= Fonction SON_DCY =======
     void son_DCY() {  
           tone(10, 880, 100);
           delay(500);
           tone(10, 880, 100);
           delay(500);
           tone(10, 880, 100);
  
     }
     
     
     //======= Fonction SON_AB =======
     void son_AB() {  
       tone(10, 440, 100);
       delay(500);
       tone(10, 440, 100);
     }

     void temp() {
         // call sensors.requestTemperatures() to issue a global temperature 
          // request to all devices on the bus
        Serial.print("Requesting temperatures...");
        sensors.requestTemperatures(); // Send the command to get temperatures
        Serial.println("DONE");
       // After we got the temperatures, we can print them here.
      // We use the function ByIndex, and as an example get the temperature from the first sensor only.
      float tempC = sensors.getTempCByIndex(0);

         tm1637.displayNum(tempC); 

 
     }
         
     
 

void loop()
 { 
   int tour = 0;
   DCYState = digitalRead(DCY);

   
   
   
  //pour DCYState appuyé c'est 0
  while ( digitalRead(DCY)==0){
    lcd.clear();
    lcd.print("Attente depart");
    temp();
  }
  
  
  
  while ( DCYState != 0 ){
     for (int i = 1; i<=3;i++){     
  
     FCGState = digitalRead(FCG);
     DCYState = digitalRead(FCD);

     son_DCY();

     temp();
     
     
     while ( digitalRead(FCD) == 0 && digitalRead(FCG) == 0){
         delay(100);         
         avant();
         temp();
     }
 
     while ( digitalRead(FCD) == 1){
        son_AB();
        delay(100); 
        attendre();
     }
     
      while ( digitalRead(FCG) == 0){           
         arr();
         temp();
     }
     
      while ( digitalRead(FCG) == 1){
         tour=tour+1;
         tm1637.displayNum(tour); 
         delay(100);
         temp();
         son_AB();
         delay(100); 
         attendre2();
         stop();   
     }
    }  
  }
 }
