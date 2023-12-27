// Define pin numbers for each segment of the 7-segment display
#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5
#define PIN_E 6
#define PIN_F 7
#define PIN_G 8
#define PIN_DP 9

// Create a class for a 7-segment display
class SevenSegDisplay {

private:
  // Helper function to turn on a specific pin
  void pinOn(int pin) {
    digitalWrite(pin, HIGH);
  }

  // Helper function to turn off a specific pin
  void pinOff(int pin) {
    digitalWrite(pin, LOW);
  }

public:
  // Public variables for each segment pin
  int A;
  int B;
  int C;
  int D;
  int E;
  int F;
  int G;
  int DP;

  // Constructor to initialize the display pins
  SevenSegDisplay(int a, int b, int c, int d, int e, int f, int g, int dp) {
    A = a;
    B = b;
    C = c;
    D = d;
    E = e;
    F = f;
    G = g;
    DP = dp;

    // Set display pins as OUTPUT
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(DP, OUTPUT);
  }

  // Turn off all segments
  void off() {
    pinOff(A);
    pinOff(B);
    pinOff(C);
    pinOff(D);
    pinOff(E);
    pinOff(F);
    pinOff(G);
    pinOff(DP);
  }

  // Display a number on the 7-segment display
  void displayNum(int num) {
    off();

    switch (num) {
      // Cases for each digit
      case 0:
        pinOn(A);
        pinOn(B);
        pinOn(C);
        pinOn(D);
        pinOn(E);
        pinOn(F);
        break;
      case 1:
        pinOn(B);
        pinOn(C);
        break;
      // ... Cases for digits 2 through 9
      default:
        return;
    }
  }

  // Display a character on the 7-segment display
  void displayChar(char letter) {
    off();

    switch (letter) {
      // Cases for each character
      case 'A':
        pinOn(A);
        pinOn(B);
        pinOn(C);
        pinOn(E);
        pinOn(F);
        pinOn(G);
        break;
      // ... Cases for characters 'B' through 'F'
      default:
        return;
    }
  }

  // Turn on the decimal point
  void appendPeriod() {
    digitalWrite(DP, HIGH);
  }
};

// Array of characters to display on the 7-segment display
int displayChars[] = {'A', 'B', 'C', 'D', 'E', 'F'};
// Create a 7-segment display object
SevenSegDisplay display(PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DP);

// Setup function (runs once at the beginning)
void setup() {}

// Loop function (runs repeatedly)
void loop() {
  // Display numbers 0 through 9
  for(int i = 0; i <= 9; i++) {
    display.displayNum(i);
    delay(1000);
  }

  // Display characters 'A' through 'F'
  for(int i = 0; i <= 5; i++) {
    display.displayChar(displayChars[i]);
    delay(1000);
  }

  // Display character 'F' with the decimal point
  display.displayChar('F');
  display.appendPeriod();

  // Delay for 1 second
  delay(1000);
}
