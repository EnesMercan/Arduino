#include <SoftwareSerial.h>
#include <Servo.h>

#define RX_ARD 7  //RX pin on Arduino
#define TX_ARD 6  //TX pin on Arduino
#define BND_RATE 38400  //default baondrate of bluetooth device

SoftwareSerial hc(RX_ARD,TX_ARD); //rx, tx
Servo motor;

int count = 0;
unsigned int degree = 0;



void setup() {

  motor.attach(3);

  Serial.begin(BND_RATE); //start serial communication with computer
  Serial.println("\nHello World!"); //seen this message on serial port on your computer?

  //serial communication boundrate with bluetooth
  hc.begin(BND_RATE);   //default value generally 38400 (sometimes 9600)

}


void loop() {
  
  if(hc.available())  //any message available from blue..?
  { 
    count++ ;
    
    if(count == 1)
    {
      
      degree += ((hc.read()) - 48) * 100;
      
    }
    
    else if(count == 2)
    {
      
      degree += (hc.read() - 48) * 10;
    }
    
    else if(count == 3){
      degree += (hc.read() - 48) * 1;

      //MOTOR WRITE
       motor.write(degree);
       Serial.println(degree, DEC);
       hc.println(degree, DEC);
      
      degree = 0;
      count = 0;  
    }
   
  }
    
}
