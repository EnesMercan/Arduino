#include <IRremote.h>
#define receiver_pin 11

IRrecv receiver(receiver_pin);
decode_results data;
void processSignal(void);

void setup(void) {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  receiver.enableIRIn();

}

void loop(void) {
  
  if(receiver.decode(&data)){
    digitalWrite(13,HIGH);
    Serial.print("0x");
    Serial.print(data.value,HEX);
    Serial.print("\t");
    processSignal();
    
    delay(30);  //Add delay to prevent false readings
    receiver.resume();
    Serial.println();
  }
    digitalWrite(13,LOW);
    
}

void processSignal(void){
  switch(data.value){
    case 0xFD08F7 : Serial.println("1"); break;//number 1
    case 0xFD8877 : Serial.println("2"); break;//number 2
    case 0xFD48B7 : Serial.println("3"); break;//number 3
    case 0xFD28D7 : Serial.println("4"); break;//number 4
    case 0xFDA857 : Serial.println("5"); break;//number 5
    case 0xFD6897 : Serial.println("6"); break;//number 6
    case 0xFD18E7 : Serial.println("7"); break;//number 7
    case 0xFD9867 : Serial.println("8"); break;//number 8
    case 0xFD58A7 : Serial.println("9"); break;//number 9
    case 0xFD30CF : Serial.println("0"); break;//number 0
    case 0xFD807F : Serial.println("+"); break;// VOL +
    case 0xFD906F : Serial.println("-"); break;// VOL - 
    case 0xFD50AF : Serial.println("CH+"); break;//CH+ button
    case 0xFF629D : Serial.println("CH"); break;//CH button
    case 0xFD10EF : Serial.println("CH-"); break;//CH- button
    case 0xFD609F : Serial.println(">>|"); break;//>>| (NEXT) button
    case 0xFD20DF : Serial.println("|<<"); break;//|<< (PREV) button
    case 0xFDA05F : Serial.println(">||"); break;// PLAY/PAUSE
    case 0xFDB04F : Serial.println("EQ"); break;// EQ
    case 0xFD00FF : Serial.println("POWER"); break;// POWER
    case 0xFD40BF : Serial.println("FUNC/STOP"); break;//FUNC/STOP button
    default : Serial.println("UNKNOWN SIGNAL");
}
}
