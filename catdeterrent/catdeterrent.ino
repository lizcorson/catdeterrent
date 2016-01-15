#define pirPin 2
#define ledPin 11

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    int pirVal = digitalRead(pirPin);

  if(pirVal == LOW){ //was motion detected
    Serial.println("Motion Detected"); 
    digitalWrite(ledPin, 5);
    delay(2000); 
    digitalWrite(ledPin, LOW);
  }

}
