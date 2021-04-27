/**************************************************************************/
/*!
    This example will wait for any ISO14443A card or tag, and
    depending on the size of the UID will attempt to read from it.

    If the card has a 4-byte UID it is probably a Mifare
    Classic card, and the following steps are taken:

    - Authenticate block 4 (the first block of Sector 1) using
      the default KEYA of 0XFF 0XFF 0XFF 0XFF 0XFF 0XFF
    - If authentication succeeds, we can then read any of the
      4 blocks in that sector (though only block 4 is read here)

    If the card has a 7-byte UID it is probably a Mifare
    Ultralight card, and the 4 byte pages can be read directly.
    Page 4 is read by default since this is the first 'general-
    purpose' page on the tags.

    To enable debug message, define DEBUG in PN532/PN532_debug.h
*/
/**************************************************************************/

#if 0
#include <SPI.h>
#include <PN532_SPI.h>
#include "PN532.h"

PN532_SPI pn532spi(SPI, 10);
PN532 nfc(pn532spi);
#elif 1
#include <PN532_HSU.h>
#include <PN532.h>

PN532_HSU pn532hsu(Serial1);
PN532 nfc(pn532hsu);
#else
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
PN532_I2C pn532i2c(Wire);
PN532 nfc(pn532i2c);
#endif
void setup(void) {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("E-I");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  // Got ok data, print it out!
  //Serial.print("Found chip PN5"); Serial.println((versiondata >> 24) & 0xFF, HEX);
  //Serial.print("Firmware ver. "); Serial.print((versiondata >> 16) & 0xFF, DEC);
  //Serial.print('.'); Serial.println((versiondata >> 8) & 0xFF, DEC);

  // configure board to read RFID tags
  nfc.SAMConfig();

  Serial.println("Standing by to identify object");
}


void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    // Display some basic information about the card
    Serial.println("Object identified");
//    Serial.print("  UID Length: "); Serial.print(uidLength, DEC); Serial.println(" bytes");
//    Serial.print("  UID Value: ");
//    nfc.PrintHex(uid, uidLength);
//    Serial.println("");

    if (uidLength == 7)
    {

      String code = String(uid[0]);
      code += String(uid[1]);
      code += String(uid[2]);
      code += String(uid[3]);
      code += String(uid[4]);
      code += String(uid[5]);
      code += String(uid[6]);

      //Serial.print("code = ");
      //Serial.println(code);

      if (code == "449187122243103129") {
        
        Serial.println("Object 1");
      
      } 
      
      else if (code == "433187122243103129") {

        Serial.println("Object 2");

      }

      else if (code == "457187122243103129") {

        Serial.println("Object 3");

      }      

      // We probably have a Mifare Ultralight card ...
      // Serial.println("Seems to be a Mifare Ultralight tag (7 byte UID)");

      // Try to read the first general-purpose user page (#4)
      // Serial.println("Reading page 4");
      uint8_t data[32];
      success = nfc.mifareultralight_ReadPage (4, data);
      if (success)
      {
        // Data seems to have been read ... spit it out
        //nfc.PrintHexChar(data, 4);
        //Serial.println("");

        // Wait a bit before reading the card again
        delay(1000);
      }
      else
      {
        Serial.println("Ooops ... object not known.");
      }
    }
  }
}
