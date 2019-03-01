#include <PN532_I2C.h>
#include <NfcAdapter.h>
#include <Wire.h>
#include <PN532.h>
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
void setup() {
  Serial.begin(9600);
  Serial.println("NFC TAG AUTHENTICATOR"); 
  nfc.begin();

}

void loop() {
  Serial.println("\nScan your NFC tag to authenticate yourself\n");
  if(nfc.tagPresent())
  {
    NfcTag tag = nfc.read();
    String id = tag.getUidString(); 
    if(id == "92 0E ED 39")
    {
      Serial.println("----Authentication Successful----");
      
    }
    else{
      Serial.println("----Authentication Failed----");
    }
  }
  delay(5000);
}
