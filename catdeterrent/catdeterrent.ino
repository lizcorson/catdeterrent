#define pirPin 2
#define ledPin 11
#define motorPin 3

long lastTriggerTime = 0;
int triggerDelay = 10000;
int sprayLength = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void LEDOnly() {
  digitalWrite(ledPin, 5);
  delay(sprayLength); 
  digitalWrite(ledPin, LOW);
}

void Spray() {
  digitalWrite(ledPin, 5);
  digitalWrite(motorPin, HIGH);
  Serial.println("Spray!"); 
  delay(sprayLength); 
  Serial.println("End spray!"); 
  digitalWrite(motorPin, LOW); 
  digitalWrite(ledPin, LOW);
  
}

void loop() {
  int pirVal = digitalRead(pirPin);
  digitalWrite(motorPin, LOW); //sometimes the motor gets stuck on, hope this will stop that
  if(pirVal == LOW){ //motion was detected
    Serial.println("Motion Detected"); 
    if ((unsigned long)(millis() - lastTriggerTime) > triggerDelay) {
      Spray();
      lastTriggerTime = millis();
    }
    else {
      LEDOnly();
    }
  }
}
