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
| 7SD A                      | Arduino Pin 2       |
| 7SD B                      | Arduino Pin ~3      |
| 7SD C                      | Arduino Pin 4       |
| 7SD D                      | Arduino Pin ~5      |
| 7SD E                      | Arduino Pin ~6      |
| 7SD F                      | Arduino Pin 7       |
| 7SD G                      | Arduino Pin 8       |
| 7SD DP                     | Arduino Pin ~9      |
| 7SD COM (Both COM pins)    | Arduino Pin GND     |


Here is an overview of the circuitry that goes into this project:
![Circuit Schematics](https://github.com/H4drian/Arduino-Components/assets/117495728/017e94a7-aa61-4b8a-9d79-29de70d8fc16)
