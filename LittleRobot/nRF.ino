const uint64_t pipe1 = 0xE6E6E6E6E6E1;
const uint64_t pipe2 = 0xE6E6E6E6E6E3;

void initNRF() {
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(pipe1); // 00002
  radio.openReadingPipe(1, pipe2); // 00001
  radio.setPALevel(RF24_PA_MAX);
}

void readNRF() {
  radio.startListening();
  //while (!radio.available()) {
  //  Serial.println(radio.available());
  //}
  radio.read(&message, sizeof(message));
  //Serial.print(message);
  //Serial.println(" from readNRF()");
}

void writeNRF(char message) {
  radio.stopListening();
  radio.write(&message, sizeof(message));
  delay(50);
}
