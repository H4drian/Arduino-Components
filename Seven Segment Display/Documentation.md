# Seven Segment Displays
Seven Segment Displays are a kind of display consisting of, as the name implies, 7 different segments, often with the addition of a decimal point. Seven segment displays are good at displaying numeric data but often are much harder to understand when trying to display letters.

Most LED seven segment displays commonly used in electronics projects will have 10 pins, A-G for the segments, COM which is for ground, and DP for the decimal point. These 10 pins are split between the top and bottom 5. 

Top:    G, F, COM, A, B
Bottom: E, D, COM, C, DP

Here is which segment each pin connects to
![7-Segment Display Diagram](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/7_Segment_Display_with_Labeled_Segments.svg/800px-7_Segment_Display_with_Labeled_Segments.svg.png)

## Components
For this build you will only need 3 components

- Arduino
- 7-Seg Display
- Wires

## Connections
For the programm to correctly run as is you will need to connect the components above in a specific way, specified here.
| Component                  | Connection          |
| -------------------------- | ------------------- |
| Ultrasonic Sensor Pin VCC  | Arduino Pin 5V      |
| Ultrasonic Sensor Pin GND  | Arduino Pin GND     |
| Ultrasonic Sensor Pin TRIG | Arduino Pin 2       |
| Ultrasonic Sensor Pin ECHO | Arduino Pin 3       |
| LED Positive Pin           | Arduino Pin 13      |
| LED Negative Pin           | Arduino Pin GND     |
