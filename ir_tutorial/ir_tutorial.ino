#include<IRremote.h>                     //include special library (a must)

const unsigned short int receiver_pin=4; //connect the reciver to the pin 4
IRrecv receiver(receiver_pin);           //inform receiver's pin
decode_results output;                   //keep the decoded datas with "output" named variable (output name is up to you to change)

void setup(void){
  
  Serial.begin(9600);                    //set the serial monitor frequency
  receiver.enableIRIn();                 //enable IR Sensor
}

void loop(void){
  if(receiver.decode(&output)){         //check if a code has been received
    Serial.println(output.value,HEX);   //print the signal data received on the Serial monitor
    
    delay(30);  //Add delay to prevent false readings
    receiver.resume();                  //receive the next coming signals
  } 
}

/*
also you can keep the data with this method:
 
  unsigned int signals=0;
  signals=receiver.decode(&output);
  Serial.println(signals);
*/

//datasheet for IR receiver
// http://eeshop.unl.edu/pdf/VS1838-Infrared-Receiver-datasheet.pdf
//guide websites for using IR:
//https://www.instructables.com/id/Arduino-Infrared-Remote-tutorial/
//url of my project:
//https://www.tinkercad.com/things/iDNboVxt9jU
