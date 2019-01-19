#define LED 13
#define BLINKDELAY 500
void setup() {
  pinMode(LED, OUTPUT);
  
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(BLINKDELAY);
  digitalWrite(LED, LOW);
  delay(BLINKDELAY);
}
