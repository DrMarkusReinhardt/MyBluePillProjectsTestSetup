#ifndef BLINKER_TASK_H
#define BLINKER_TASK_H

#include <Arduino.h>
#include <Task.h>
#include <TaskScheduler.h>

// Timed task to blink a LED.
class BlinkerTask : public TimedTask
{
public:
    // Create a new blinker for the specified pin and rate.
    BlinkerTask(uint8_t _pin, uint32_t _rate);
    virtual void run(uint32_t now);
private:
    uint8_t pin;      // LED pin.
    uint32_t rate;    // Blink rate.
    bool on;          // Current state of the LED.
};

BlinkerTask::BlinkerTask(uint8_t _pin, uint32_t _rate)
: TimedTask(millis()),
  pin(_pin),
  rate(_rate),
  on(false)
{
    pinMode(pin, OUTPUT);     // Set pin for output.
}

void BlinkerTask::run(uint32_t now)
{
    // If the LED is on, turn it off and remember the state.
    if (on) {
        digitalWrite(pin, LOW);
        on = false;
    // If the LED is off, turn it on and remember the state.
    } else {
        digitalWrite(pin, HIGH);
        on = true;
    }
    
    // Run again in the required number of milliseconds.
    incRunTime(rate);
}

#endif

