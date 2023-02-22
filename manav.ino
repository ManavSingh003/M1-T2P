int inputPin = 2;
int led = 13;
bool MotionDetected = false;

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(inputPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(inputPin), handleMotionInterrupt, CHANGE);
}

void loop()
{
  delay(500);
}

void handleMotionInterrupt()
{
  MotionDetected = !MotionDetected;
  Serial.println("Motion Detected!");
  digitalWrite(LED_BUILTIN, MotionDetected);
  Serial.println("Interrupted");
}
