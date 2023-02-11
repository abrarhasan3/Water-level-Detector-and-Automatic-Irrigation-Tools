#define tp 2
#define ep 3

int duration;
int distance;
int parity = 0;

void setup() {
  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  int sensorValue;  
  digitalWrite(tp,LOW);
  delayMicroseconds(5);
  digitalWrite(tp,HIGH);
  delayMicroseconds(10);
  duration = pulseIn(ep,HIGH);
  distance = 0.017*duration;
  Serial.print("SENSOR : ");
  Serial.println(distance);
  if(distance>4)
  {
     digitalWrite(4, HIGH);    
  }
  else
  {
    digitalWrite(4, LOW);    
  }
  sensorValue = analogRead(A0); 
  Serial.println("Analog Value : ");
  Serial.println(sensorValue);
  if(sensorValue<450)
  {
    digitalWrite(5,LOW);     
  }
  if(sensorValue>500)
  {
    digitalWrite(5,HIGH);    
  }
  delay(500);
}
