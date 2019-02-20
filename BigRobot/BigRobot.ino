#include <AFMotor.h>
#include <PID_v1.h>
#include <Encoder.h>
#include <digitalWriteFast.h> //Will increment speed of digital read/write and setting pinMode with using port manipulation for more info and download visit https://github.com/NicksonYap/digitalWriteFast/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

double encoderSetpoint = 0, encoderInput, encoderOutput;
int minVelocity = 20;
const int straightVelocity = 60;
byte qtrValues[] = {0, 0, 0, 0, 0, 0, 0, 0};
char message = 'x';
int idealDegree;

RF24 radio(4, 5); //// ORDER IS: CE, CSN
Encoder encoderLeft(20, 21);
Encoder encoderRight(18, 19);

void setup() {
  Serial.begin(9600);   // This value is for serial from usb
  Serial.println("You are connected to BigRobot");
  defineQTR();
  defineMotors();
  defineEncoderPID();
  initNRF();
}

void loop() {
  while (message == 'x') {
    writeNRF('r');
    delay(50);
    readNRF();
    Serial.println(message);
    delay(50);
  }
  rescue(message);
}
