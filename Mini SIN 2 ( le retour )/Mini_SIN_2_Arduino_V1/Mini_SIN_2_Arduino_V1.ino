#include <Wire.h>
#include "rgb_lcd.h"
#include "TM1637.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

const int CLK = 7;
const int DIO = 8;
TM1637 tm1637(CLK, DIO);  

int LEDAV = 2;
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
     pinMode(2, OUTPUT);
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
  }
     
      void stop() {  
          digitalWrite(LEDAR,LOW);
     }
     
void loop()
 { 
   int tour = 0;
   DCYState = digitalRead(DCY);
   
   
   
  //pour DCYState appuyé c'est 0
  while ( digitalRead(DCY)==0){
    lcd.clear();
    lcd.print("Attente depart");
    
  }
  
  
  
  while ( DCYState != 0 ){
     for (int i = 1; i<=3;i++){     
  
     FCGState = digitalRead(FCG);
     DCYState = digitalRead(FCD);

     son_DCY();
     
     
     while ( digitalRead(FCD) == 0 && digitalRead(FCG) == 0){
   delay(100);         
         avant();
     }
 
     while ( digitalRead(FCD) == 1){
        son_AB();
  delay(100); 
        attendre();
     }
     
      while ( digitalRead(FCG) == 0){           
         arr();
     }
     
      while ( digitalRead(FCG) == 1){
         tour=tour+1;
         tm1637.displayNum(tour); 
   delay(100);
         son_AB();
   delay(100); 
         attendre2();
         stop();   
     }
    }  
  }
 }
