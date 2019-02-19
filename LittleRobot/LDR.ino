#define ldrPin A8

//  METHODS IN HERE
//  defineLdr
//  ldrTest
//  ldrDuration
int ldrInitial = 0; // Using the digital out of the LDR module means we get 0 or 1 as a read from the LDR
long start = 0;
long duration = 0;


void defineLdr() {
  pinMode(ldrPin, INPUT);
}

// Method for testing output of LDR and related components. (Content is volatile and is modified according to needs.)
void ldrTest() {
  Serial.println(ldrDuration());
}

double ldrAverage(int count) {
  double sum = 0;
  for (int i = 0; i < count; i++) {
    sum += ldrDuration();
  }
  return (sum / count);
}
// Returns the flashing light's PERIOD (how long the light stays on/of) in milliseconds.
// The error hasn't exceeded 5 ms in testing but more testing and calibration is necessary with more realistic conditions. (i.e. in a replica parkour)
float ldrDuration() {
  ldrInitial = 0; // Using the digital out of the LDR module means we get 0 or 1 as a read from the LDR
  start = 0;
  duration = 0;

  ldrInitial = analogRead(ldrPin); // First, we read the initial state of the lights.

  // Then, we wait until the initial state changes
  while (abs(ldrInitial - analogRead(ldrPin)) < 200) {
    delay(10);
  }

  // When the state changes, we mark the beginning of the cycle using the current time.
  start = millis();
  // Then, we wait until the state changes again, back to the initial state.
  while (abs(ldrInitial - analogRead(ldrPin)) >= 200) {
    delay(10);
  }
  // When it does, we calculate the duration the light was stable in one state, by subtracting the beginning time from the current time.
  duration = millis() - start;
  return duration;
}
