# Liquid Crystal Displays
Liquid Crystal Displays (LCDs) are an important part in any electronic engineer's toolkit. LCDs are good at conveying information with very little energy consumption and using simple code but fall short in terms of aesthetic and color.

## Components
For this build you are going to need 4 components.

- LCD display
- Arduino
- Wires
- Resistors (Dependent on LCD display)

## Connections
For the code to work without modification the following connections will have to be made

| Component    | Connection      |
|--------------|-----------------|
| LCD VCC      | Arduino 5V      |
| LCD GND      | Arduino GND     |
| LCD VO       | Arduino ~9      |
| LCD RS       | Arduino 12      |
| LCD RW       | Arduino ~11     |
| LCD E        | Arduino ~10     |
| LCD D4       | Arduino ~5      |
| LCD D5       | Arduino 4       |
| LCD D6       | Arduino ~3      |
| LCD D7       | Arduino ~2      |
| LCD A (Anode)| Arduino 5V      |
| LCD K (Cathode)| Arduino GND    |

Here is an overview of the circuitry
![image](https://github.com/H4drian/Arduino-Components/assets/117495728/df509856-f85f-4f7f-820d-2fd60d3df891)
