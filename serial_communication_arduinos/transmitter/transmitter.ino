// For serial communication...
#define BAU_RATE 9600
#define TX_ARD 5  // Tx pin on this arduino (rx : receiver)
#define RX_ARD 4  // RX pin on this ardiuno (tx : transmitter)

#include <SoftwareSerial.h>

SoftwareSerial mySerial(RX_ARD, TX_ARD);
  
char message = 0;
  
void setup()
{
  Serial.begin(BAU_RATE);
  mySerial.begin(BAU_RATE);
  
  delay(100); // Wait little bit for stabilization
  
  //testing the first Arduino can send data via USB (arduino_1 ---> computer)
  // you will see this message on the serial monitor
  Serial.println("Hello! I'm second Arduino!");
  
}

void loop()
{
  
  
  if (Serial.available() > 0)
  {
  
    message = Serial.read();
    mySerial.write(message);
    
    digitalWrite(13, HIGH); // Received data indicator
  }
  
  
  mySerial.listen();  // Listen to other Arduino
  if (mySerial.available() > 0)
  {
    
    message = mySerial.read();
    Serial.println(message);
    
    digitalWrite(13, HIGH); // Received data indicator
  }
  
  
}
