
int led=13;
int ledd=10;
int buttonPin=2;
int buttonP=4;

void setup() 
{
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(buttonPin, INPUT);
pinMode(buttonP, INPUT);
}

void loop()
{
  if(digitalRead(buttonPin)==HIGH)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  delay(100);
  if(digitalRead(buttonP)==HIGH)
  {
    digitalWrite(ledd,HIGH);
  }
  else
  {
    digitalWrite(ledd, LOW);
  }
  delay(100);
}
