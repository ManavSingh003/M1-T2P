// define the pins for the LED and the motion sensor
const int led = 13;
const int sensor = 2;
int state = LOW;             // by default, no motion detected
int val = 0; 

// define a flag variable to indicate motion detection
volatile bool motionDetected = false;

void setup() {
  pinMode(led, OUTPUT);    
  pinMode(sensor, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // do nothing in the loop - motion detection is handled by the interrupt
  check_motion();
}

void turn_led_on()
{
  digitalWrite(led, HIGH);
}

void turn_led_off()
{
  digitalWrite(led, LOW);
}

void check_motion()
{
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    turn_led_on() ;  // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
     turn_led_off();// turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}