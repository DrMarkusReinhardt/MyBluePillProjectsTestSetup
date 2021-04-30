/* TestBluePillI2C.ino
 * Test the 16x4 character LCD controlled via the I2C interface
 * from the Blue Pill STM32 board
 * 
 * @author: Dr. Markus Reinhardt
 * @date:   30th April 2021
*/
#include <Arduino.h>
#include "LCD16x4.h"

using namespace MR_GUI_LIB;

// setup the LCD driver
LCD16x4 lcd;

void setup()
{
  // put your setup code here, to run once:
  lcd.begin();                      // initialize the lcd 
  // Print messages to the LCD.
  lcd.print("Hallo, Markus!");
  lcd.setCursor(0,1);
  lcd.print("LCD Test");
  lcd.setCursor(0,2);
  lcd.print("16 characters");
  lcd.setCursor(0,3);
  lcd.print("Line 4");
  delay(2000);
}

void loop()
{
  // clear LCD and then fill all 4 lines repeatedly
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ABCDEFGHIJKLMNOP");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("0123456789012345");
  delay(1000);
  lcd.setCursor(0,2);
  lcd.print("abcdefghijklmnop");
  delay(1000);
  lcd.setCursor(0,3);
  lcd.print(",;.:-_?^!$%&/()=");
  delay(2000);
}
