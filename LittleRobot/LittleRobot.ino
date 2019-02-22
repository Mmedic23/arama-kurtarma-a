#include <SharpIR.h>
#include <PID_v1.h>
#include <Encoder.h>
#include <digitalWriteFast.h> //Will increment speed of digital read/write and setting pinMode with using port manipulation for more info and download visit https://github.com/NicksonYap/digitalWriteFast/
#include <SPI.h>
#include <nRF24L01.h>         // NRF LIBRARY
#include <RF24.h>

double encoderSetpoint = 0, encoderInput, encoderOutput;
byte qtrValues[] = {0, 0, 0, 0, 0, 0, 0, 0};
float roomFrequencies[] = {0, 0, 0};
char roomNumber;
char message = ' ';
int minVelocity = 25;
const int straightVelocity = 200;
int idealDegree;
double initPos;

RF24 radio(48, 49); // CE, CSN
Encoder encoderLeft(20, 21);
Encoder encoderRight(18, 19);
SharpIR sharpIR(A7, 1080);


void setup() {
  Serial.begin(9600);
  Serial.println("You are connected to LittleRobot");
  defineQTR();
  defineLdr();
  defineEncoderPID();
  defineMotors();
  initNRF();
  //radio.startListening();
}
void loop() {
  searchTheRooms();
  while (message != 'r') {
    readNRF();
  }
  //Serial.print(message);
  //Serial.println(" from main loop. Exited first while loop.");
  char currentRoom = whereAmI();
  while (message != 's') {
    //Serial.print("Basıyom");
    writeNRF(currentRoom);
    delay(50);
    readNRF();
    delay(50);
  }
  makeEncoderZero();
  idealDegree = 0;
  searchForDoor();
  idealDegree = 0;
  makeEncoderZero();
  homeComing();
}
