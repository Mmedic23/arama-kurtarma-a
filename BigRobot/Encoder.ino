
const double perimeterOfWheel = 4.687 * PI;
const double shaftConstant = 297.92;
const int magneticPoles = 6;
double encoderKp = 2, encoderKi = 0.1, encoderKd = 0;
const double step2cmConstant = perimeterOfWheel / (shaftConstant * magneticPoles);
int encoderError = 0;

PID encoderPID(&encoderInput, &encoderOutput, &encoderSetpoint, encoderKp, encoderKi, encoderKd, DIRECT);

double distanceMeasure(char wheel) {
  double distanceTravelled;
  if (wheel == 'l') {
    distanceTravelled = encoderLeft.read() * step2cmConstant;
  }
  else if (wheel == 'r') {
    distanceTravelled = encoderRight.read() * step2cmConstant;
  }
  return distanceTravelled;
}



void go(int distance, int velocity) {
  //encoderInput = 0;
  //encoderOutput = 0;
  double initPos = distanceMeasure('r');
  if (distanceMeasure('r') < initPos + distance) {
    encoderSetpoint = - idealDegree;
    while (distanceMeasure('r') < initPos + distance) {
      encoderInput = -getHeading();
      //Serial.println(encoderInput);
      //Serial.println(encoderRight.read());
      encoderPID.Compute();
      setMotors(velocity + encoderOutput, velocity - encoderOutput);
      //Serial.println(encoderOutput);
    }
  }
  else {
    encoderSetpoint = idealDegree;
    while (distanceMeasure('r') > initPos + distance) {
      encoderInput = getHeading();
      //Serial.println(encoderInput);
      //Serial.println(encoderRight.read());
      encoderPID.Compute();
      setMotors(-(velocity + encoderOutput), -(velocity - encoderOutput));
      //Serial.println(encoderOutput);
    }
  }
}

void goUntilLineIsWhite(int velocity) {
  //encoderInput = 0;
  //encoderOutput = 0;
  encoderSetpoint = - idealDegree;
  while (!isOnWhiteLine()) {
    encoderInput = -getHeading();
    //Serial.println(encoderInput);
    //Serial.println(encoderRight.read());
    encoderPID.Compute();
    setMotors(velocity + encoderOutput, velocity * 1.05 - encoderOutput);
    //Serial.println(encoderOutput);
  }

}

const double distanceBetweenWheels = 18.78;

void turn(int degree) {
  double initDegree = getHeading();
  if (degree > initDegree) {
    while (degree > getHeading()) {
      setMotors(-(minVelocity + int(0.4 * (degree - getHeading()))), +(minVelocity + int(0.4 * (degree - getHeading()))));
    }
    //setMotors(255, -255);
    //delay(25);
    stopMotors();
  }

  else {
    while (getHeading() > degree) {
      setMotors(-(-minVelocity + (int)(0.4 * (degree - getHeading()))), (-minVelocity + int(0.4 * (degree - getHeading()))));
    }
    //setMotors(-255, 255);
    //delay(25);
    stopMotors();
  }
  idealDegree = degree;
}

void makeEncoderZero() {
  encoderLeft.write(0);
  encoderRight.write(0);
}

void encoderTest() {
  Serial.print(distanceMeasure('l'));
  Serial.print("***");
  Serial.println(distanceMeasure('r'));
}

void defineEncoderPID() {
  encoderInput = ((encoderLeft.read() - encoderRight.read()) / (shaftConstant * magneticPoles));
  encoderSetpoint = 0;
  encoderPID.SetOutputLimits(-255, 255);
  encoderPID.SetMode(AUTOMATIC);
}
double getEncoderInput() {
  return encoderInput;
}

int getHeading() {
  return int(((distanceMeasure('r') - distanceMeasure('l')) / 2) * 180) / ((distanceBetweenWheels / 2) * PI);
}
