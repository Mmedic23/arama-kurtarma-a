void findLine() {
    int sharpRead = sharpIR.distance();
    if (sharpRead > 80) {
      sharpRead = 80;
    }
    Serial.println(sharpRead);
    int dis = 2 * (42 - sharpRead); // THIS COEFFICIENT MUST BE TESTED THOROUGHLY
    setMotors(100 + dis, 100 - dis);
    delay(500);
}
