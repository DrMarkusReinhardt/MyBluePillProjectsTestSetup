/**
 * RotaryEncoder.h
 *
 * @brief Rotary Encoder library for a rotary encoder
 *
 * Rotary Encoder library for a rotary encoder
 *
 * History: Dr. M. Reinhardt, June 8th 2019
 *          first implementation and fully tested, working perfectly
 *
 * @author Dr. Markus Reinhardt
 *
 * @date June 2019
 */
#pragma once

#include <Arduino.h>

namespace MR_GUI_LIB
{

class RotaryEncoder
{
public:
  RotaryEncoder();

  /// get the value of the rotation
  int8_t getRotationVariable();

  /// get the value of the switch
  uint8_t getSwitchVariable();

  void EncoderFunctionB();

  void EncoderFunctionE();

  /// reset the rotation value and the switch value
  void reset();

  /// disable the rotary encoder
  void disable(uint8_t pinA, uint8_t pinB, uint8_t pinE);

  /// activate the rotary encoder pins and reset the counters
  void setup(uint8_t pinA, uint8_t pinB, uint8_t pinE);


private:
  uint8_t pinA;
  uint8_t pinB;
  uint8_t pinE;

  volatile int8_t RotationVariable;
  volatile uint8_t SwitchVariable;
};

} // namespace MR_GUI_LIB
