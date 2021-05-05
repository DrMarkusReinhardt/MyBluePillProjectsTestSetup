/**
 *  RotaryEncoderSlotsAbstractBase2.h
 *
 * @brief The abstract base class defines slots for the handling of the second rotary encoder signals
 *
 * The abstract base class defines slots for the handling of the second rotary encoder signals
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

class RotaryEncoderSlotsAbstractBase2
{
public:
  RotaryEncoderSlotsAbstractBase2()
  {};

  /// the update routine to handle the rotary encoder 2 turn signal
  virtual void OnRotaryEncoder2TurnReceived(Event<int16_t> turnEvent)=0;

  /// the update routine to handle the rotary encoder 2 key press signal
  virtual void OnRotaryEncoder2KeyPressReceived(Event<uint16_t> keyPressEvent)=0;
  
  /// to print out the name of the slot class
  virtual String printName() = 0;
};

} // namespace MR_GUI_LIB
