char locationOfLittleRobot() {
  readNRF();
  return message;
}



void rescue(char roomNumber) {
  //There will be common moves
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  idealDegree = 0;
  makeEncoderZero();
  go(115, straightVelocity);
  instantStop();
  delay(500);
  if (roomNumber == '1') {
    turn(90);
    delay(500);
    goUntilLineIsWhite(straightVelocity);
    go(9, straightVelocity);
    instantStop();
    delay(500);
    turn(180);
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    instantStop();
    delay(500);
    go(-20, straightVelocity);
    instantStop();
    turn(270);
    delay(500);
    go(55, straightVelocity);
    instantStop();
    delay(500);
    turn(360);
    goUntilLineIsWhite(straightVelocity);
    stopMotors();
    while (true) {
    }
  }
  else if (roomNumber == '2') {
    turn(90);
    delay(500);
    goUntilLineIsWhite(straightVelocity);
    go(11, straightVelocity);
    instantStop();
    delay(500);
    turn(0); ///
    delay(500);
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    go(-15, straightVelocity);
    stopMotors();
    delay(500);
    turn(-90); ///
    stopMotors();
    delay(500);
    go(65, straightVelocity);
    instantStop();
    delay(500);
    turn(0);
    delay(500);
    goUntilLineIsWhite(straightVelocity);
  }
  else if (roomNumber == '3') {
    turn(-90);
    delay(500);
    goUntilLineIsWhite(straightVelocity);
    go(10, straightVelocity);
    instantStop();
    turn(0);
    delay(500);
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    go(-20, straightVelocity);
    turn(90);
    go(55, straightVelocity);
    turn(0);
    goUntilLineIsWhite(straightVelocity);
    stopMotors();
    while (true) {

    }
  }
  else if (roomNumber == '4') {
    turn(-90);
    goUntilLineIsWhite(straightVelocity);
    go(13, straightVelocity);
    turn(0);
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    go(-20, straightVelocity);
    turn(90);
    go(55, straightVelocity);
    turn(0);
    goUntilLineIsWhite(straightVelocity);
    stopMotors();
    while (true) {

    }
  }
  setMotors(50, 50);
  delay(500);
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  int initPos = distanceMeasure('r');
  while (distanceMeasure('r') - initPos < 40) {
    pidLineFollow();
  }
  stopMotors();
  while (true) {}
}
