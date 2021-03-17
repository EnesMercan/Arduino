/* Attention:
 *  This is a inter-mediate project!
 *  If you do not know how to use IR (infra-red) receiver ,see the " IR tutorial " below:
 https://www.tinkercad.com/things/3fjueL3R1z6
 *  if you do not know how to use LCD display, see "LCD TUTORIAL"
 https://www.tinkercad.com/things/gLlmIYa70pj
*/

#include<LiquidCrystal.h>
#include<IRremote.h>

#define receiver_pin 11            //pink wire
#define d4 2                       //yellow wire
#define d5 4                       //orange wire
#define d6 8                       //yellow wire
#define d7 7                       //orange wire
#define RS 3                       //green wire
#define En 9                       //purple wire
#define lcdContrast 5              //orange wire

IRrecv receiver(receiver_pin);
decode_results receivedData;
LiquidCrystal lcd(RS,En,d4,d5,d6,d7); 

void lcdDisplay(byte); //print on LCD

void setup(void) {
  
  lcd.begin(16,2);
  receiver.enableIRIn();
  
  pinMode(lcdContrast,OUTPUT);
  
  Serial.begin(9600);
  lcd.clear();
  lcd.print("Hello User");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Send a signal");
}//setup()

void loop(void) {
   if(receiver.decode(&receivedData)){
    lcd.clear();
    digitalWrite(13,HIGH);
    Serial.print("0x");
    Serial.print(receivedData.value,HEX);
    Serial.print("\t");
    processSignal();
     
    delay(30);  //Add delay to prevent false readings
    receiver.resume();
    Serial.println();
  }
    digitalWrite(13,LOW);
    
  }


void processSignal(void){
  
  switch(receivedData.value){
    case 0xFD08F7 : lcdDisplay(1); break;     //number 1           
    case 0xFD8877 : lcdDisplay(2); break;     //number 2
    case 0xFD48B7 : lcdDisplay(3); break;     //number 3
    case 0xFD28D7 : lcdDisplay(4); break;     //number 4
    case 0xFDA857 : lcdDisplay(5); break;     //number 5
    case 0xFD6897 : lcdDisplay(6); break;     //number 6
    case 0xFD18E7 : lcdDisplay(7); break;     //number 7
    case 0xFD9867 : lcdDisplay(8); break;     //number 8
    case 0xFD58A7 : lcdDisplay(9); break;     //number 9
    case 0xFD30CF : lcdDisplay(0); break;     //number 0
    case 0xFD807F : lcdDisplay(10); break;    // VOL +
    case 0xFD906F : lcdDisplay(11); break;    // VOL - 
    case 0xFD50AF : lcdDisplay(12); break;    //CH+ button (upward button)
    case 0xFF629D : lcdDisplay(13); break;    //CH button 
    case 0xFD10EF : lcdDisplay(14); break;    //CH- button (downward button)
    case 0xFD609F : lcdDisplay(15); break;    //>>| (NEXT) button
    case 0xFD20DF : lcdDisplay(16); break;    //|<< (PREV) button
    case 0xFDA05F : lcdDisplay(17); break;    // PLAY/PAUSE
    case 0xFDB04F : lcdDisplay(18); break;    // EQ
    case 0xFD00FF : lcdDisplay(19); break;    // POWER
    case 0xFD40BF : lcdDisplay(20); break;    //FUNC/STOP button
    default : lcdDisplay(21);
  }
}//processSignal()

void lcdDisplay(byte flag){ //print on LCD
  lcd.setCursor(9,0);
  lcd.print("|");
  lcd.setCursor(9,1);
  lcd.print("|");
  lcd.setCursor(0,0);
  lcd.print("HEX Code");
  lcd.setCursor(11,0);
  lcd.print("Data");
  lcd.setCursor(0,1);
  lcd.print("0x");
  lcd.setCursor(2,1);
  lcd.print(receivedData.value,HEX);
  
  if((flag>=0)&&(flag<=9)){  //numbers between 0-9
    lcd.setCursor(13,1);
    Serial.println(flag);      
    lcd.print(flag,DEC);
    }
  else if(flag==10){
    Serial.println("VOL+");
    lcd.setCursor(11,1);
    lcd.print("VOL+");
  }
  else if(flag==11){
    Serial.println("VOL-");
    lcd.setCursor(11,1);
    lcd.print("VOL-");
  }
  else if(flag==12){
    Serial.println("CH+");
    lcd.setCursor(11,1);
    lcd.print("CH+");
  }
  else if(flag==13){
    Serial.println("VOL-");
    lcd.setCursor(11,1);
    lcd.print("VOL-");
  }
  else if(flag==14){
    Serial.println("CH-");
    lcd.setCursor(11,1);
    lcd.print("CH-");
  }
  else if(flag==15){
    Serial.println(">>|");
    lcd.setCursor(11,1);
    lcd.print(">>|");
  }
  else if(flag==16){
    Serial.println("|<<");
    lcd.setCursor(11,1);
    lcd.print("|<<");
  }
  else if(flag==17){
    Serial.println(">||");
    lcd.setCursor(11,1);
    lcd.print(">||");
  }
  else if(flag==18){
    Serial.println("EQ");
    lcd.setCursor(11,1);
    lcd.print("EQ");
  }
  else if(flag==19){
    Serial.println("POW");
    lcd.setCursor(11,1);
    lcd.print("POWER");
  }
  else if(flag==20){
    Serial.println("STOP");
    lcd.setCursor(11,1);
    lcd.print("STOP");
  }
  else if(flag==21){
    lcd.clear();
    Serial.println("UNKNOWN SIGNAL");
    lcd.setCursor(0,0);
    lcd.print("UNKNOWN SIGNAL");
  }
  
}//lcdDisplay()

//URL of this project:
// https://www.tinkercad.com/things/k8n2UpAeOjV
