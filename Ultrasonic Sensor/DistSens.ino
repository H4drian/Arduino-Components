// Define macros for later use
#define TRIG_PIN 2
#define MIN_TRIGGER_DISTANCE 15
#define ECHO_PIN 3
#define LED_PIN 13
#define BAUDRATE 9600

// LED Component Class
class LED {
  public:
    int pin;

    // Constructor for LED class
    LED(int pinNum) {
      pin = pinNum;
      pinMode(pin, OUTPUT);
    }

    // Turn the LED on
    void on() {
      digitalWrite(pin, HIGH);
    }

    // Turn the LED off
    void off() {
      digitalWrite(pin, LOW);
    }
};

// Sensor Component Class
class UltrasonicSensor {
  public:
    int trigPin;
    int echoPin;

    // Constructor for UltrasonicSensor class
    UltrasonicSensor(int tp, int ep) {
      trigPin = tp;
      echoPin = ep;

      // Set pin modes for trigger and echo pins
      pinMode(echoPin, INPUT);
      pinMode(trigPin, OUTPUT);
    }

    // Trigger the ultrasonic sensor transmitter
    void trigger() {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
    }

    // Get the duration of the ultrasonic pulse
    long getDuration() {
      return pulseIn(echoPin, HIGH);
    }

    // Calculate and return the distance based on the pulse duration
    float getDistance() {
      return pulseIn(echoPin, HIGH) * 0.0343 / 2;
    }
};

// Set up objects for each component
LED alarm(LED_PIN);
UltrasonicSensor sensor(TRIG_PIN, ECHO_PIN);

// Setup function
void setup() {
  Serial.begin(BAUDRATE);
}

// Main loop
void loop() {
  sensor.trigger(); // Trigger the sensor transmitter
  float distance = sensor.getDistance(); // Get distance from sensor receiver

  // Display results
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(" cm");

  // Check if there is an object within the minimum trigger distance
  if(distance < MIN_TRIGGER_DISTANCE){
    alarm.on(); // Turn on the alarm
  } else {
    alarm.off(); // Turn off the alarm
  }

  delay(500); // Delay for stability
}
