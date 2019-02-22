void homeComing() {
  if (roomNumber == '1') {
    turn(-90);
    delay(500);
    go(65, straightVelocity);
    instantStop();
    delay(500);
    turn(0);
    delay(500);
  }
  else if (roomNumber == '2') {
    turn(-270);
    delay(500);
    go(65, straightVelocity);
    instantStop();
    delay(500);
    turn(-180);
    delay(500);
  }
  else if (roomNumber == '3') {
    turn(-270);
    delay(500);
    go(65, straightVelocity);
    instantStop();
    delay(500);
    turn(-360);
    delay(500);
  }
  else if (roomNumber == '4') {
    turn(-90);
    delay(500);
    go(65, straightVelocity);
    instantStop();
    delay(500);
    turn(-180);
    delay(500);
  }
  goUntilLineIsWhite(straightVelocity);
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
  //Serial.println("ez win");
}
