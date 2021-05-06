/**
 * RotaryEncoderHandler1.h
 *
 * @brief The rotary encoder handler for the first rotary encoder
 *
 * The rotary encoder handler for the first rotary encoder, it derives the following
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

#include "RotaryEncoder.h"
#include "RotaryEncoderSlotsAbstractBase1.h"
#include "RotaryEncoderHandler.h"
#include "Event.h"

namespace MR_GUI_LIB
{

class RotaryEncoderHandler1 : public RotaryEncoderHandler
{
public:
  /// constructor
  RotaryEncoderHandler1(const char* initName, MR_GUI_LIB::RotaryEncoder *initRotEnc) 
   : RotaryEncoderHandler(initName,initRotEnc)
  {}

  /// attach a class with a rotary encoder slot to the rotary encoder handlers's turn value signal
  void attachTurnValueSignal2EventSlot(MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1 *slotClass)
  {
    // connect the slot to the turn signal
    // Serial.println(F("Rotary encoder handler 1: connect widget to the turn signal"));
    // Serial.print(F("slot class = ")); Serial.println(slotClass->printName());
    MethodSlot< MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1, Event<int16_t> > turnValueSlot(&(*slotClass), 
      &MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1::OnRotaryEncoder1TurnValueReceived);
    turnValueSignal.Connect(turnValueSlot);
  }

  /// attach a class with a rotary encoder slot to the rotary encoder handlers's turn direction signal
  void attachTurnDirectionSignal2EventSlot(MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1 *slotClass)
  {
    // connect the slot to the turn signal
    // Serial.println(F("Rotary encoder handler 1: connect widget to the turn signal"));
    // Serial.print(F("slot class = ")); Serial.println(slotClass->printName());
    MethodSlot< MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1, Event<TurnDirection> > turnDirectionSlot(&(*slotClass), 
         &MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1::OnRotaryEncoder1TurnDirectionReceived);
    turnDirectionSignal.Connect(turnDirectionSlot);
  }

  /// attach a class with a rotary encoder slot to the rotary encoder handlers's key press signal
  void attachKeyPressSignal2EventSlot(MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1 *slotClass)
  {
    // connect the slot to the key press signal
    // Serial.print(name_);
    // Serial.println(F("Rotary encoder handler 1: connect widget to the key press signal"));
    // Serial.print(F("slot class = ")); Serial.println(slotClass->printName());
    MethodSlot<MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1, Event<uint16_t> > keyPressSlot(&(*slotClass), 
      &MR_GUI_LIB::RotaryEncoderSlotsAbstractBase1::OnRotaryEncoder1KeyPressReceived);
    keyPressSignal.Connect(keyPressSlot);
  }
};

} // namespace MR_GUI_LIB
