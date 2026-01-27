     void attendre(void) {  
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
