#include <Arduino.h>
#include "Callback.h"
#include "Event.h"

#include "RotaryEncoder.h"
#include "RotaryEncoderHandler1.h"
#include "RotaryEncoderHandler2.h"

// pin definitions of rotary encoder 1
#define Encoder1_PinA PB14
#define Encoder1_PinB PB13
#define Encoder1_PinE PB12

// pin definitions of rotary encoder 2
#define Encoder2_PinA PB5
#define Encoder2_PinB PB4
#define Encoder2_PinE PB3

volatile bool pendingInterruptRotEnc1KeyPressed = false;
volatile bool pendingInterruptRotEnc1Turned = false;

volatile uint8_t pinAValRotEnc1;
volatile uint8_t pinBValRotEnc1;

volatile bool pendingInterruptRotEnc2KeyPressed = false;
volatile bool pendingInterruptRotEnc2Turned = false;

volatile uint8_t pinAValRotEnc2;
volatile uint8_t pinBValRotEnc2;

// ISR routine called when the rotary encoder 1 is turned
void rotEnc1Turned()
{
  noInterrupts();
  pendingInterruptRotEnc1Turned = true;
  pinAValRotEnc1 = digitalRead(Encoder1_PinA);
  pinBValRotEnc1 = digitalRead(Encoder1_PinB);
  interrupts();
}

// ISR routine called when the rotary encoder 1 key is pressed
void rotEnc1KeyPressed()
{
  noInterrupts();
  pendingInterruptRotEnc1KeyPressed = true;
  interrupts();
}         

// ISR routine called when the rotary encoder 2 is turned
void rotEnc2Turned()
{
  noInterrupts();
  pendingInterruptRotEnc2Turned = true;
  pinAValRotEnc2 = digitalRead(Encoder2_PinA);
  pinBValRotEnc2 = digitalRead(Encoder2_PinB);
  interrupts();
}

// ISR routine called when the rotary encoder 2 key is pressed
void rotEnc2KeyPressed()
{
  noInterrupts();
  pendingInterruptRotEnc2KeyPressed = true;
  interrupts();
}         

// the rotary encoder 1 as input device
MR_GUI_LIB::RotaryEncoder rotEnc1("RotEnc1",Encoder1_PinA,Encoder1_PinB,Encoder1_PinE,
                                  &pendingInterruptRotEnc1KeyPressed,&pendingInterruptRotEnc1Turned,
                                  &pinAValRotEnc1,&pinBValRotEnc1);

// the rotary encoder 2 as input device
MR_GUI_LIB::RotaryEncoder rotEnc2("RotEnc2",Encoder1_PinA,Encoder1_PinB,Encoder1_PinE,
                                  &pendingInterruptRotEnc2KeyPressed,&pendingInterruptRotEnc2Turned,
                                  &pinAValRotEnc2,&pinBValRotEnc2);

/// the rotary encoder handler for rotary encoder 1 to support the signals&slots mechanics
MR_GUI_LIB::RotaryEncoderHandler1 reh1("REH1",&rotEnc1);

/// the rotary encoder handler for rotary encoder 2 to support the signals&slots mechanics
MR_GUI_LIB::RotaryEncoderHandler2 reh2("REH2",&rotEnc2);

uint32_t counter = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  // initialize the rotary encoder handler 1 and related interrupts
  // reh1.setup(&rotEnc1, Encoder1_PinA, Encoder1_PinB, Encoder1_PinE);
  attachInterrupt(digitalPinToInterrupt(Encoder1_PinB), rotEnc1Turned, RISING);
  attachInterrupt(digitalPinToInterrupt(Encoder1_PinE), rotEnc1KeyPressed, FALLING);

  // initialize the rotary encoder handler 2 and related interrupts
  // reh2.setup(&rotEnc2,Encoder2_PinA, Encoder2_PinB, Encoder2_PinE);
  attachInterrupt(digitalPinToInterrupt(Encoder2_PinB), rotEnc2Turned, RISING);
  attachInterrupt(digitalPinToInterrupt(Encoder2_PinE), rotEnc2KeyPressed, FALLING);
  
  Serial.println("Setup done");
}

void checkRotEnc1KeyPressed()
{
  noInterrupts();
  if (pendingInterruptRotEnc1KeyPressed == true)
  {
    Serial.println("RotEnc 1 key pressed");
    pendingInterruptRotEnc1KeyPressed = false;
  }
  interrupts();
}

void checkRotEnc1Turned()
{
  noInterrupts();
  if (pendingInterruptRotEnc1Turned == true)
  {
    Serial.println("RotEnc 1 turned");
    pendingInterruptRotEnc1Turned = false;
  }
  interrupts();
}

void checkRotEnc2KeyPressed()
{
  noInterrupts();
  if (pendingInterruptRotEnc2KeyPressed == true)
  {
    Serial.println("RotEnc 2 key pressed");
    pendingInterruptRotEnc2KeyPressed = false;
  }
  interrupts();
}

void checkRotEnc2Turned()
{
  noInterrupts();
  if (pendingInterruptRotEnc2Turned == true)
  {
    Serial.println("RotEnc 2 turned");
    pendingInterruptRotEnc2Turned = false;
  }
  interrupts();
}


void loop() 
{
  // put your main code here, to run repeatedly:

  int16_t rotation1;
  uint16_t keyPresses1;
  int16_t rotation2;
  uint16_t keyPresses2;
  TurnDirection turnDirection1;
  String turnDirectionString1;
  TurnDirection turnDirection2;
  String turnDirectionString2;

  counter++;
  Serial.print(counter);
  Serial.println(" -*-");
  
  if (rotEnc1.checkKeyPressed())
  {
    keyPresses1 = rotEnc1.handleKeyPress();
    Serial.print("RotEnc1 no. key pressed = "); Serial.println(keyPresses1);
  }
    
  if (rotEnc1.checkTurned())
  {
    rotation1 = rotEnc1.handleTurn();
    Serial.print("RotEnc1 rotation = "); Serial.println(rotation1);
    turnDirection1 = rotEnc1.getTurnDirection();
    Serial.print("RotEnc1 turn direction (enum) = "); Serial.println(turnDirection1);
    turnDirectionString1 = rotEnc1.getTurnDirectionString();
    Serial.print("RotEnc1 turn direction (string) = "); Serial.println(turnDirectionString1);
  }

  if (rotEnc2.checkKeyPressed())
  {
    keyPresses2 = rotEnc2.handleKeyPress();
    Serial.print("RotEnc2 no. key pressed = "); Serial.println(keyPresses2);
  }
    
  if (rotEnc2.checkTurned())
  {
    rotation2 = rotEnc2.handleTurn();
    Serial.print("RotEnc2 rotation = "); Serial.println(rotation2);
    turnDirection2 = rotEnc2.getTurnDirection();
    Serial.print("RotEnc2 turn direction (enum) = "); Serial.println(turnDirection2);
    turnDirectionString2 = rotEnc2.getTurnDirectionString();
    Serial.print("RotEnc2 turn direction (string) = "); Serial.println(turnDirectionString2);
  }

  delay(1000);
}