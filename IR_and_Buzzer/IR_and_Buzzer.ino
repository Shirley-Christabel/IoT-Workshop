#define ir 5
#define buzzer 6
int x=0;

void out(){
  digitalWrite(buzzer,HIGH);
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(ir,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(ir);
  if(x=0){
    out();
    }
   else if(x>0){
      digitalWrite(buzzer,LOW);
      }
    Serial.println(digitalRead(3));
    delay(100);
    }
