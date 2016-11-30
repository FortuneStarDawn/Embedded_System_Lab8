int button = 2;
int xAxis = A0, yAxis = A1;
int redPin = 11, greenPin = 10, bluePin = 9;
int red, blue;

void setup()
{
  pinMode(button, INPUT_PULLUP); //return LOW when link
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop()
{
  int xVal = analogRead(xAxis);
  int yVal = analogRead(yAxis);
  int isPress = digitalRead(button);

  blue = map(xVal, 0, 1023, 255, 0);
  red = map(yVal, 0, 1023, 0, 255);
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  if(isPress==0) analogWrite(greenPin, 0);
  else analogWrite(greenPin, 153);
}

