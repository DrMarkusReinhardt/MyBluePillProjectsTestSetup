/* Arduino class to implement the task for the charge control
 * 
 * @author: Dr. Markus Reinhardt
 * @date: April 2021
 * 
 */
#pragma once

#include "Arduino.h"
#include "Print.h"
#include <Callback.h>
#include <Task.h>
#include <TaskScheduler.h>
#include "ApplicationParameters.h"
#include "ChargeHandler.h"
#include "MMIHandler.h"

// Timed task to do the charge control
class ChargeControlTask : public TimedTask
{
  public:
    ChargeControlTask(uint32_t rate, MR_GUI_LIB::MMI_FSM *mmi, MR_LiPo_Charger::ApplicationParameters *appParams);
    void updateChargeControl();                   // execute the charge control algorithms
    virtual void run(uint32_t now);   // run again in the required number of milliseconds

  private:
    uint32_t m_rate;        // repetition rate
    MR_GUI_LIB::MMIHandler *m_mmiHandler;
    MR_LiPo_Charger::ApplicationParameters *m_appParams;
    MR_LiPo_Charger::ChargeHandler *m_chargeHandler;
    
};


ChargeControlTask::ChargeControlTask(uint32_t rate, MR_GUI_LIB::MMIHandler *mmiHandler, MR_LiPo_Charger::ApplicationParameters *appParams)
: TimedTask(millis()),
  m_rate(rate), m_mmiHandler(mmiHandler), m_appParams(appParams)
{
  // create the charge handler
  m_chargeHandler = new MR_LiPo_Charger::ChargeHandler(appParams);
}

// update the MMI
void updateMMI()
{

}

// execute the charge control algorithms
void ChargeControlTask::updateChargeControl()
{
  m_chargeHandler->exec();
}

void ChargeControlTask::run(uint32_t now)
{
  // update the MMI
  updateMMI();

  // execute the charge control algorithms
  updateChargeControl();
  
  // run again in the required number of milliseconds
  incRunTime(m_rate);
}

