double qtrKp=40, qtrKd=26;
int qtrError = getPosition();
int lastQtrError = qtrError;
int pidSpeed;
int leftBaseSpeed = 200;
int rightBaseSpeed = 200;
const int qtrMults[] = {7, 5, 3, 1, -1, -3, -5, -7};

//Calculates error value qith using PD and sets motors with that value
void pidLineFollow(){
 qtrError = getPosition();
 pidSpeed = qtrKp*qtrError + qtrKd*(qtrError - lastQtrError);
 lastQtrError = qtrError;
 setMotors(leftBaseSpeed - pidSpeed, rightBaseSpeed + pidSpeed);
}


//Creates a position due to qtr sensor's position at line if two qtr sensors detect the line takes avarage of that values.
//Also if robot get out of the line it returns last value of error. With this feature we can get in to the line.
int getPosition() {
  qtrRead();
  int sum = 0;
  int valueCounter = 0;
  for (byte i = 0; i < 8; i++) {
    if (qtrValues[i] == 1){
      valueCounter++; 
    }
    sum += qtrValues[i] * qtrMults[i];
  }
  if (valueCounter == 0) {
    return qtrError;
  }
  sum /= valueCounter;
  return sum;
}
void turnUntilQTRIsZero(){
  setMotors(-200,190);
  while(qtrValues [3] != 0){
  }
  stopMotors();
  idealDegree = 360;
}
