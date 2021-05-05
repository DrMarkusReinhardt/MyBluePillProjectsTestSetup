/**
 * RotaryEncoderHandler2.h
 *
 * @brief The rotary encoder handler for the second rotary encoder
 *
 * The rotary encoder handler for the second rotary encoder, it derives the following
 * functionality from the base class RotaryEncoderHandler:
 * It emits a signal when the rotary encoder is turned and calls the notifyTurn() function
 * It emits a signal when the rotary encoder key is pressed and calls the notifyKeyPress() function
 * It provides the means to attach / connect slots that receive the signals.
 *
 * @author Dr. Markus Reinhardt
 *
 * @date Dec. 2020
 *
 */
#pragma once

#include "RotaryEncoderSlotsAbstractBase2.h"
#include "RotaryEncoderHandler.h"

namespace MR_GUI_LIB
{

class RotaryEncoderHandler2 : public RotaryEncoderHandler
{
public:
  /// constructor
  RotaryEncoderHandler2(const char* initName) : RotaryEncoderHandler(initName)
  {}

  /// attach a class with a rotary encoder slot to the rotary encoder handlers's turn signal
  void attachTurnSignal2WidgetSlot(RotaryEncoderSlotsAbstractBase2 *slotClass)
  {
    // connect the widget to the turn signal
    // Serial.println(F("Rotary encoder handler 2: connect widget to the turn signal"));
    // Serial.print(F("slot class = ")); Serial.println(slotClass->printName());
    MethodSlot<RotaryEncoderSlotsAbstractBase2,int16_t> turnSlot(&(*slotClass), &RotaryEncoderSlotsAbstractBase2::OnRotaryEncoder2TurnReceived);
    turnSignal.Connect(turnSlot);
  }

  void attachKeyPressSignal2WidgetSlot(RotaryEncoderSlotsAbstractBase2 *slotClass)
  {
    // connect the widget to the key press signal
    // Serial.println(F("Rotary encoder handler 2: connect widget to the key press signal"));
    // Serial.print(F("slot class = ")); Serial.println(slotClass->printName());
    MethodSlot<RotaryEncoderSlotsAbstractBase2,uint16_t> keyPressSlot(&(*slotClass), &RotaryEncoderSlotsAbstractBase2::OnRotaryEncoder2KeyPressReceived);
    keyPressSignal.Connect(keyPressSlot);
  }
};

} // namespace MR_GUI_LIB
