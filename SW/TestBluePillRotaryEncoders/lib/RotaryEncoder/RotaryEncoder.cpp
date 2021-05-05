/**
 * RotaryEncoder.cpp
 *
 * Rotary Encoder library for the first rotary encoder
 *
 * History: Dr. M. Reinhardt, June 8th 2019
 *          first implementation and fully tested, working perfectly
 */

#include "RotaryEncoder.h"

namespace MR_GUI_LIB
{

void RotaryEncoder::EncoderFunctionB()
{
  uint8_t pinAVal = digitalRead(pinA);
  uint8_t pinBVal = digitalRead(pinB);
  if(pinAVal == pinBVal)
  {
    RotationVariable++;
  }
  else
  {
    RotationVariable--;
  }
  // Serial.println("EncoderFunctionB() called");
};

void RotaryEncoder::EncoderFunctionE()
{
  SwitchVariable++;
  // Serial.println("EncoderFunctionE() called");
};

RotaryEncoder::RotaryEncoder()
{
};

/// activate the interrupts for the rotary encoder and reset the counters
void RotaryEncoder::setup(uint8_t initPinA, uint8_t initPinB, uint8_t initPinE)
{
  pinA = initPinA;
  pinB = initPinB;
  pinE = initPinE;

  RotationVariable = 0;
  SwitchVariable = 0;

  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  RotationVariable = 0;

  pinMode(pinE, INPUT_PULLUP);
  SwitchVariable = 0;
};

int8_t RotaryEncoder::getRotationVariable()
{
  return RotationVariable;
}

uint8_t RotaryEncoder::getSwitchVariable()
{
  return SwitchVariable;
}

void RotaryEncoder::reset()
{
  RotationVariable = 0;
  SwitchVariable = 0;
}

void RotaryEncoder::disable(uint8_t pinA, uint8_t pinB, uint8_t pinE)
{
  detachInterrupt(pinA);
  detachInterrupt(pinE);
}

} // namespace MR_GUI_LIB
