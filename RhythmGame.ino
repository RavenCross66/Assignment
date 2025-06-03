#include <Adafruit_Circuit_Playground.h>

bool leftButtonState = false;
bool rightButtonState = false;
int currentBeat = 0;
int currentSequence = 0;
int buttonInput = 0;
int currentScore = 0;
int highScore = 0;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  while (!Serial);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (currentBeat == 0){
    currentSequence = 1 + random(3);
    for (int i=0;i<10;i+=1){
      CircuitPlayground.setPixelColor(i,0,0,255);
    }
  }
  if (currentBeat>0 && currentBeat<10) {
    switch (currentSequence){
      case 1:
      CircuitPlayground.setPixelColor(currentBeat-1,0,0,0);
      break;

      case 2:
      CircuitPlayground.setPixelColor(10-currentBeat,0,0,0);
      break;

      case 3:
      if (currentBeat%2==0){
        CircuitPlayground.setPixelColor(10-(currentBeat/2),0,0,0);
        CircuitPlayground.setPixelColor((currentBeat/2)-1,0,0,0);
      }
      break;
    }
  }

  leftButtonState = CircuitPlayground.leftButton();
  rightButtonState = CircuitPlayground.rightButton();

  if (currentBeat==10){
    currentBeat==0;
    if (leftButtonState && rightButtonState){
      buttonInput = 3;
    } else if (rightButtonState) {
      buttonInput = 1;
    } else if (leftButtonState) {
      buttonInput = 2;
    } else {
      buttonInput = 0;
    }

    if (buttonInput== currentSequence){
      for (int i=0;i<10;i+=1){
        CircuitPlayground.setPixelColor(i,0,255,0);
      }
       currentScore++;
        Serial.print("Current Score: ");
        Serial.println(currentScore);
    } else {
      for (int i=0;i<10;i+=1){
       CircuitPlayground.setPixelColor(i,255,0,0);
      }
      Serial.print("Your Current High Score: ");
        if (highScore<currentScore){
          highScore=currentScore;
        }
        currentScore= 0;
        Serial.println(highScore);
    }
    delay(250);
  } else if (leftButtonState || rightButtonState){
      currentBeat=11;
      for (int i=0;i<10;i+=1){
       CircuitPlayground.setPixelColor(i,255,0,0);
      }
      Serial.print("Your Current High Score: ");
        if (highScore<currentScore){
          highScore=currentScore;
        }
        Serial.println(highScore);
        currentScore = 0;
      delay(250);
  }
 
  currentBeat +=1;
  if (currentBeat>10) {
    currentBeat=0;
  }
  delay(120-currentScore);
  if (currentScore == 100){
    Serial.print("You win, what are you even doing playing this god forsaken circuit board game this much? Get a life dude.");
    while (currentScore == 100);
  }
}
