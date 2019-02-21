
const double perimeterOfWheel = 4.687 * PI;
const double shaftConstant = 297.92;
const int magneticPoles = 12;
double encoderKp = 25, encoderKi = 0, encoderKd = 0;
const double step2cmConstant = perimeterOfWheel / (shaftConstant * magneticPoles);

PID encoderPID(&encoderInput, &encoderOutput, &encoderSetpoint, encoderKp, encoderKi, encoderKd, DIRECT);

void go(int dist, int velocity) {
  initPos = distanceMeasure('r');
  if (distanceMeasure('r') < initPos + dist) {
    encoderSetpoint = -idealDegree;
    while (distanceMeasure('r') < initPos + dist) {
      encoderInput = -getHeading();
      //Serial.print("Going forwards");
      //Serial.print(encoderInput);
      //Serial.print("    ");
      //Serial.println(encoderRight.read());
      encoderPID.Compute();
      setMotors(velocity + encoderOutput, velocity - encoderOutput);
      //Serial.println(encoderOutput);
    }
  }
  else {
    encoderSetpoint = idealDegree;
    while (distanceMeasure('r') > initPos + dist) {
      encoderInput = getHeading();
      //Serial.print("Going backwards");
      //Serial.print(encoderInput);
      //Serial.print("   ");
      //Serial.println(encoderRight.read());
      encoderPID.Compute();
      setMotors(-(velocity + encoderOutput), -(velocity - encoderOutput));
      //Serial.println(encoderOutput);
    }
    setMotors(255,255);
    delay(20);
    stopMotors();
  }
}
void goUntilLineIsWhite(int velocity) {
  encoderSetpoint = - idealDegree;
  while (!isOnWhiteLine()) {
    encoderInput = -getHeading();
    //Serial.println(encoderInput);
    //Serial.println(encoderRight.read());
    encoderPID.Compute();
    setMotors(velocity + encoderOutput, velocity - encoderOutput);
    //Serial.println(encoderInput);
    //Serial.println(encoderOutput);
  }
}

const double distanceBetweenWheels = 13;

void turn(int degree) {
  double initDegree = getHeading();
  if (degree > initDegree) {
    while (degree > getHeading()) {
      setMotors(-(minVelocity + int(3 * (degree - getHeading()))), +(minVelocity + int(3 * (degree - getHeading()))));
    }
    setMotors(155, -155);
    delay(25);
    stopMotors();
  }

  else {
    while (getHeading() > degree) {
      setMotors(+(minVelocity - int(3 * (degree - getHeading()))), -(minVelocity - int(3 * (degree - getHeading()))));
    }
    setMotors(-155, 155);
    delay(25);
    stopMotors();
  }
  idealDegree = degree;
}

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
  //-100, +100
  encoderPID.SetMode(AUTOMATIC);
  encoderPID.SetOutputLimits(-255, 255);
}

double getHeading() {
  return ((((distanceMeasure('r') - distanceMeasure('l'))) * 180) / ((distanceBetweenWheels) * PI)) ;
}
