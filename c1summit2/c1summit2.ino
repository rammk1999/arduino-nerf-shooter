#include <Servo.h>

#define SOLENOID 2
#define PUMP 9
#define BUTTON 12
#define JOYX A0
#define JOYY A1
#define SERV1 3 
#define SERV2 5
#define SERV3 6
#define LIGHT A2
#define TEMP A3

Servo azimuth;
Servo elevation;

// center (516, 516)

void setup() {
  Serial.begin(115200);
  Serial.println("Ready Aim FIRE");

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(PUMP, OUTPUT);
  pinMode(SOLENOID, OUTPUT);
  digitalWrite(SOLENOID, LOW);

  digitalWrite(PUMP,HIGH);
  delay(5000);
  digitalWrite(PUMP,LOW);

  azimuth.attach(SERV1);
  azimuth.attach(SERV2);
  azimuth.write(80);
  elevation.write(3);
  
}

int lastx, lasty;

void loop() {
  if (!digitalRead(BUTTON)) {
    Serial.println("FIRE!");
    digitalWrite(SOLENOID, HIGH);
    delay(500);
    digitalWrite(SOLENOID, LOW);
    digitalWrite(PUMP, HIGH);
    delay(5000);
    digitalWrite(PUMP, LOW);
  }
  
  int xRead = analogRead(JOYX);
  int yRead = analogRead(JOYY);
  if (abs(lastx-xRead) > 2) {
    if (xRead < 516) {
      azimuth.write(map(xRead,516, 0, 90, 2));
    }
    else {
      if (xRead > 415) {
        azimuth.write(map(xRead, 415, 0, 91, 178));
        }
    }
  }
  lastx = xRead;

  if(abs(lasty - yRead)>2) {
    if(yRead < 515) {
      elevation.write(map(yRead, 515, 0, 90, 2));
    }
    else {
      if (yRead > 480) {
        azimuth.write(map(yRead, 480, 0, 90, 178));
      }
    }
  }
  lasty = yRead;
}
