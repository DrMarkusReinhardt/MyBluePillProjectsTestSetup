#include <Arduino.h>

#define PWMPin A1

void writePWM(uint8_t pwmValue)
{
  analogWrite(PWMPin,pwmValue);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // Initialize the PWM output pin
  pinMode(PWMPin, OUTPUT);

  Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint8_t dutyCycle = 0; dutyCycle <= 100; dutyCycle++)
  {
    Serial.print("Duty cycle = ");Serial.println(dutyCycle);
    writePWM((uint8_t)(dutyCycle*2.55));
    delay(1000);
  }
  Serial.println("New loop");
  
  delay(1000);
}
