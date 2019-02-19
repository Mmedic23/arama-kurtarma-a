void searchForDoor() {
  if(!isBackAvailable()) {
    go(20,75);
  }
  if (isLeftAvailable()) {
    while (!isFacingDoor()) {
      turnInsideTheRoom('-');
    }
    int initAngle = getHeading();
    while (isFacingDoor()) {
      turnInsideTheRoom('-');
    }
    int lastAngle = getHeading();
    turn(lastAngle - (lastAngle - initAngle)/2);
  }
  else {
    while (!isFacingDoor()) {
      turnInsideTheRoom('+');
    }
    int initAngle = getHeading();
    while (isFacingDoor()) {
      turnInsideTheRoom('+');
    }
    int lastAngle = getHeading();
    turn(lastAngle - (lastAngle - initAngle)/2);
  }
  goUntilLineIsWhite(180);
  int cmCounter = distanceMeasure('r');
  while(distanceMeasure('r')< cmCounter + 30){
      pidLineFollow();
  }

 
}

void turnInsideTheRoom(char direction){
  int directionSign;
  if (direction == '+')
    directionSign = 1;
  else if (direction == '-')
    directionSign = -1;
    
  setMotors(-directionSign*70,directionSign*70);  
}
