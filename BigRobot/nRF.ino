const uint64_t pipe1 = 0xE6E6E6E6E6E1;
const uint64_t pipe2 = 0xE6E6E6E6E6E3;

void initNRF() {
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(pipe2); // 00002
  radio.openReadingPipe(1, pipe1); // 00001
  radio.setPALevel(RF24_PA_MAX);
}

void readNRF() {
  radio.startListening();
  while (!radio.available()) {
    //Serial.println("Listening");
  }
  radio.read(&message, sizeof(message));
  //Serial.println(message);
}

void writeNRF(char a) {
  radio.stopListening();
  radio.write(&a, sizeof(a));
  delay(100);
}
