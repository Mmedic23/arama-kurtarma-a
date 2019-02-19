void rescueTesting(char roomNumber) {
  //There will be common moves
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  idealDegree = 0;
  go(115, 180);
  if (roomNumber == '1' || roomNumber == '2') {
    //There will be common moves for the room at the same side
    turn(90);
    goUntilLineIsWhite(100);
    go(8, 100);
    if (roomNumber == '1') {
      turn(180);
    }
    else { //roomNumber is 2
      turn(0);
    }
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    stopMotors();
    makeEncoderZero();
    delay(2000);
    go(-20,100);
    writeNRF('r');
    if (roomNumber == '1') {
      turn(270);
    }
    else { //roomNumber is 2
      turn(270);
    }
    makeEncoderZero();
    go(65, 100);
    makeEncoderZero();
    turn(0);
  }
  else if (roomNumber == '3' || roomNumber == '4') {
    turn(-90);
    goUntilLineIsWhite(100);
    go(8, 100);
    if (roomNumber == '3') {
      turn(90);
    }
    else { //roomNumber is 4
      turn(-90);
    }
    while (!isLineCompletelyWhite()) {
      pidLineFollow();
    }
    stopMotors();
    makeEncoderZero();
    delay(2000);
    go(-20,100);
    writeNRF('r');
    if (roomNumber == '3') {
      turn(90);
    }
    else { //roomNumber is 4
      turn(-90);
    }
    go(65, 150);
    turn(-90);
  }
  makeEncoderZero();
  goUntilLineIsWhite(100);
  go(5, 100);
  while (isLineCompletelyWhite()) {
    pidLineFollow();
  }
  go(10, 150);
  goUntilLineIsWhite(100);
}
