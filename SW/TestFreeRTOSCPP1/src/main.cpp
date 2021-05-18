#include <Arduino.h>
#include "STM32FreeRTOSConfig.h"
#include <STM32FreeRTOS.h>
#include "RAMAllocation.h"
#include "MyTaskClass.h"
#include "TaskDefinitions.h"
#include "task.h"

// print the init message and start the task scheduler
void setup() 
{
  Serial.begin(9600);

  // put your setup code here, to run once:
  Serial.println("Testing FreeRTOS C++ wrapper");
  Serial.println("Simple Tasks");
  
  // setup two tasks
  Task1 task1((const char *)"task1", MyTaskPriority::MyTaskPrio_Low, 128);
  Task2 task2((const char *)"task2", MyTaskPriority::MyTaskPrio_High, 128);
  delay(1000);
  // and start them
  task1.start();
  task2.start();

  // start the task scheduler
  vTaskStartScheduler();

  Serial.println("How did we get there ?");
  //  We shouldn't ever get here
  while(1);
}

void loop() 
{
  // Empty. Things are done in Tasks
}
