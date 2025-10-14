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
     Serial.begin(9600);
     DCYState = digitalRead(DCY);
     FCGState = digitalRead(FCG);
     FCDState = digitalRead(FCD);
  }
     
     void avant() {  
          digitalWrite(LEDAV,HIGH);
     }
     
     void arr() {  
          digitalWrite(LEDAR,HIGH);
     }
     
     void attendre() {  
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
         
     
 

void loop()
 { 
   int tour = 0;
   DCYState = digitalRead(DCY);
   
   
   
  //pour DCYState appuyé c'est 0
  while ( digitalRead(DCY)==0){
    Serial.println("Rien");
  }
  
  
  
  while ( DCYState != 0 ){
     for (int i = 1; i<=3;i++){

     Serial.println("Démarrage en cours....");     
  
     FCGState = digitalRead(FCG);
     DCYState = digitalRead(FCD);

     son_DCY();
     
     
     while ( digitalRead(FCD) == 0 && digitalRead(FCG) == 0){
         Serial.println("Marche avant");
   delay(100);         
         avant();
     }
 
     while ( digitalRead(FCD) == 1){
        Serial.println("Attendre");
        son_AB();
  delay(100); 
        attendre();
     }
     
      while ( digitalRead(FCG) == 0){
         Serial.println("Marche arrière");           
         arr();
     }
     
      while ( digitalRead(FCG) == 1){
         tour=tour+1;
   delay(100);
         Serial.println(tour);
         Serial.println("Attendre....");
         son_AB();
   delay(100); 
         attendre2();
         stop();   
     }
    }  
  }
 }
