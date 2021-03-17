#include <SoftwareSerial.h>

#define RX_ARD 7  //RX pin on Arduino
#define TX_ARD 6  //TX pin on Arduino
#define BND_RATE 38400  //default baondrate of bluetooth device

SoftwareSerial hc(RX_ARD,TX_ARD); //rx, tx

char payload = 0; //communication data to keep

#define LED1 12 //led on digital pin 12
#define LED2 11 //led on digital pin 11


void setup() {

  //configure leds as output
  pinMode(LED1, OUTPUT);  
  pinMode(LED2, OUTPUT);

  //initialize them low for first usage
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  Serial.begin(BND_RATE); //start serial communication with computer
  Serial.println("\nHello World!"); //seen this message on serial port on your computer?

  //serial communication boundrate with bluetooth
  hc.begin(BND_RATE);   //default value generally 38400 (sometimes 9600)

}


void loop() {
  
  if(hc.available())  //any message available from blue..?
  {
    payload = hc.read();  //read teh message
    Serial.println(payload);  //print message on Serial Port
    hc.println("ok"); //send to messager "ok" ("got it")
    
      if(payload == '1')  //if the message character '1'...
      {
      digitalWrite(LED1, !digitalRead(LED1)); //then toggle led1
      
      }
      
      else if(payload == '2') //if the message is the character '2'
        digitalWrite(LED2, !digitalRead(LED2)); //the toggle led2
  
  }
    
  //  that's it! enjoy your code!
}

/*caution!
 * connections of bluetooth module :
 *  VCC --> 3.6V-6V level power
 *  GND --> GROUND
 *  RXD --> TX
 *  TXD --> RX
 *  STATE and EN pin are not connected
 *  
 *  you can use RXD and EN pins only with 3.3V
 *  any level excees 3V may damage your module
 *  make sure that you use voltage divider 
 *  (1kΩ and 2kΩ or 2.2kΩ and 4.7kΩ) resistor pairs on
 *  RXD pin of the module to decrease the voltage 
 *  level from 5V to 3.3V
 */
 
