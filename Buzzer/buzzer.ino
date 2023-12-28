#define PASSIVE_BUZZER_PIN 12
#define PULSE_WIDTH 1000
#define PULSE_COUNT 100

#define ACTIVE_BUZZER_PIN 13
#define NOTE_C4 261

class PassiveBuzzer {
public:
  int pin;
  int pulseWidth;
  int pulseCount;

  PassiveBuzzer(int p, int pw, int pc) {
    pin = p;
    pulseWidth = pw;
    pulseCount = pc;

    pinMode(pin, OUTPUT);
  }

  void on() {
    for(int i = 0; i < pulseCount; i++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(pulseWidth);
      digitalWrite(pin, LOW);
      delayMicroseconds(pulseWidth);
    }
  }
};

class ActiveBuzzer {
public:
  int pin;

  ActiveBuzzer(int p) {
    pin = p;

    pinMode(pin, OUTPUT);
  }

  void on(int freq, int dur = -1) {
    if(dur == -1) {
      tone(pin, freq);
    } else {
      tone(pin, freq, dur);
    }
  };

  void off() {
    noTone(pin);  
  }
};

PassiveBuzzer passiveBuzzer(PASSIVE_BUZZER_PIN, PULSE_WIDTH, PULSE_COUNT);
ActiveBuzzer activeBuzzer(ACTIVE_BUZZER_PIN);

void setup() {}

void loop() {
  passiveBuzzer.on();
  delay(500);

  activeBuzzer.on(NOTE_C4);
  activeBuzzer.off();

  delay(500);
  
  activeBuzzer.on(NOTE_C4, 1000);

  delay(500);
}
