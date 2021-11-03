/**
 * @file nxyi2c-10-digits-demo.ino
 * @author Takeshi Mori
 * @brief A sample of each tube given a different lighting pattern
 * 
 * @copyright Copyright (c) 2021 Takeshi Mori All Rights reserved.
 * 
 */
#include <Wire.h>
#include "from_nxyi2c_default.h"

// configuration
#define I2CADDR(INDEX) (21+INDEX) // I2C address (DEC) => from 21 to 30
#define PATTERN_DURATION (100)
const unsigned short TUBES_COUNT = 10;

// globals
NXYI2C_CMD g_cmd;

void sendCommand(const int dest_addr, const NXYI2C_CMD cmd)
{
  Wire.beginTransmission(dest_addr);
  Wire.write((unsigned char *)(&cmd), sizeof(cmd));
  Wire.endTransmission();
}

void turn_on_at(const int addr, const unsigned short number) {
  // set pattern
  g_cmd.command = nxyi2c_set_pattern;
  g_cmd.value = nxyi2c_pattern_fade_in;
  sendCommand(addr, g_cmd);

  // set number
  g_cmd.command = nxyi2c_set_number;
  g_cmd.value = number;
  sendCommand(addr, g_cmd);

  // start
  g_cmd.command = nxyi2c_start;
  sendCommand(addr, g_cmd);
}

void turn_off_at(const int addr) {
  // set pattern
  g_cmd.command = nxyi2c_set_pattern;
  g_cmd.value = nxyi2c_pattern_fade_out;
  sendCommand(addr, g_cmd);

  // start
  g_cmd.command = nxyi2c_start;
  sendCommand(addr, g_cmd);
}

void from_right_to_left_in(const int start_addr, const int end_addr, const unsigned short number) {
  for (int addr = end_addr; addr > start_addr; addr--) {
    turn_off_at(addr);
    turn_on_at(addr - 1, number);
    delay(PATTERN_DURATION);
  }
}

void from_right_to_left_out(const int start_addr, const int end_addr, const unsigned short number) {
  for (int addr = end_addr; addr >= start_addr; addr--) {
    if (addr - 1 >= start_addr) {
      turn_on_at(addr - 1, number);
    }
    turn_off_at(addr);
    delay(PATTERN_DURATION);
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("START setup()");

  // Please wait until the NXYI2C self-check process is complete
  delay(8000);
  Serial.println("START WIRE");

  Wire.begin();

  // set duration of pattern to all NXYI2Cs
  g_cmd.command = nxyi2c_set_duration;
  g_cmd.value = PATTERN_DURATION;
  for (unsigned short index = 0; index < TUBES_COUNT; index++) {
    sendCommand(I2CADDR(index), g_cmd);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 10; i++) {
    from_right_to_left_in(I2CADDR(i), I2CADDR(10), i);
  }
  delay(1000);
  for (int i = 0; i <= 10; i++) {
    from_right_to_left_out(I2CADDR(0), I2CADDR(i), i);
  }
  delay(1000);
}
