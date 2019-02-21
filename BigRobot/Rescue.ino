
void rescue(char roomNumber) {
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  idealDegree = 0;
  makeEncoderZero();
  go(115, straightVelocity);
  instantStop();
  delay(500);
  if (roomNumber == '1') {
    turn(90); // SAME BETWEEN
    delay(500);
    goUntilLineIsWhite(straightVelocity);
    go(11, straightVelocity);
    instantStop();
    delay(500);
    turn(180); // DIFFERENCE BETWEEN
    delay(500);
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    go(-15, straightVelocity);
    stopMotors();
    delay(500);
    turn(270); // SAME EXCEPT DIRECTION
    stopMotors();
    delay(500);
    go(65, straightVelocity);
    instantStop();
    for (int i = 0; i < 30; i++) {
      writeNRF('s');
    }
    delay(500);
    turn(360); // SAME EXCEPT DIRECTION
    delay(500);
    goUntilLineIsWhite(straightVelocity);
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
    for (int i = 0; i < 30; i++) {
      writeNRF('s');
    }
    delay(500);
    turn(0);
    delay(500);
    goUntilLineIsWhite(straightVelocity);
  }
  else if (roomNumber == '3') {
    turn(-90); ///
    delay(500);
    goUntilLineIsWhite(straightVelocity);
    go(11, straightVelocity);
    instantStop();
    delay(500);
    turn(-180); ///
    delay(500);
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    go(-15, straightVelocity);
    stopMotors();
    delay(500);
    turn(-270); ///
    stopMotors();
    delay(500);
    go(65, straightVelocity);
    instantStop();
    for (int i = 0; i < 30; i++) {
      writeNRF('s');
    }
    delay(500);
    turn(-360);
    delay(500);
    goUntilLineIsWhite(straightVelocity);
  }
  else if (roomNumber == '4') {
    turn(-90); ///
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
    turn(90); ///
    stopMotors();
    delay(500);
    go(65, straightVelocity);
    instantStop();
    for (int i = 0; i < 30; i++) {
      writeNRF('s');
    }
    delay(500);
    turn(0);
    delay(500);
    goUntilLineIsWhite(straightVelocity);
  }
  stopMotors();
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
