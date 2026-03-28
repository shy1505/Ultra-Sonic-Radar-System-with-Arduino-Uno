#include <Servo.h>

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int SERVO_PIN = 11;

const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;
const int STEP_DELAY = 25;       // Servo stabilization delay (ms)
const int NUM_SAMPLES = 5;       // Number of samples for averaging
const int MAX_DISTANCE = 400;    // Maximum measurable distance (cm)

Servo radarServo;
long duration = 0;
void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  radarServo.attach(SERVO_PIN);
  radarServo.write(90);  // Start from center

  delay(1000); // Stabilization time
}
void loop() {
  scanForward();
  scanBackward();
}
void scanForward() {
  for (int angle = MIN_ANGLE; angle <= MAX_ANGLE; angle++) {
    processAngle(angle);
  }
}

void scanBackward() {
  for (int angle = MAX_ANGLE; angle >= MIN_ANGLE; angle--) {
    processAngle(angle);
  }
}

void processAngle(int angle) {
  radarServo.write(angle);
  delay(STEP_DELAY);

  int distance = getFilteredDistance();
  sendData(angle, distance);
}

int measureDistance() {
  // Ensure clean LOW signal
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send trigger pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse (with timeout)
  duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30 ms timeout

  // If no echo received
  if (duration == 0) {
    return MAX_DISTANCE;
  }

  int distance = duration * 0.034 / 2;

  // Clamp values
  if (distance > MAX_DISTANCE) distance = MAX_DISTANCE;
  if (distance < 2) distance = 2;

  return distance;
}

int getFilteredDistance() {
  int sum = 0;

  for (int i = 0; i < NUM_SAMPLES; i++) {
    sum += measureDistance();
    delay(5);
  }

  return sum / NUM_SAMPLES;
}

void sendData(int angle, int distance) {
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
}
