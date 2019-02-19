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
int roomNumber;
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
  //qtrTest();
  /*
    initNRFWrite();
    searchForDoor();
    whereAmI();
    initNRFRead();
    readNRF();
    stopMotors();
    while (message != 'r') {
    readNRF();
    }
    goToDoor();
    homeComing();
  */
}
