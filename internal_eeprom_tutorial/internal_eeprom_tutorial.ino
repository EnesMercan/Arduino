// EEPROM tutorial
// You can store only 1 byte size data each cell in EEPROM
// EEPROM memory 256 byte genisligindedir. Yani 0-255 arasi adresleme yapabilirisin
// EEPROM verilerini okumak icin '1' e bas...

#include <EEPROM.h>

uint8_t firstData = 0;
uint8_t secData = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i<=255; i++)
  {

    EEPROM.write(i, i+10);
    delay(3);
  }

  Serial.println("Writing done!");
  Serial.println();

}

void loop() {
  

  if (Serial.available() > 0)
  {
    
    if (Serial.read() == '1'){
      
      int i = 0;
      for (; i<=255; i++)
      {
  
        Serial.print(i);
        Serial.print("  -->  ");
        Serial.println(EEPROM.read(i));
        delay(4);
      }
    }
  }

  
}
