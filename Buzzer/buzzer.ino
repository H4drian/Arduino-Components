// Define pins and constants for the passive buzzer
#define PASSIVE_BUZZER_PIN 12
#define PULSE_WIDTH 1000
#define PULSE_COUNT 100

// Define pin and note for the active buzzer
#define ACTIVE_BUZZER_PIN 13
#define NOTE_C4 261

// Class for controlling a passive buzzer
class PassiveBuzzer {
public:
  int pin;
  int pulseWidth;
  int pulseCount;

  // Constructor for the PassiveBuzzer class
  PassiveBuzzer(int p, int pw, int pc) {
    pin = p;
    pulseWidth = pw;
    pulseCount = pc;

    // Set the pin mode to OUTPUT
    pinMode(pin, OUTPUT);
  }

  // Function to turn on the passive buzzer
  void on() {
    for(int i = 0; i < pulseCount; i++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(pulseWidth);
      digitalWrite(pin, LOW);
      delayMicroseconds(pulseWidth);
    }
  }
};

// Class for controlling an active buzzer
class ActiveBuzzer {
public:
  int pin;

  // Constructor for the ActiveBuzzer class
  ActiveBuzzer(int p) {
    pin = p;

    // Set the pin mode to OUTPUT
    pinMode(pin, OUTPUT);
  }

  // Function to turn on the active buzzer with optional duration
  void on(int freq, int dur = -1) {
    if(dur == -1) {
      tone(pin, freq);
    } else {
      tone(pin, freq, dur);
    }
  };

  // Function to turn off the active buzzer
  void off() {
    noTone(pin);  
  }
};

// Instantiate objects for passive and active buzzers
PassiveBuzzer passiveBuzzer(PASSIVE_BUZZER_PIN, PULSE_WIDTH, PULSE_COUNT);
ActiveBuzzer activeBuzzer(ACTIVE_BUZZER_PIN);

// Setup function (executed once)
void setup() {}

// Loop function (executed repeatedly)
void loop() {
  // Turn on the passive buzzer and wait for 500 milliseconds
  passiveBuzzer.on();
  delay(500);

  // Turn on the active buzzer with the C4 note
  activeBuzzer.on(NOTE_C4);
  // Turn off the active buzzer
  activeBuzzer.off();

  // Wait for 500 milliseconds
  delay(500);
  
  // Turn on the active buzzer with the C4 note and a duration of 1000 milliseconds
  activeBuzzer.on(NOTE_C4, 1000);

  // Wait for 500 milliseconds
  delay(500);
}
