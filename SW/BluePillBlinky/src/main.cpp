#include <Arduino.h>

void setup() 
{
  // put your setup code here, to run once:
  Serial1.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial1.println("Setup done");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial1.print(".");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}