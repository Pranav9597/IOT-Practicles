int thermistorpin=A0;
int buzzer=8;
int delayTime=500;

void setup() 
{
  // put your setup code here, to run once:
  pinMode (buzzer,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
float a= analogRead(thermistorpin);
float resistance=(1023.0*10000)/ a-10000;
float tempC=(3435.0/(log(resistance/10000))) -273.15+273.15;
Serial.print("Temp:");
Serial.print(tempC);
Serial.print("C");
delay (delayTime);
if(tempC>30.0)
{
  for (int i=200;i<800;i++)
  {
    tone(buzzer,i);
    delay(5);
  
}
for (int i=800;i>200;i--)
{
  tone(buzzer,i);
    delay(5);
}
}
}
