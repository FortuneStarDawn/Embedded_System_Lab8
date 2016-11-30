#include <Stepper.h>

// for 28BYJ-48
#define STEPS 2048

int button = 2;
int xAxis = A0, yAxis = A1;
int tempX=512, tempY=512;
int state = 0;
int unit = 512;

// create an instance of the stepper class, specifying # of steps of the motor and the pins it is attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

void setup()
{
  stepper.setSpeed(5); // set the speed to 30 RPMs
  pinMode(button, INPUT_PULLUP);
}

void loop()
{
  // get the sensor value from pin A0
  int xVal = analogRead(xAxis);
  int yVal = analogRead(yAxis);

  // move a number of steps equal to the change in the
  // sensor reading
  if(xVal > 1000)
  {
    if(state==0)
    {
      stepper.step(unit);
    }
    else if(state==2)
    {
      stepper.step(unit*3);
    }
    else if(state==3)
    {
      stepper.step(unit*2);
    }
    state = 1;
  }
  else if(xVal < 20)
  {
    if(state==0)
    {
      stepper.step(unit*3);
    }
    else if(state==1)
    {
      stepper.step(unit*2);
    }
    else if(state==2)
    {
      stepper.step(unit);
    }
    state = 3;
  }
  else if(yVal > 1000)
  {
    if(state==0)
    {
      stepper.step(unit*2);
    }
    else if(state==1)
    {
      stepper.step(unit);
    }
    else if(state==3)
    {
      stepper.step(unit*3);
    }
    state = 2;
  }
  else if(yVal < 20)
  {
    if(state==1)
    {
      stepper.step(unit*3);
    }
    else if(state==2)
    {
      stepper.step(unit*2);
    }
    else if(state==3)
    {
      stepper.step(unit);
    }
    state = 0;
  }
  delay(1000);
}

