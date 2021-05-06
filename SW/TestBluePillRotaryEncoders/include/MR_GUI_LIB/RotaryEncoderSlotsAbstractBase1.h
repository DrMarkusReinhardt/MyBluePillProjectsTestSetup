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
#include "Event.h"

namespace MR_GUI_LIB
{

class RotaryEncoderSlotsAbstractBase1
{
public:
  RotaryEncoderSlotsAbstractBase1()
  {};

  /// the update routine to handle the rotary encoder turn signal with argument turn value
  virtual void OnRotaryEncoder1TurnValueReceived(MR_GUI_LIB::Event<int16_t> turnValueEvent)=0;

  /// the update routine to handle the rotary encoder turn signal with argument turn direction
  virtual void OnRotaryEncoder1TurnDirectionReceived(MR_GUI_LIB::Event<TurnDirection> turnDirectionEvent)=0;

  /// the update routine to handle the rotary encoder key press signal
  virtual void OnRotaryEncoder1KeyPressReceived(MR_GUI_LIB::Event<uint16_t> keyPressEvent)=0;

  /// to print out the name of the slot class
  virtual String getId() = 0;
};

} // namespace MR_GUI_LIB
