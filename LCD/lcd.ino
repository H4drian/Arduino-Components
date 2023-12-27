#include <LiquidCrystal.h>

// Define pin numbers for LCD connections
#define VO 9    // LCD contrast control
#define D4 5    // LCD data line 4
#define D5 4    // LCD data line 5
#define D6 3    // LCD data line 6
#define D7 2    // LCD data line 7
#define RS 12   // LCD Register Select
#define RW 11   // LCD Read/Write
#define E 10    // LCD Enable

// Create a LiquidCrystal object with the specified connections
LiquidCrystal lcd(RS, RW, E, D4, D5, D6, D7);

void setup() {
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Set up the VO pin for controlling LCD contrast
  pinMode(VO, OUTPUT);
  analogWrite(VO, 95);  // Adjust the contrast (value can be adjusted based on your LCD and preference)
}

void loop() {
  // Set the cursor to the beginning of the first line
  lcd.setCursor(0, 0);

  // Print the message on the LCD
  lcd.print("Hello World!");

  // Wait for 3 seconds
  delay(3000);
}
