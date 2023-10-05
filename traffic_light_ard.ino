/*
Name: Akshit Sodhiya
Date: 26th April,2022
*/
#define OFF LOW
#define ON HIGH
int const buttonPin = 3;    // index of the pushbutton pin
int const ledGreen = 13;    // index of the green LED pin
int const ledYellow = 12;   // index of the yellow LED pin
int const ledRed = 11;      // index of the red LED pin
int const min_time=500;     //minimum time button has to be pressed

unsigned long start;
unsigned long end;
unsigned long held;

//My Functions

void setup()
{
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

//Function for red light to stop
void red(void){
  digitalWrite(ledRed,ON);
  digitalWrite(ledYellow,OFF);
  digitalWrite(ledGreen,OFF);
  delay(5000);
}

//Function for yellow light to slow
void yellow(void){
  digitalWrite(ledYellow,ON);
  digitalWrite(ledGreen,OFF);
  digitalWrite(ledRed,OFF);
  delay(3000);
}

//Function for green light to go
void green(void){
  digitalWrite(ledGreen,ON);
  digitalWrite(ledYellow,OFF);
  digitalWrite(ledRed,OFF);
}

//Main Loop
void loop()
{
  buttonState=digitalRead(buttonPin);
  if (buttonState==OFF)
  {
    green();                          //traffic passes by
  }

  else if (buttonState==ON)
  {
    start=millis();           //time when button is pressed
   
    if (buttonState==OFF)
    {
      end=millis();           //time when button is released
    }
    held=end-start;         //time period
   
    if (held>min_time)
    {
    delay(2000);
     
    yellow();
     
    red();                    //traffic stops
    }
  }
}
