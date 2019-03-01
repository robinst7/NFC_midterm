#include <PN532_I2C.h>
#include <NfcAdapter.h>
#include <Wire.h>
#include <PN532.h>
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
void setup() {
  Serial.begin(9600);
  nfc.begin();

}

void loop() {
  Serial.println("\nScan your NFC tag that you wish to clear\n");
  if(nfc.tagPresent())
  {
    boolean success = nfc.erase(); //The erase function cleans the tag by putting an empty NDEF message on it. 
    if(success){
      Serial.println("Good job, your NFC tag now contains an empty record");
      
    }else{
      Serial.println("Unable to clear tag");
    }

    
  }
delay(10000);
}
