### **Code Files**

#### **Main Code File: `bluetooth_motor_control.ino`**

```cpp
#include <AFMotor.h>
#include <NewPing.h>
#include <SoftwareSerial.h>

#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200  // Maximum distance for ultrasonic sensor

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
SoftwareSerial mySerial(10, 9);  // RX, TX for Bluetooth

AF_DCMotor motor1(1);  // Motor 1 on Adafruit Motor Shield
AF_DCMotor motor2(2);  // Motor 2 on Adafruit Motor Shield

bool obstruction = false;
int distance = 0;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  motor1.setSpeed(200);  // Set initial speed
  motor2.setSpeed(200);

  sendCommand("AT");  // Initialize Bluetooth
  sendCommand("AT+NAMEYourName");
  sendCommand("AT+ROLE0");  // Set as slave
}

void loop() {
  char command = readBluetoothCommand();
  distance = sonar.ping_cm();

  if (distance > 10 || distance == 0) {
    obstruction = false;
  } else {
    obstruction = true;
  }

  if (!obstruction) {
    if (command == 'f') {
      moveForward();
    } else if (command == 'b') {
      moveBackward();
    } else if (command == 's') {
      stopMotors();
    }
  } else {
    stopMotors();
  }

  delay(500);
}

void sendCommand(const char* command) {
  mySerial.println(command);
  delay(500);
}

char readBluetoothCommand() {
  if (mySerial.available()) {
    return mySerial.read();
  }
  return '\0';
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}