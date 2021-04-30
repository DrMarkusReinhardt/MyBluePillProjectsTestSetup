/* LCD16x4.h
 * 
 * The driver for a 16x4 character LCD derived from LiquidCrystal_I2C
 * 
 * 
 */
#pragma once

#include "Arduino.h"
#include "LiquidCrystal_PCF8574.h"
#include <Wire.h>

namespace MR_GUI_LIB
{

class LCD16x4 : public LiquidCrystal_PCF8574
{
public:
  LCD16x4() : LiquidCrystal_PCF8574(0x27)
  {
  };

  void begin()
  {
    LiquidCrystal_PCF8574::begin(16,4);
    LiquidCrystal_PCF8574::home();
    LiquidCrystal_PCF8574::clear();
    LiquidCrystal_PCF8574::setBacklight(255);
    LiquidCrystal_PCF8574::cursor();
    LiquidCrystal_PCF8574::blink();
    LiquidCrystal_PCF8574::setCursor(0,0);
  }  
};

} // namespace MR_GUI_LIB
