/**
 **************************************************
 *
 * @file        SettingBaseline.ino
 * @brief       This example shows use of baseline register
 *              To use this properly, wait until sensor is burned in, warmed up and in cleam air.
 *              Afterwards ,the sensor can be used in dirty air and 
 *              the baseline can be restored from EEPROM to stabilise sensor faster
 *
 * @authors     @ soldered.com
 * @copyright   [MIT License](http://opensource.org/licenses/MIT)
 *              www.Solde.red/333009
 ***************************************************/
#include <Wire.h>
#include "CCS811-SOLDERED.h"
#include <EEPROM.h>

CCS_811 ccsSensor;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("CCS811 Setting Baseline Example");

  Wire.begin();

  //This begins the CCS811 sensor and prints error status of .beginWithStatus()
  CCS_811::CCS811_Status_e returnCode = ccsSensor.beginWithStatus();
  Serial.print("CCS811 begin exited with: ");
  //Pass the error code to a function to print the results
  Serial.print(ccsSensor.statusString(returnCode));
  Serial.println();

  //This looks for previously saved data in the eeprom at program start
  if ((EEPROM.read(0) == 0xA5) && (EEPROM.read(1) == 0xB2))
  {
    Serial.println("EEPROM contains saved data.");
  }
  else
  {
    Serial.println("Saved data not found!");
  }
  Serial.println();

  Serial.println("Program running.  Send the following characters to operate:");
  Serial.println(" 's' - save baseline into EEPROM");
  Serial.println(" 'l' - load and apply baseline from EEPROM");
  Serial.println(" 'c' - clear baseline from EEPROM");
  Serial.println(" 'r' - read and print sensor data");
}

void loop()
{
  char c;
  unsigned int result;
  unsigned int baselineToApply;
  CCS_811::CCS811_Status_e errorStatus;
  if (Serial.available())
  {
    c = Serial.read();
    switch (c)
    {
    case 's':
      //This gets the latest baseline from the sensor
      result = ccsSensor.getBaseline();
      Serial.print("baseline for this sensor: 0x");
      if (result < 0x100)
        Serial.print("0");
      if (result < 0x10)
        Serial.print("0");
      Serial.println(result, HEX);
      //The baseline is saved (with valid data indicator bytes)
      EEPROM.write(0, 0xA5);
      EEPROM.write(1, 0xB2);
      EEPROM.write(2, (result >> 8) & 0x00FF);
      EEPROM.write(3, result & 0x00FF);
      break;
    case 'l':
      if ((EEPROM.read(0) == 0xA5) && (EEPROM.read(1) == 0xB2))
      {
        Serial.println("EEPROM contains saved data.");
        //The recovered baseline is packed into a 16 bit word
        baselineToApply = ((unsigned int)EEPROM.read(2) << 8) | EEPROM.read(3);
        Serial.print("Saved baseline: 0x");
        if (baselineToApply < 0x100)
          Serial.print("0");
        if (baselineToApply < 0x10)
          Serial.print("0");
        Serial.println(baselineToApply, HEX);
        //This programs the baseline into the sensor and monitors error states
        errorStatus = ccsSensor.setBaseline(baselineToApply);
        if (errorStatus == CCS_811::CCS811_Stat_SUCCESS)
        {
          Serial.println("Baseline written to CCS811.");
        }
        else
        {
          Serial.print("Error writing baseline: ");
          Serial.println(ccsSensor.statusString(errorStatus));
        }
      }
      else
      {
        Serial.println("Saved data not found!");
      }
      break;
    case 'c':
      //Clear data indicator and data from the eeprom
      Serial.println("Clearing EEPROM space.");
      EEPROM.write(0, 0x00);
      EEPROM.write(1, 0x00);
      EEPROM.write(2, 0x00);
      EEPROM.write(3, 0x00);
      break;
    case 'r':
      if (ccsSensor.dataAvailable())
      {
        //Simply print the last sensor data
        ccsSensor.readAlgorithmResults();

        Serial.print("CO2[");
        Serial.print(ccsSensor.getCO2());
        Serial.print("] tVOC[");
        Serial.print(ccsSensor.getTVOC());
        Serial.print("]");
        Serial.println();
      }
      else
      {
        Serial.println("Sensor data not available.");
      }
      break;
    default:
      break;
    }
  }
  delay(10);
}
