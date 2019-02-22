#define sharpPinBack  46
#define sharpPinFront 47
#define sharpPinLeft  45


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


boolean isNextToWall () {
  return !digitalReadFast(sharpPinLeft);
}


boolean isFacingDoor() {
  return digitalReadFast(sharpPinFront);
}

boolean isBackAvailable() {
  return (digitalReadFast(sharpPinBack));
}

void findLine() {
  if (isNextToWall()) {
    setMotors(255, 60);
    delay(500);
  }
  else {
    int sharpRead = sharpIR.distance();
    if (sharpRead > 42) {
      sharpRead = 42;
    }
    Serial.println(sharpRead);
    int dis = 5 * (21 - sharpRead); // THIS COEFFICIENT MUST BE TESTED THOROUGHLY
    setMotors(150 + dis, 150 - dis);
    delay(500);
  }
}

void sharpTest() {
  Serial.print("Back is ");
  Serial.print(isBackAvailable() ? "available" : "NOT available");
  Serial.print(" || ANALOG Left is ");
  Serial.print(isLeftAvailable() ? "available" : "NOT available");
  Serial.print(" || DIGITAL Left is ");
  Serial.print(isNextToWall() ? "next to wall" : "NOT next to wall");
  Serial.print(" || Facing door? ");
  Serial.println(isFacingDoor() ? "True" : "False");
}
