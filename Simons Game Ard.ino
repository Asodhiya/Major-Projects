//Name: Akshit Sodhiya
//defined all the constants thats are being used 
int const NOT_WORKING = 13;int const PASS = 8;

int const YELLOW_LIGHT = 11;int const BLUE_LIGHT = 10;int const RED_LIGHT = 12;int const GREEN_LIGHT = 9;

int const BLUE_BUTTON = 5;int const YELLOW_BUTTON =6;int const GREEN_BUTTON = 4;int const RED_BUTTON = 7;

int RED_INPUT_BUTTON; int YELLOW_INPUT_BUTTON;int BLUE_INPUT_BUTTON;int GREEN_INPUT_BUTTON;

char const CHECK[] = "The Game has began\n";
//initlize the constants i.e the lights and the button
void setup()
{
  Serial.begin(10000);
 
  pinMode(NOT_WORKING, OUTPUT);pinMode(PASS, OUTPUT);
  pinMode(RED_LIGHT, OUTPUT);pinMode(YELLOW_LIGHT, OUTPUT);
  pinMode(BLUE_LIGHT, OUTPUT);pinMode(GREEN_LIGHT, OUTPUT);
 
  pinMode(RED_BUTTON, INPUT);pinMode(YELLOW_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);pinMode(GREEN_BUTTON, INPUT);
 
}
void loop()//the main funtion 
{
 //to flash all the lighst before the game starts 
   digitalWrite(PASS, HIGH);digitalWrite(NOT_WORKING, HIGH);
   delay(750);

   digitalWrite(PASS, LOW);digitalWrite(NOT_WORKING, LOW);
   delay(750);

   digitalWrite (RED_LIGHT, HIGH);digitalWrite (YELLOW_LIGHT, HIGH);
   digitalWrite (BLUE_LIGHT, HIGH);digitalWrite (GREEN_LIGHT, HIGH);
   delay(750);
    
   digitalWrite (RED_LIGHT, LOW);digitalWrite (YELLOW_LIGHT, LOW);
   digitalWrite (BLUE_LIGHT, LOW);digitalWrite (GREEN_LIGHT, LOW);
   delay(750); 
 
  Serial.print(CHECK);
  randomSeed(analogRead(0)); 
  int color[5];int size = 5;int l; int status = 5;int colournum=0;
  for(;colournum<5;)
  {
    color[colournum]=random(9,13);
    colournum++;
  }  
 l=1;
  for(;l<=size;) 
  {
     if(status == 0)
     {
       break;
     }
     delay(1750);
     colournum=0;
    for(;colournum<l;) 
    {
     
      if(status == 0)
      {
        break;
      }
      digitalWrite( color[colournum], HIGH );delay(750);
      digitalWrite( color[colournum], LOW ); delay(300);
      if(colournum == l - 1)
       {
      status = input(l, color);

       }
     colournum++;
    }
   l++;
  }
  if(status == 1)
  {
    digitalWrite(PASS, HIGH);delay(750);
    digitalWrite(PASS, LOW);delay(750);
    digitalWrite(PASS, HIGH);delay(750);
    digitalWrite(PASS, LOW);delay(750);
    digitalWrite(PASS, HIGH);delay(750);
    digitalWrite(PASS, LOW);delay(750);
    digitalWrite(PASS, HIGH);
    Serial.print("YOU ARE A WINNER!!");
    Serial.print("\n");
  }
  Serial.print("To play just press any button on the circuit");
  Serial.print("\n");
  for(;BLUE_INPUT_BUTTON == LOW && RED_INPUT_BUTTON == LOW && GREEN_INPUT_BUTTON == LOW && YELLOW_INPUT_BUTTON == LOW ;)
    {
     
     RED_INPUT_BUTTON = digitalRead(RED_BUTTON);YELLOW_INPUT_BUTTON = digitalRead(YELLOW_BUTTON);
     BLUE_INPUT_BUTTON = digitalRead(BLUE_BUTTON);GREEN_INPUT_BUTTON = digitalRead(GREEN_BUTTON);
    }
}
//the function is the input all the button pressed from the user
int input(int l, int cololur[5])
{
        int status; int pointers;//status shows if the player has won or lost:1-they are still winning,0-they have lost
        pointers = 0;//pointers is a loop variable  
        for(;pointers<l;)
   {   //check for which switches has the user inputted 
       RED_INPUT_BUTTON = digitalRead(RED_BUTTON);YELLOW_INPUT_BUTTON = digitalRead(YELLOW_BUTTON);
       BLUE_INPUT_BUTTON = digitalRead(BLUE_BUTTON);GREEN_INPUT_BUTTON = digitalRead(GREEN_BUTTON);

       for(;RED_INPUT_BUTTON == LOW && YELLOW_INPUT_BUTTON == LOW && BLUE_INPUT_BUTTON == LOW && GREEN_INPUT_BUTTON == LOW;)
       {
         RED_INPUT_BUTTON = digitalRead(RED_BUTTON);YELLOW_INPUT_BUTTON = digitalRead(YELLOW_BUTTON);
         BLUE_INPUT_BUTTON = digitalRead(BLUE_BUTTON);GREEN_INPUT_BUTTON = digitalRead(GREEN_BUTTON);
         
        }  
       RED_INPUT_BUTTON = digitalRead(RED_BUTTON);
       if (RED_INPUT_BUTTON == HIGH) //check if this button was pressed
       {
             for(;RED_INPUT_BUTTON == HIGH;)  
              RED_INPUT_BUTTON = digitalRead(RED_BUTTON);
       
               if(RED_INPUT_BUTTON == LOW) 
         { 
           if(cololur[pointers] == 12)
             status = 1; 
             else 
             {
             status = 0;
             Serial.print("YOU HAVE LOST THE GAME\n");
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             return 0;
             }
         }
         }
     
     YELLOW_INPUT_BUTTON = digitalRead(YELLOW_BUTTON);
     if (YELLOW_INPUT_BUTTON == HIGH) 
       {
     for (;YELLOW_INPUT_BUTTON == HIGH;)
     YELLOW_INPUT_BUTTON = digitalRead(YELLOW_BUTTON);
       
         if(YELLOW_INPUT_BUTTON == LOW) 
         {
           
           if(cololur[pointers] == 11)
             status = 1; 
         
           else
        {
             status = 0;
             Serial.print("YOU HAVE LOST THE GAME \n");
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             return 0;
           }
           
           }
         }
     BLUE_INPUT_BUTTON = digitalRead(BLUE_BUTTON);

     if (BLUE_INPUT_BUTTON == HIGH) 
       {
     for(;BLUE_INPUT_BUTTON == HIGH;)  
     BLUE_INPUT_BUTTON = digitalRead(BLUE_BUTTON);
       
         if(BLUE_INPUT_BUTTON == LOW) 
         {
           
           if(cololur[pointers] == 10)
             status = 1; 
           
           else 
           {
             status = 0;
             Serial.print("YOU HAVE LOST THE GAME \n");
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW); delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             return 0;
           }
           }
         }
         GREEN_INPUT_BUTTON = digitalRead(GREEN_BUTTON);
     if (GREEN_INPUT_BUTTON == HIGH) 
       {
     for(;GREEN_INPUT_BUTTON == HIGH;)  
     GREEN_INPUT_BUTTON = digitalRead(GREEN_BUTTON);
       
         if(GREEN_INPUT_BUTTON == LOW) 
         {
           
           if(cololur[pointers] == 9)
             status = 1; 
         
           else {
             status = 0;
             Serial.print("YOU HAVE LOST THE GAME\n");

             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW);delay(750);
             digitalWrite(NOT_WORKING, HIGH);delay(750);
             digitalWrite(NOT_WORKING, LOW); delay(750);
            return 0;  
           }
         }
       }
         pointers++;
     }

    return status; 
 }
   

