#define trig 4
#define echo 5

void setup() {
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

long duration = pulseIn(echo,HIGH);
int distance = 0.034*duration/2;
Serial.println("Distance : "+String(distance)+"cm");
}
