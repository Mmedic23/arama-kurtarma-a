void homeComing() {
  go(-30,150);
  if (roomNumber == 1 || roomNumber == 2) {
    if (roomNumber == 1) {
      turn(-90);
    }
    else {
      turn(90);
    }
    go(65, 150);
    turn(90);
  }
  else if (roomNumber == 3 || roomNumber == 3) {
    if (roomNumber == 3) {
      turn(90);
    }
    else {
      turn(-90);
    }
    go(65, 150);
    turn(-90);
  }
  while (!isLineCompletelyWhite()) {
    setMotors(150, 150);
  }
  delay(300);
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
}
