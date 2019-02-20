void homeComing() {
  if (roomNumber == 1) {
    turn(-90);
    go(65, straightVelocity);
    turn(0);
  }
  else if (roomNumber == 2) {
    turn(90);
    go(65, straightVelocity);
    turn(180);
  }
  else if (roomNumber == 3) {
    turn(90);
    go(65, straightVelocity);
    turn(0);
  }
  else if (roomNumber == 4) {
    turn(-90);
    go(65, straightVelocity);
    turn(180);
  }
  goUntilLineIsWhite(180);
  instantStop();
  delay(200);
  findLine();
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  initPos = distanceMeasure('r');
  while (distanceMeasure('r') < initPos + 40){
    pidLineFollow();
  } 
  instantStop();
  Serial.println("ez win");
}
