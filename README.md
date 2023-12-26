# Ultrasonic-Sensor
A simple circuit used to detect its distance from an object.
![Circuit Schematics](https://cdn.discordapp.com/attachments/880259593199034378/1189132416644816977/image.png?ex=659d0cdd&is=658a97dd&hm=680c143ae1b9a331947d473e35f9dc9cec45f276244f720d392b986855b67fe9&)

## Components
To create this circuit you will need 5 components

- Wires
- Resistors (Optional)
- Ultrasonic Sensor (4 Pin HC-SR04 Type)
- LED
- Arduino

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


Optionally add a resistor within the LED's circuit to limit brightness.
