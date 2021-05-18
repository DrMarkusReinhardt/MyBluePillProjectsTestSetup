#pragma once

#include "Arduino.h"
#include "MyTaskClass.h"

class Task1 : public MyTaskClass
{
public:
  Task1(char const *name, MyTaskPriority priority,
        unsigned portSHORT stackSize, void * myParm = 0) : MyTaskClass(name,priority,stackSize)
    { }

  void exec()
  {
    for(;;)
    {
      Serial.print(name_); Serial.println("::exec()");
      vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    }
  }
};

class Task2 : public MyTaskClass
{
public:
  Task2(char const *name, MyTaskPriority priority,
        unsigned portSHORT stackSize, void * myParm = 0) : MyTaskClass(name,priority,stackSize)
  { }

  void exec()
  {
    for (;;)
    {
        Serial.print(name_); Serial.println("::exec()");
        // read the input on analog pin 0:
        int sensorValue = analogRead(A0);
        // print out the value you read:
        Serial.println(sensorValue);
        vTaskDelay( 1000 / portTICK_PERIOD_MS );  // one tick delay (15ms) in between reads for stability
    } 
  }
};