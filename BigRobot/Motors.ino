#define in1L  A2  //Changelog 7/12/2018: const int changed with define for low memory consumption
#define in2L  A3
#define in1R  A0
#define in2R  A1
#define enL  8
#define enR  9

// METHODS IN HERE
// defineMotors
// setMotors
// stopMotors

void defineMotors() {
  pinModeFast(in1L, OUTPUT);
  pinModeFast(in1R, OUTPUT);
  pinModeFast(in2L, OUTPUT);
  pinModeFast(in2R, OUTPUT);
  pinModeFast(enL, OUTPUT);
  pinModeFast(enR, OUTPUT);
}

// Sets DC motors left and right to speedL and speedR respectively, using the L298N motor driver.
void setMotors(int speedL, int speedR) {  // Changelog 7/12/2018 : Going backward feature added HAVE TO BE TESTED
  //Serial.print("Left motor speed: ");
  //Serial.print(speedL);
  //Serial.print("  Right motor speed: ");
  //Serial.println(speedR);
  if (speedL >= 0) {
    digitalWrite(in1L, HIGH);
    digitalWrite(in2L, LOW);
  }
  else {
    digitalWriteFast(in1L, LOW);
    digitalWriteFast(in2L, HIGH);
    speedL *= -1;
  }

  if (speedR >= 0) {
    digitalWriteFast(in1R, HIGH);
    digitalWriteFast(in2R, LOW);
  }
  else {
    digitalWriteFast(in1R, LOW);
    digitalWriteFast(in2R, HIGH);
    speedR *= -1;
  }
  if (speedL > 255) {
    speedL = 255;
  }
  if (speedR > 255) {
    speedR = 255;
  }
  analogWrite(enL, speedL);
  analogWrite(enR, speedR);
}

//Stops motors immediately
void stopMotors() { // Added in 7/12/2018
  //  digitalWriteFast(in1L, LOW);
  //  digitalWriteFast(in2L, HIGH);
  //  digitalWriteFast(in1R, HIGH);
  //  digitalWriteFast(in2R, LOW);
  //  setMotors(100,100);
  //  delay(20);  

  digitalWriteFast(in1L, HIGH);
  digitalWriteFast(in2L, HIGH);
  digitalWriteFast(in1R, HIGH);
  digitalWriteFast(in2R, HIGH);
  setMotors(0, 0);
  //Serial.println("Motors Stopped because of stopMotors function");
}

void instantStop(){
  setMotors(-155,-155);
  delay(25);
  stopMotors();
}
