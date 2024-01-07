// Define the pins for I2C communication
#define SDA A4
#define SCL A5

// Define the I2C address for the LCD. This value varies depending on the specific LCD so use an I2C address finder to find yours
#define I2C_ADDR 0x27 

// Include necessary libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with the I2C address and dimensions
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();
  
  // Turn on the backlight of the LCD
  lcd.backlight();
}

void loop() {
  // Clear the LCD display
  lcd.clear();
  
  // Set the cursor to the top-left corner of the LCD
  lcd.setCursor(0, 0);
  
  // Print the message "Hello World!" on the LCD
  lcd.print("Hello World!");

  // Wait for 500 milliseconds
  delay(500);
}
