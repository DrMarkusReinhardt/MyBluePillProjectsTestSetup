/** TestRotaryEncoderSlot.h
 *
 *
 */
#pragma once

#include "Arduino.h"
#include "RotaryEncoder.h"
#include "RotaryEncoderSlotsAbstractBase1.h"

namespace MR_GUI_LIB
{

class TestRotaryEncoderSlot : public RotaryEncoderSlotsAbstractBase1, public RotaryEncoderSlotsAbstractBase2
{
public:
  TestRotaryEncoderSlot(String id) : RotaryEncoderSlotsAbstractBase1(), m_id(id) 
  {
  }

  /// the update routine to handle the rotary encoder turn signal
  virtual void OnRotaryEncoder1TurnValueReceived(MR_GUI_LIB::Event<int16_t> turnValueEvent)
  {
    Serial.println("TestRotaryEncoderSlot: turn value 1 signal received");
    Serial.print("rotation value = "); Serial.println(turnValueEvent.getParameter());
  }

  virtual void OnRotaryEncoder1TurnDirectionReceived(MR_GUI_LIB::Event<TurnDirection> turnDirectionEvent)
  {
    Serial.println("TestRotaryEncoderSlot: turn direction 1 signal received");
    Serial.print("direction = "); Serial.println(turnDirectionEvent.getParameter());
  }

  /// the update routine to handle the rotary encoder key press signal
  virtual void OnRotaryEncoder1KeyPressReceived(MR_GUI_LIB::Event<uint16_t> keyPressEvent)
  {
    Serial.print(getId()); Serial.println(": key press 1 signal received");
    Serial.print("key press value = "); Serial.println(keyPressEvent.getParameter());      
  }

  /// the update routine to handle the rotary encoder turn signal
  virtual void OnRotaryEncoder2TurnValueReceived(MR_GUI_LIB::Event<int16_t> turnValueEvent)
  {
    Serial.println("TestRotaryEncoderSlot: turn value 2 signal received");
    Serial.print("rotation value = "); Serial.println(turnValueEvent.getParameter());
  }

  virtual void OnRotaryEncoder2TurnDirectionReceived(MR_GUI_LIB::Event<TurnDirection> turnDirectionEvent)
  {
    Serial.println("TestRotaryEncoderSlot: turn direction 2 signal received");
    Serial.print("direction = "); Serial.println(turnDirectionEvent.getParameter());
  }

  /// the update routine to handle the rotary encoder key press signal
  virtual void OnRotaryEncoder2KeyPressReceived(MR_GUI_LIB::Event<uint16_t> keyPressEvent)
  {
    Serial.print(getId()); Serial.println(": key press 2 signal received");
    Serial.print("key press value = "); Serial.println(keyPressEvent.getParameter());      
  }

  /// to return the name of the slot class
  virtual String getId()
  {
    return m_id; 
  }

public:
  String m_id;
};

} // namespace MR_GUI_LIB
