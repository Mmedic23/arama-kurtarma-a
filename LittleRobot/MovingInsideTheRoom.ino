void searchForDoor() {
  if (!isBackAvailable()) {
    go(20, 75);
  }
  //  else {
  //    if (isLeftAvailable()) {
  //      while (isBackAvailable()) {
  //        turnInsideTheRoom('+');
  //      }
  //      instantStop();
  //      delay(300);
  //      while(!isBackAvailable()) {
  //        setMotors(180, 200);
  //      }
  //    }
  //    else {
  //      while (isBackAvailable()) {
  //        turnInsideTheRoom('-');
  //      }
  //      instantStop();
  //      delay(300);
  //      while(!isBackAvailable()) {
  //        setMotors(180, 200);
  //      }
  //    }
  //  }

  if (!isNextToWall()) {
    if(isFacingDoor){
      makeEncoderZero();
      turn(90);
    }
    while (!isFacingDoor()) {
      turnInsideTheRoom('+'); // Turn left (in positive direction)
    }
    /*double beginAngle = getHeading();
      while (isFacingDoor()) {
      turnInsideTheRoom('+');
      }
      double endAngle = getHeading();
      turn(endAngle - (endAngle - beginAngle) / 2);
    */
    idealDegree = 0;
    delay(1);
    setMotors(255, -255);
    delay(20);
    stopMotors();
    makeEncoderZero();
  }
  else {
    if(isFacingDoor){
      makeEncoderZero();
      turn(-90);
    }
    while (!isFacingDoor()) {
      turnInsideTheRoom('-');
    }
    /*
      double beginAngle = getHeading();
      while (isFacingDoor()) {
      turnInsideTheRoom('-');
      }
      double endAngle = getHeading();
      turn(((endAngle + beginAngle) / 2) - 5);
    */
    idealDegree = 0;
    delay(62);
    stopMotors();
    makeEncoderZero();
    
  }

  goUntilLineIsWhite(180);
  instantStop();
  delay(500);
  setMotors(160,240);
  delay(150);
  int cmCounter = distanceMeasure('r');
  while (distanceMeasure('r') < cmCounter + 40) {
    pidLineFollow();
  }
}

void turnInsideTheRoom(char direction) {
  int directionSign;
  if (direction == '+')
    directionSign = 1;
  else if (direction == '-')
    directionSign = -1;

  setMotors(directionSign * -70, directionSign * 70);
}
