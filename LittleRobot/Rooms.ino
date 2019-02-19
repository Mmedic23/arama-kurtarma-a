void searchTheRooms() {
  Serial.println("START");
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  idealDegree = 0;
  Serial.println("REACHED ENTRY POINT");
  go(112, straightVelocity);
  instantStop();
  Serial.println("REACHED CENTRE");
  delay(500);
  turn(90);
  delay(500);
  goUntilLineIsWhite(straightVelocity);
  Serial.println("REACHED LINE BETWEEN FIRST TWO ROOMS");
  go(9,straightVelocity);
  instantStop();
  delay(500);
  turn(180);
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  Serial.println("REACHED FIRST ROOM ENTRY POINT");
  go(30, straightVelocity);
  instantStop();
  Serial.println("ENTERED FIRST ROOM");
  ldrAssignRoom(1);
  turn(0);
  goUntilLineIsWhite(straightVelocity);
  go(10,straightVelocity);
  Serial.println("REACHED SECOND ROOM ENTRY POINT");
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  go(30,straightVelocity);
  instantStop();
  Serial.println("ENTERED SECOND ROOM");
  ldrAssignRoom(2);
  turn(180);
  goUntilLineIsWhite(straightVelocity);
  initPos = distanceMeasure('r');
  while(distanceMeasure('r') < initPos + 40){
    pidLineFollow();
  }
  instantStop();
  Serial.println("REACHED MIDPOINT OF LINE BETWEEN SECOND SET OF ROOMS");
  delay(500);
  turn(270);
  goUntilLineIsWhite(straightVelocity);
  go(9,200);
  instantStop();
  delay(500);
  turn(180);
  delay(500);
  while (!isLineCompletelyWhite()) {
    pidLineFollow();
  }
  Serial.println("REACHED ENTRY POINT OF THIRD ROOM");
  go(30, straightVelocity);
  instantStop();
  Serial.println("ENTERED THIRD ROOM");
  ldrAssignRoom(3);
  turn(0);
  goUntilLineIsWhite(straightVelocity);
  initPos = distanceMeasure('r');
  while(distanceMeasure('r') < initPos + 40){
    pidLineFollow();
  }
  instantStop();
  delay(500);
  turn(90);
  delay(500);
  Serial.println("REACHED MIDPOINT OF LINE BETWEEN SECOND SET OF ROOMS");
  go(65, straightVelocity);
  instantStop();
  delay(500);
  turn(0);
  delay(500);
  goUntilLineIsWhite(straightVelocity);
  instantStop();                                                                                              
  findLine();
  
}



void ldrAssignRoom(int roomNumber) {
  double frequency = ldrAverage(3);
  roomFrequencies[roomNumber - 1] = frequency;
  Serial.print("Room ");
  Serial.print(roomNumber);
  Serial.print("'s frequency is set to: ");
  Serial.println(frequency);
}


//IT SHOULD READ FREQUENCY AND MATCH IT WITH CLOSEST FREQUENCY IT READ BEFORE
void whereAmI() {
  double currentFrequency = ldrAverage(3);
  if (abs(roomFrequencies[0] - currentFrequency) < 50) {
    roomNumber = 1;
  }
  else if (abs(roomFrequencies[1] - currentFrequency) < 50) {
    roomNumber = 2;
  }
  else if (abs(roomFrequencies[2] - currentFrequency) < 50) {
    roomNumber = 3;
  }
  else {
    roomNumber = 4;
  }
  Serial.print("Neredeyim ? ");
  Serial.println(roomNumber);
  char roomChar = char(roomNumber);
  writeNRF(roomChar);
}
