  //Récupération de la température
     void temp(void) {
      
        Serial.print("Requesting temperatures...");
        sensors.requestTemperatures();
        float tempC = sensors.getTempCByIndex(0);
        tm1637.displayNum(tempC); 

     }
