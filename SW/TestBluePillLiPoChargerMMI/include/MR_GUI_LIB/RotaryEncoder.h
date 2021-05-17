/**
 * RotaryEncoder.h
 *
 * @brief Rotary Encoder driver for a rotary encoder
 *
 * Rotary Encoder driver for a rotary encoder
 *
 * History: Dr. M. Reinhardt, May 6th 2021
 *          updated implementation and fully tested, working perfectly
 *
 * @author Dr. Markus Reinhardt
 *
 * @date May 2021
 */
#pragma once

#include <Arduino.h>

enum TurnDirection
{
  CW,
  CCW
};

namespace MR_GUI_LIB
{

class RotaryEncoder
{
public:
  /// constructor
  RotaryEncoder(String id, uint8_t pinA, uint8_t pinB, uint8_t pinE,
                volatile bool *pendingInterruptKeyPressed, volatile bool *pendingInterruptTurned,
                volatile uint8_t *pinAVal, volatile uint8_t *pinBVal);

  /// check if the key has been pressed (interrupt is pending)
  bool checkKeyPressed();

  /// check if the rotary encoder was turned (interrupt is pending)
  bool checkTurned();

  /// update the key pressed variable
  uint16_t handleKeyPress();

  /// determine the turn direction and update the rotation variable
  int16_t handleTurn();

  /// get the value of the switch
  uint16_t getSwitchVariable();

  /// get the value of the rotation
  int16_t getRotationValue();

  /// get turn direction enum
  TurnDirection getTurnDirection();

  /// get turn direction as a string
  String getTurnDirectionString();

  /// reset pending key interrupt
  void resetKeyInterrupt();

  /// rest pending turn interrupt
  void resetTurnInterrupt();

  /// reset the rotation value and the switch value
  void reset();

  /// disable the rotary encoder
  void disable(uint8_t pinA, uint8_t pinB, uint8_t pinE);

  /// activate the rotary encoder pins and reset the counters
  void setup(uint8_t pinA, uint8_t pinB, uint8_t pinE);


private:
  String m_id;
  uint8_t m_pinA;
  uint8_t m_pinB;
  uint8_t m_pinE;

  volatile bool *m_pendingInterruptKeyPressed;
  volatile bool *m_pendingInterruptTurned;
  volatile uint8_t *m_pinAVal;
  volatile uint8_t *m_pinBVal;
  volatile int16_t m_rotationVariable;
  volatile uint16_t m_switchVariable;
  volatile TurnDirection m_turnDirection;
  String m_turnDirectionString;
};

/// constructor
RotaryEncoder::RotaryEncoder(String id, uint8_t pinA, uint8_t pinB, uint8_t pinE,
                volatile bool *pendingInterruptKeyPressed, volatile bool *pendingInterruptTurned,
                volatile uint8_t *pinAVal, volatile uint8_t *pinBVal)
: m_id(id), m_pinA(pinA), m_pinB(pinB), m_pinE(pinE),
  m_pendingInterruptKeyPressed(pendingInterruptKeyPressed), m_pendingInterruptTurned(pendingInterruptTurned),
  m_pinAVal(pinAVal), m_pinBVal(pinBVal)
{
  m_rotationVariable = 0;
  m_switchVariable = 0;
  pinMode(m_pinA, INPUT_PULLUP);
  pinMode(m_pinB, INPUT_PULLUP);
  pinMode(m_pinE, INPUT_PULLUP);
}

/// check if the key has been pressed (interrupt is pending)
bool RotaryEncoder::checkKeyPressed()
{
  if (*m_pendingInterruptKeyPressed == true)
  {
    // Serial.print(m_id); Serial.println(" key pressed");
    *m_pendingInterruptKeyPressed = false;
    return true;
  }
  else
    return false;
}

bool RotaryEncoder::checkTurned()
{
  if (*m_pendingInterruptTurned == true)
  {
    // Serial.print(m_id); Serial.println(" turned");
    *m_pendingInterruptTurned = false;
    return true;
  }
  else
    return false;
}

/// update the key pressed variable
uint16_t RotaryEncoder::handleKeyPress()
{
  m_switchVariable++;
  return m_switchVariable;
};

/// determine the turn direction and update the rotation variable
int16_t RotaryEncoder::handleTurn()
{
  if(*m_pinAVal == *m_pinBVal)
  {
    m_rotationVariable--;
    m_turnDirection = CCW;
  }
  else
  {
    m_rotationVariable++;
    m_turnDirection = CW;
  }
  return m_rotationVariable;
};


int16_t RotaryEncoder::getRotationValue()
{
  return m_rotationVariable;
}

uint16_t RotaryEncoder::getSwitchVariable()
{
  return m_switchVariable;
}

/// get turn direction
TurnDirection RotaryEncoder::getTurnDirection()
{
  return m_turnDirection;
}

/// get turn direction string
String RotaryEncoder::getTurnDirectionString()
{
  if (m_turnDirection == CW)
    m_turnDirectionString = "CW";
  else
    m_turnDirectionString = "CCW";
  return m_turnDirectionString;
}

void RotaryEncoder::reset()
{
  m_rotationVariable = 0;
  m_switchVariable = 0;
}

/// activate the pins for the rotary encoder and reset the counters
void RotaryEncoder::setup(uint8_t initPinA, uint8_t initPinB, uint8_t initPinE)
{
  m_pinA = initPinA;
  m_pinB = initPinB;
  m_pinE = initPinE;
  m_rotationVariable = 0;
  m_switchVariable = 0;
  pinMode(m_pinA, INPUT_PULLUP);
  pinMode(m_pinB, INPUT_PULLUP);
  pinMode(m_pinE, INPUT_PULLUP);
};

void RotaryEncoder::disable(uint8_t pinA, uint8_t pinB, uint8_t pinE)
{
  detachInterrupt(pinA);
  detachInterrupt(pinE);
}

} // namespace MR_GUI_LIB
