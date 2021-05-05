
/******************************************************************************************************************************************
  EEPROM_put.ino
  For STM32 using Flash emulated-EEPROM

  The FlashStorage_STM32 library aims to provide a convenient way to store and retrieve user's data using the non-volatile flash memory
  of STM32F/L/H/G/WB/MP1. It's using the buffered read and write to minimize the access to Flash.
  It now supports writing and reading the whole object, not just byte-and-byte.

  Inspired by Cristian Maglie's FlashStorage (https://github.com/cmaglie/FlashStorage)

  Built by Khoi Hoang https://github.com/khoih-prog/FlashStorage_STM32
  Licensed under MIT license
  Version: 1.1.0

  Version Modified By   Date        Comments
  ------- -----------  ----------   -----------
  1.0.0   K Hoang      26/01/2021  Initial coding to support STM32F/L/H/G/WB/MP1 using emulated-EEPROM
  1.0.1   K Hoang      23/02/2021  Fix compiler warnings.
  1.1.0   K Hoang      26/04/2021  Add support to new STM32 core v2.0.0 and new STM32L5 boards.
 ******************************************************************************************************************************************/
/***
    eeprom_put example.

    This shows how to use the EEPROM.put() method. Also, this sketch will pre-set the EEPROM data
    for the example sketch eeprom_get.

    Note, unlike the single byte version EEPROM.write(), the put method will use update semantics. As in a byte
    will only be written to the EEPROM if the data is actually different.

    Written by Christopher Andrews 2015
    Released under MIT licence.
***/
#include <Arduino.h>
#include <FlashStorage_STM32.h>

struct MyObject
{
  float field1;
  byte field2;
  char name[10];
};

void setup()
{
  Serial.begin(9600);
  // while (!Serial);

  delay(200);

  Serial.print(F("\nStart EEPROM_put on ")); Serial.println(BOARD_NAME);
  Serial.println(FLASH_STORAGE_STM32_VERSION);

  Serial.print("EEPROM length: ");
  Serial.println(EEPROM.length());

  float f = 123.456f;  //Variable to store in EEPROM.
  int eeAddress = 0;   //Location we want the data to be put.

  //One simple call, with the address first and the object second.
  EEPROM.put(eeAddress, f);

  Serial.println("Written float data type!");

  /** Put is designed for use with custom structures also. **/

  //Data to store.
  MyObject customVar =
  {
    3.14159f,
    65,
    "Working!"
  };

  eeAddress += sizeof(float); //Move address to the next byte after float 'f'.

  EEPROM.put(eeAddress, customVar);
  Serial.print("Written custom data type!");

  Serial.println("Setup done");
  delay(5000);
}

void loop()
{
  /* Empty loop */
  Serial.println("Get Data from EEPROM:\n");
  int eeAddress = 0;
  float f;

  //Get the float data from the EEPROM at position 'eeAddress'
  EEPROM.get(eeAddress, f);
  Serial.println(f, 3);    //This may print 'ovf, nan' if the data inside the EEPROM is not a valid float.

  // get custom data type from EEPROM
  eeAddress = sizeof(float); //Move address to the next byte after float 'f'.

  MyObject customVar; //Variable to store custom object read from EEPROM.
  EEPROM.get(eeAddress, customVar);

  Serial.println("Read custom object from EEPROM: ");
  Serial.println(customVar.field1, 5);
  Serial.println(customVar.field2);
  Serial.println(customVar.name);

  delay(5000);
}
