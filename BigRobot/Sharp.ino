void findLine() {  // THIS METHOD'S CM VALUES MUST BE MEASURED IN METU
  int sharpRead = sharpIR.distance();
  if (sharpRead > 42) {
    sharpRead = 42;
  }
  Serial.println(sharpRead);
  int dis = 7 * (20 - sharpRead); // THIS COEFFICIENT MUST BE TESTED THOROUGHLY
  setMotors(150 + dis, 150 - dis);
  delay(500);
  while (!isOnWhiteLine()) {}
}
