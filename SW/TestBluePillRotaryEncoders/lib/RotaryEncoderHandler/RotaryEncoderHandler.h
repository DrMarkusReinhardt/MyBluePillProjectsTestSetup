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
  RotaryEncoderHandler(const char* initName) : name_(initName)
  {
    rotationValue_ = 0;
    oldRotationValue_ = 0;
    noKeyHits_= 0;
    oldNoKeyHits_= 0;
  };

  /// setup routine
  void setup(MR_GUI_LIB::RotaryEncoder *initRotEnc, uint8_t initPinA, uint8_t initPinB, uint8_t initPinE)
  {
    rotEnc_ = initRotEnc;
    // activate the pins for the rotary encoder and reset the counters
    rotEnc_->setup(initPinA, initPinB, initPinE);
  };

  /// check if the rotary encoder was turned
  bool checkTurned()
  {
    noInterrupts();
    bool checkResult;
    // Serial.println("checkTurned");
    rotationValue_ = rotEnc_->getRotationVariable();
    // Serial.print("rotation value = "); Serial.println(rotationValue_);
    if (rotationValue_ != oldRotationValue_)
      checkResult = true;
    else
      checkResult =  false;
    interrupts();
    return checkResult;
  };

  /// check the rotary encoder turn direction
  bool checkTurnDirection()
  {
    noInterrupts();
    bool checkResult;
    rotationValue_ = rotEnc_->getRotationVariable();
    if (rotationValue_ > oldRotationValue_)
    {
      oldRotationValue_ = rotationValue_;
      checkResult = true;  // CW
    }
    else
    {
      oldRotationValue_ = rotationValue_;
      checkResult =  false; // CCW
    }
    interrupts();
    return checkResult;
  };

  /// check if the rotary encoder key was pressed
  bool checkKeyPressed()
  {
    noInterrupts();
    bool checkResult;
    noKeyHits_ = rotEnc_->getSwitchVariable();
    if (noKeyHits_ != oldNoKeyHits_)
    {
      oldNoKeyHits_ = noKeyHits_;
      checkResult =  true;
    }
    else
    {
      oldNoKeyHits_ = noKeyHits_;
      checkResult =  false;
    }
    interrupts();
    return checkResult;
  };

  /// get rotation value from last turn
  int16_t getRotationValue()
  {
    return rotationValue_;
  };

  /// get key hits value
  uint16_t getKeyHitsValue()
  {
    return noKeyHits_;
  };

  /// notify widgets when the rotary encoder is turned
  void notifyTurn(int16_t rehDirection)
  {
    noInterrupts();
    
    // create the turn event
    String evString("Turn");
    evString += String(name_);
    Event<int16_t>  ev(evString, rehDirection);
    
    turnSignal.Emit(ev);
    interrupts();
  };

  /// notify widgets when the key is pressed
  void notifyKeyPress()
  {
    noInterrupts();
    
    // create the key press event
    String evString("KeyPress");
    evString += String(name_);
    Event<uint16_t>  ev(evString, noKeyHits_);
    
    // emit the key press signal
    keyPressSignal.Emit(ev);
    interrupts();
  };

  /// the signal with argument when the rotary encoder is turned
  Signal< Event<int16_t> > turnSignal;

  /// the signal with argument when the rotary encoder key is pressed
  Signal< Event<uint16_t> > keyPressSignal;

protected:
  const char* name_;
  int16_t rotationValue_;
  int16_t oldRotationValue_;
  uint16_t noKeyHits_;
  uint16_t oldNoKeyHits_;
  MR_GUI_LIB::RotaryEncoder *rotEnc_;
};

} // namespace MR_GUI_LIB
