/* The main file of the application
 * 
 *
 */
#include <Arduino.h>
#include "Callback.h"
#include "MMIHandler.h"
#include "Event.h"
#include "RotaryEncoderInterface.h"

// loop counter
uint32_t counter = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // setup the interrupts for both rotary encoders
  setupRotaryEncoderInterrupts();

  // setup the MMI handler
  mmiHandler.setup();
  
  Serial.println("Setup done");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  counter++;
  Serial.print(counter);
  Serial.println(" -*-");

  mmiHandler.update();

  delay(1000);
}