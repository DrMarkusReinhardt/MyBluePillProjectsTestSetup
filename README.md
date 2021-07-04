# MyBluePillProjectsTestSetup

Several small projects to demonstrate HW and SW concepts in a
breadboard setup with a STM32 "Blue Pill" board.

The PlatformIO extension within the VSCode IDE using the Arduino environment was used
to develop all test and demo programs.

For programming the "Blue Pill" board the low-cost ST-Link V2 programming dongle was used and for
serial communication with the Arduino Serial Monitor within the IDE a
USB/Serial dongle was used.

The following features of the board were tested:
- Project 1: Usage of the module with the USB/Serial adapter
- Project 1: Usage of the PlatformIO IDE
- Project 2: Usage of a 16x4 character LCD with I2C adapter.
- Project 3: Usage of rotary encoders connected to the board supported by hardware interrupts.
- Project 4: Usage of the ADC with different resolutions.
- Project 5: Usage of PWM.
- Project 6: Usage of flash data storage and retrieval (to emulate EEPROM storage and retrieval)
- Project 7: Usage of FreeRTOS (C-Variant)
- Project 8: Usage of FreeRTOS (C++-Wrapper)