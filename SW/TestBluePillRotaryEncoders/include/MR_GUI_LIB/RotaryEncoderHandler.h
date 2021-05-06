/**
 * RotaryEncoderHandler.h
 *
 * @brief The base class of a rotary encoder handler
 *
 * The base class of a rotary encoder handler.
 * It emits a signal when the rotary encoder is turned and calls the notifyTurn() function
 * It emits a signal when the rotary encoder key is pressed and calls the notifyKeyPress() function
 * It provides the means to attach / connect slots that receive the signals.
 * Derived classes have to create the attach function to attach specific slot classes with specific slot member functions
 * to the signals
 *
 * @author Dr. Markus Reinhardt
 *
 * @date Dec. 2020
 *
 */
#pragma once

#include "Callback.h"
#include "RotaryEncoder.h"

namespace MR_GUI_LIB
{

class RotaryEncoderHandler
{
public:
  /// constructor
  RotaryEncoderHandler(String id, MR_GUI_LIB::RotaryEncoder *initRotEnc) 
  : m_id(id), m_rotEnc(initRotEnc)
  {
    m_rotationValue = 0;
    m_oldRotationValue = 0;
    m_noKeyHits = 0;
    m_oldNoKeyHits = 0;
  }

  /// setup routine
  void setup(MR_GUI_LIB::RotaryEncoder *initRotEnc)
  {
    m_rotEnc = initRotEnc;
  }

  /// check if the rotary encoder was turned
  bool checkTurned()
  {
    return m_rotEnc->checkTurned();
  }

  /// get the rotary encoder turn direction
  TurnDirection getTurnDirection()
  {
    return m_rotEnc->getTurnDirection();
  }

  /// get the rotary encoder turn direction as a string
  String getTurnDirectionString()
  {
    return m_rotEnc->getTurnDirectionString();
  }

  /// check if the rotary encoder key was pressed
  bool checkKeyPressed()
  {
    return m_rotEnc->checkKeyPressed();
  }

  /// get rotation value from last turn
  int16_t getRotationValue()
  {
    m_rotationValue = m_rotEnc->getRotationValue();
    return m_rotationValue;
  };

  /// get key hits value
  uint16_t getKeyHitsValue()
  {
    m_noKeyHits = m_rotEnc->getSwitchVariable();
    return m_noKeyHits;
  }

  /// notify widgets when the rotary encoder is turned
  void notifyTurn()
  {  
    // create the turn event
    String evString("Turn");
    evString += String(m_id);
    Event<int16_t>  ev(evString, getRotationValue());

    // emit the turn signal sending the event
    turnSignal.Emit(ev);
  }

  /// notify widgets when the key is pressed
  void notifyKeyPress()
  {    
    // create the key press event
    String evString("KeyPress");
    evString += String(m_id);
    Event<uint16_t>  ev(evString, getKeyHitsValue());
    
    // emit the key press signal sending the event
    keyPressSignal.Emit(ev);
  }

  /// the signal with argument when the rotary encoder is turned
  Signal< Event<int16_t> > turnSignal;

  /// the signal with argument when the rotary encoder key is pressed
  Signal< Event<uint16_t> > keyPressSignal;

protected:
  String m_id;
  MR_GUI_LIB::RotaryEncoder *m_rotEnc;
  int16_t m_rotationValue;
  int16_t m_oldRotationValue;
  uint16_t m_noKeyHits;
  uint16_t m_oldNoKeyHits;
};

} // namespace MR_GUI_LIB
