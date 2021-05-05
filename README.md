# MyBluePillProjectsTestSetup

Several sub-projects to demonstrate HW and SW concepts tested in a
breadboard setup with a STM32 "Blue Pill" board.

The PlatformIO IDE within the VSCode IDE using the Arduino environment was used
to develop all programs.
For programming the board the ST-Link V2 programming dongle was used and for
serial communication with the Arduino Serial Monitor within the IDE a
USB/Serial dongle was used.

The following features of the board were tested:
- Usage of the on-board LED.
- Usage of a 16x4 character LCD with I2C adapter.
- Usage of rotary encoders connected to the board supported by hardware interrupts.
- Usage of the ADC with different resolutions.
- Usage of PWM.
- Usage of flash data storage and retrieval (to emulate EEPROM storage and retrieval)
