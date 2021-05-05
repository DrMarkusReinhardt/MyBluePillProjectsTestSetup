/**
 *  RotaryEncoderSlotsAbstractBase1.h
 *
 * @brief The abstract base class defines slots for the handling of the first rotary encoder signals
 *
 * The abstract base class defines slots for the handling of the first rotary encoder signals
 *
 * @author Dr. Markus Reinhardt
 *
 * @date December 2020
 *
*/
#pragma once

#include <Arduino.h>

namespace MR_GUI_LIB
{

class RotaryEncoderSlotsAbstractBase1
{
public:
  RotaryEncoderSlotsAbstractBase1()
  {};

  /// the update routine to handle the rotary encoder turn signal
  virtual void OnRotaryEncoder1TurnReceived(Event<int16_t> turnEvent)=0;

  /// the update routine to handle the rotary encoder key press signal
  virtual void OnRotaryEncoder1KeyPressReceived(Event<uint16_t> keyPressEvent)=0;

  /// to print out the name of the slot class
  virtual String printName() = 0;
};

} // namespace MR_GUI_LIB
