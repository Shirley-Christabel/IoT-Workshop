void setup() {
  Serial.begin(115200);
  }

void loop() {
  int ldr = analogRead(4);
  Serial.println("LDR: " + String(ldr));
  delay(1000);
  }
