int greenLed=12;
int yellowLed=11;
int redLed=10;
bool blinkGreen=false;
void setup() {
  // put your setup code here, to run once:
pinMode(greenLed,OUTPUT);
pinMode(yellowLed,OUTPUT);
pinMode(redLed,OUTPUT);
Serial.begin(9600);
Serial.println("Enter 'b'to blink green,'g' for green,'y' for yellow,'r' for red");

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  char userInput=Serial.read();
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,LOW);
  digitalWrite(redLed,LOW);
  switch(userInput){
    case 'b':
    blinkGreen=true;
    break;
     case 'g':
    blinkGreen=false;
    digitalWrite(greenLed,HIGH);
    break;
        case 'y':
    blinkGreen=false;
    digitalWrite(yellowLed,HIGH);
    break;
        case 'r':
    blinkGreen=false;
    digitalWrite(redLed,HIGH);
    break;
    default:
    Serial.println("Invalid input.Please enter 'b','g','y',or'r'.");
    break;
  }

}
if(blinkGreen){
  digitalWrite(greenLed,HIGH);
  delay(500);
  digitalWrite(greenLed,LOW);
  delay(500);
}
}
