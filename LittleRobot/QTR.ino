const byte qtrPins[] = {22, 23, 24, 25, 26, 27, 28, 29};
// Note: qtrValues is declared in the main tab.


// Defines qtr input pins as input pullup
void defineQTR ()  {
  for (byte i = 0; i < 8; i++)  {
    pinMode(qtrPins[i], INPUT_PULLUP) ;
  }
}




// Reads values from qtr sensor and assings the values to array qtrValues
void qtrRead() {
  for (int i = 0; i < 8; i++) {
    qtrValues[i] = digitalRead(qtrPins[i]) == 1 ? 0 : 1;
  }
}


//Checks the first and last qtr pins to are they on the white line or not.
boolean isLineCompletelyWhite() {
  qtrRead();
  int qtrSum = 0;
  for (int i = 0; i < 7; i++) {
    qtrSum += qtrValues[i];
  }
  return qtrSum > 3;
}

boolean isOnWhiteLine() {
  qtrRead();
    for (int i = 0; i < 7; i++) {
      if(qtrValues[i] == 1)
      return true;
  }
  return false;
  
}

// Prints the current values of the qtr sensor to serial port. For testing and debugging.
void qtrTest() {
  qtrRead();
  for (int i = 0; i < 8 ; i++) {
    Serial.print(qtrValues[i]) ;
    Serial.print(" ");
  }
  Serial.println();
}
