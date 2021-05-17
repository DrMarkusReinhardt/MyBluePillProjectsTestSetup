/**  MMIHandler.h
*    The handler of the application's MMI
* 
*
*/
#pragma once

#include "Arduino.h"
#include "RotaryEncoderHandler1.h"
#include "RotaryEncoderHandler2.h"
#include "RotaryEncoderSlotsAbstractBase1.h"
#include "RotaryEncoderSlotsAbstractBase2.h"
#include "TestRotaryEncoderSlot.h"

namespace MR_LiPo_Charger
{

class MMIHandler
{
public:
   /// the constructor
   MMIHandler(MR_GUI_LIB::RotaryEncoderHandler1 *reh1, MR_GUI_LIB::RotaryEncoderHandler2 *reh2) 
   : m_reh1(reh1), m_reh2(reh2)
   {
      m_testSlot1 = new MR_GUI_LIB::TestRotaryEncoderSlot("RotEnc1TestSlot");
   }

   /// setup the whole MMI including signals and slots
   void setup()
   {
     // attach the slots of the rotary encoder 1
     m_reh1->attachKeyPressSignal2EventSlot(m_testSlot1);
     m_reh1->attachTurnDirectionSignal2EventSlot(m_testSlot1);

     // attach the slots of the rotary encoder 2
     m_reh2->attachKeyPressSignal2EventSlot(m_testSlot1);
     m_reh2->attachTurnDirectionSignal2EventSlot(m_testSlot1);
   }

   void update()
   {
     // check all rotary encoder actions and notify the slots
     if (m_reh1->checkKeyPressed())
       m_reh1->notifyKeyPress();
     if (m_reh1->checkTurned())
       m_reh1->notifyTurnDirection();
     if (m_reh2->checkKeyPressed())
       m_reh2->notifyKeyPress();
     if (m_reh2->checkTurned())
       m_reh2->notifyTurnDirection();
   }

private:
  MR_GUI_LIB::RotaryEncoderHandler1 *m_reh1;
  MR_GUI_LIB::RotaryEncoderHandler2 *m_reh2;
  MR_GUI_LIB::TestRotaryEncoderSlot *m_testSlot1;
};

} // namespace MR_LiPo_Charger