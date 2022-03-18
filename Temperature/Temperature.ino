void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = analogRead(A0);
  float volt = temp*(0.0048828125);
  float milivolt = volt*1000;
  float degree = milivolt/10;
  Serial.println(degree);
  delay(100);
}
