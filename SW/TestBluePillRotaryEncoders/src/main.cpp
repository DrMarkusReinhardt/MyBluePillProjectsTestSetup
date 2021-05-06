#include <Arduino.h>
#include "Callback.h"
#include "Event.h"

#include "RotaryEncoder.h"
#include "RotaryEncoderHandler1.h"
#include "RotaryEncoderHandler2.h"

#include "MMIHandler.h"

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

// the rotary encoder handler for rotary encoder 1 to support the signals&slots mechanics
MR_GUI_LIB::RotaryEncoderHandler1 reh1("REH1",&rotEnc1);

// the rotary encoder handler for rotary encoder 2 to support the signals&slots mechanics
MR_GUI_LIB::RotaryEncoderHandler2 reh2("REH2",&rotEnc2);

// create the MMI handler
MR_LiPo_Charger::MMIHandler mmiHandler(&reh1, &reh2);

// loop counter
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

  // setup the MMI handler
  mmiHandler.setup();
  
  Serial.println("Setup done");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  counter++;
  Serial.print(counter);
  Serial.println(" -*-");

  mmiHandler.update();

  delay(1000);
}