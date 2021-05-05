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

volatile bool pendingInterruptRotEnc2KeyPressed = false;
volatile bool pendingInterruptRotEnc2Turned = false;

// ISR routine called when the rotary encoder 1 is turned
void rotEnc1Turned()
{
  noInterrupts();
  pendingInterruptRotEnc1Turned = true;
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
  interrupts();
}

// ISR routine called when the rotary encoder 2 key is pressed
void rotEnc2KeyPressed()
{
  noInterrupts();
  pendingInterruptRotEnc2KeyPressed = true;
  interrupts();
}         

//  the rotary encoder 1 as input device
MR_GUI_LIB::RotaryEncoder rotEnc1;

//  the rotary encoder 2 as input device
MR_GUI_LIB::RotaryEncoder rotEnc2;


MR_GUI_LIB::RotaryEncoderHandler1 reh1("reh1");
MR_GUI_LIB::RotaryEncoderHandler2 reh2("reh2");

uint32_t counter = 0;

void setup() {
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


void loop() {
  // put your main code here, to run repeatedly:
  counter++;
  Serial.print(counter);
  Serial.println(" -*-");

  checkRotEnc1KeyPressed();
  checkRotEnc1Turned();
  checkRotEnc2KeyPressed();
  checkRotEnc2Turned();

  delay(1000);
}