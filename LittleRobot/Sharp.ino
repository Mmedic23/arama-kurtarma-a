#define sharpPinBack  46
#define sharpPinFront 47



//It should check sides is far away from sharp sensors and if all of them is avaible should returns true else returns false
boolean isLeftAvailable() {
  unsigned int dis = sharpIR.distance();
  if (dis > 10) {
    return true;
  }
  else {
    return false;
  }
}

boolean isFacingDoor() {
  return digitalRead(sharpPinFront);
}

boolean isBackAvailable() {
  return (digitalReadFast(sharpPinBack));
}

void findLine() {
  int dis = 5 * (21 - sharpIR.distance());
  setMotors(100 + dis, 100 - dis);
  delay(500);
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
}
