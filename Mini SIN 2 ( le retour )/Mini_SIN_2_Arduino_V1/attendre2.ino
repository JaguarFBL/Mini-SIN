     void attendre2(void) {  
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
