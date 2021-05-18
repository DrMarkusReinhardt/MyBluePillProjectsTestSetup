#ifndef MyFreeRTOSTask_H
#define MyFreeRTOSTask_H

#include "Arduino.h"
#include "STM32FreeRTOS.h"
#include "task.h"

#define MAX_NAME_LENGTH 20

enum MyTaskPriority {
	MyTaskPrio_Idle = 0,													///< Non-Real Time operations. tasks that don't block
	MyTaskPrio_Low = ((configMAX_PRIORITIES)>1),                         	///< Non-Critical operations
	MyTaskPrio_HMI = (MyTaskPrio_Low + ((configMAX_PRIORITIES)>5)),			///< Normal User Interface Level
	MyTaskPrio_Mid = ((configMAX_PRIORITIES)/2),							///< Semi-Critical, have deadlines, not a lot of processing
	MyTaskPrio_High = ((configMAX_PRIORITIES)-1-((configMAX_PRIORITIES)>4)),///< Urgent tasks, short deadlines, not much processing
	MyTaskPrio_Highest = ((configMAX_PRIORITIES)-1) 						///< Critical Tasks, Do NOW, must be quick (Used by FreeRTOS)
};

class MyTaskClass
{
public:
  MyTaskClass(char const *name, MyTaskPriority priority,
              unsigned portSHORT stackSize, void * myParm = 0) : priority_(priority), stackSize_(stackSize)
  { 
    Serial.println("MyTask constructor");

    // copy the name to the private variable
    for (int i = 0; i < configMAX_TASK_NAME_LEN - 1; i++) 
    {
        name_[i] = *name;
        if (*name == 0)
            break;
        name++;
    }
    name_[configMAX_TASK_NAME_LEN - 1] = 0;      
  }

  void start()
  {
    xTaskCreate(TaskFunctionAdapter, name_, stackSize_, this, priority_, &taskHandle); 
  }

  virtual void exec() = 0;

protected:  
  TaskHandle_t taskHandle;
  char name_[MAX_NAME_LENGTH];

private:
  MyTaskPriority priority_;
  unsigned portSHORT stackSize_;
  // Adapter function that allows you to write a class specific task() function that interfaces with FreeRTOS.
  static void TaskFunctionAdapter(void *pvParameters);

  StaticTask_t tcb;
  StackType_t stack[128];
};

void MyTaskClass::TaskFunctionAdapter(void *pvParameters)
{
    MyTaskClass *mytask = static_cast<MyTaskClass*>(pvParameters);
    mytask->exec();
}


#endif