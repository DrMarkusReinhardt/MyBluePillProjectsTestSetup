#include <Arduino.h>

#define MeasurementPin A0
uint32_t singleADCValue;
uint32_t averageADCValue;
const uint32_t noAverages = 50;
float averagedResult;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Initialize the DC input pin
  pinMode(MeasurementPin, INPUT);

  // change the resolution of the ADC
  analogReadResolution(12);

  Serial.println("Setup done");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  averageADCValue = 0;
  for(uint8_t k = 0; k < noAverages; k++)
  {
    singleADCValue = analogRead(MeasurementPin);
    // Serial.print("single ADC value = ");Serial.println(singleADCValue);
    averageADCValue += singleADCValue;
    delay(50);
  }
  // Serial.print("accumulated ADC value = ");Serial.println(averageADCValue);
  averagedResult =(float)averageADCValue / (float)noAverages;
  Serial.print("float averaged ADC value = ");Serial.println(averagedResult);

  delay(1000);
}
