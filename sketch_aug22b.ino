const int tempPin = A0;
float tfmax = -100; 
float tfmin = 100;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val = analogRead(tempPin);
float mv = (val / 1024.0) * 500;
float cel = (mv - 500) / 10;
float farh = (cel * 9.0 / 5.0) + 32;


if (farh > tfmax) {
tfmax = farh;
}
if (farh < tfmin) {
tfmin = farh;
}


Serial.print("Temperature: ");
Serial.print(farh);
Serial.print(" °F");
Serial.print(" Max: ");
Serial.print(tfmax);
Serial.print(" °F");

Serial.print(" Min: ");
Serial.print(tfmin);
Serial.println(" °F");

delay(1000);
}
