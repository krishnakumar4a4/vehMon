int relayIn = 10;
int n=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayIn, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(n==1) {
    digitalWrite(relayIn, HIGH);
    Serial.println("*******************Pin mode is  HIGH *******************");
    n++;
  }
  if(Serial.available()) {
    String isRaspOn = Serial.readString();
    Serial.println("Shutting down power, Raspberry is already down");
    if(isRaspOn == "PowerDown") {
      Serial.println("=================Pin mode is LOW==================");
      digitalWrite(relayIn, LOW);  
    }
  } else {
    if(n==2) {
      // read the input on analog pin 0:
      int sensorValue = analogRead(A0);
      // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      float voltage = sensorValue * (5.0 / 1023.0);
      // print out the value you read:
      Serial.println(sensorValue);
      // Serial.write(sensorValue);  
    }
  }
}
