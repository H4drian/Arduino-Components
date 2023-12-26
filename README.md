# Ultrasonic-Sensor
A simple circuit used to detect its distance from an object.

## How do Ultrasonic Sensors Work & Pseudocode
Ultrasonic Sensors are a common component in many electronics projects. Ultrasonic sensors are able to guage the distance of an object but fall short in terms of recognizing objects.

Ultrasonic Sensors operate alot like bats and other animals do with echolocation. The sensors will send out a high frequency "ping" and then wait for the "echo" to come back. Since the speed of sound on is the same in most applications we can take the amount of time elapsed between the sent ping and the received echo to get the distance of whatever object it sense.

With this knowledge we can piece together what we should do with our code

1. Trigger the sensor to send out a ping
2. Receive the echo and calculate the durration between the ping and echo
3. Take the durration and calculate the distance
4. Display information as needed

Here is the pseudocode based on the constraints above.
```
// Define constants for later use, exact values can vary
TRIG_PIN
MIN_TRIGGER_DISTANCE
ECHO_PIN
LED_PIN 
BAUDRATE

// Define LED Component Class
class LED:
    pin
    
    // Constructor for LED class
    LED(pinNum):
        pin = pinNum
        set pinMode(pin, OUTPUT)

    // Turn the LED on
    on():
        set digitalWrite(pin, HIGH)

    // Turn the LED off
    off():
        set digitalWrite(pin, LOW)

// Define Sensor Component Class
class UltrasonicSensor:
    trigPin
    echoPin

    // Constructor for UltrasonicSensor class
    UltrasonicSensor(tp, ep):
        trigPin = tp
        echoPin = ep

        // Set pin modes for trigger and echo pins
        set pinMode(echoPin, INPUT)
        set pinMode(trigPin, OUTPUT)

    // Trigger the ultrasonic sensor transmitter
    trigger():
        set digitalWrite(trigPin, LOW)
        delayMicroseconds(2)
        set digitalWrite(trigPin, HIGH)
        delayMicroseconds(10)
        set digitalWrite(trigPin, LOW)

    // Get the duration of the ultrasonic pulse
    getDuration():
        return pulseIn(echoPin, HIGH)

    // Calculate and return the distance based on the pulse duration
    getDistance():
        return pulseIn(echoPin, HIGH) * 0.0343 / 2

// Set up objects for each component
alarm = new LED(LED_PIN)
sensor = new UltrasonicSensor(TRIG_PIN, ECHO_PIN)

// Setup function
setup():
    Serial.begin(BAUDRATE) // Set data transfer rate between your computer and the Arduino

// Main loop
loop():
    // Trigger the sensor transmitter
    sensor.trigger()
    // Get distance from sensor receiver
    distance = sensor.getDistance()

    // Display results
    Serial.print("Distance: ")
    Serial.println(distance)
    Serial.println(" cm")

    // Check if there is an object within the minimum trigger distance
    if distance < MIN_TRIGGER_DISTANCE:
        // Turn on the alarm
        alarm.on()
    else:
        // Turn off the alarm
        alarm.off()

    // Delay for stability
    delay(500)
```

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

Here is an overview of the circuitry that goes into this project:
![Circuit Schematics](https://cdn.discordapp.com/attachments/880259593199034378/1189132416644816977/image.png?ex=659d0cdd&is=658a97dd&hm=680c143ae1b9a331947d473e35f9dc9cec45f276244f720d392b986855b67fe9&)
