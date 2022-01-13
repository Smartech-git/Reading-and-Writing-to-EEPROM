#include <Arduino.h>

#include <EEPROM.h>

void writeStringToEEPROM(byte addrOffset, String strToWrite) {
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);

  for (int i = 0; i < len; i++) {
    EEPROM.write( addrOffset + 1 + i, strToWrite[i]);
  }
}

String readStringFromEEPROM(byte addrOffset) {
  byte newStrlen = EEPROM.read(addrOffset);
  char data[newStrlen + 1];

  for(int i=0; i < newStrlen; i++) {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrlen] = '\0';
  return String(data);
}
