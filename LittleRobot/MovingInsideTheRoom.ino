void searchForDoor() {
  if (!isBackAvailable()) {
    go(20, 75);
  }
  if (isLeftAvailable()) {
    while (!isFacingDoor()) {
      turnInsideTheRoom('+');
    }
    double beginAngle = getHeading();
    while (isFacingDoor()) {
      turnInsideTheRoom('+');
    }
    double endAngle = getHeading();
    turn(endAngle - (endAngle - beginAngle) / 2);
  }
  else {
    while (!isFacingDoor()) {
      turnInsideTheRoom('-');
    }
    double beginAngle = getHeading();
    while (isFacingDoor()) {
      turnInsideTheRoom('-');
    }
    double endAngle = getHeading();
    turn(endAngle - (endAngle - beginAngle) / 2);
  }
  goUntilLineIsWhite(180);
  int cmCounter = distanceMeasure('r');
  while (distanceMeasure('r') < cmCounter + 30) {
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
