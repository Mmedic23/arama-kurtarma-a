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
  unsigned int dis = sharpIR.distance();
  if (dis > 28) { //28 30 olarak güncellencek
    setMotors(200, 50);
  } else if (dis > 20) {
    setMotors(125, 125);
  } else {
    setMotors(80, 140);
  }
  delay(500);
  while (true) {
    pidLineFollow();
  }
}
