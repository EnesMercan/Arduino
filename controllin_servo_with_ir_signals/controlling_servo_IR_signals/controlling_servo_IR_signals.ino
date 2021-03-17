/*
* connect me through linkedIn:
*  https://www.linkedin.com/in/enesmercan
*/
#include <IRremote.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define receiver_pin 11
#define RS 3
#define E 9
#define D4 2
#define D5 4
#define D6 8
#define D7 7
#define lcdContrast 5
#define light 6
#define LED 12

//functions for Libraries
IRrecv receiver(receiver_pin);
decode_results receivedSignal;
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
Servo engine;

//Global Variables
byte motorAngle=90;
byte signalDecimal=0; 
char signal[5]="xxxx";
int brightness=255;
int contrast=80;
byte page=0;
byte counter=0;
bool power=false;
byte processFlag=0;
int temporary=0;

//My functions
void processSignal(void);
void lcdDisplay(byte);
void adjust(byte);
void store(void);


void setup(void) {
  pinMode(13,OUTPUT);
  pinMode(lcdContrast,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(light,OUTPUT);
  
  Serial.begin(9600);
  receiver.enableIRIn();
  lcd.begin(16,2);
  engine.attach(10);

  lcd.clear();               //make sure LCD screen is totaly clean
  engine.write(90);  //assign the starting value of servo motor
}//setup-end


void loop(void) {
  
  if(receiver.decode(&receivedSignal)){
    
    lcd.clear();
    digitalWrite(13,HIGH);
    digitalWrite(LED,HIGH);
    
    if((processFlag!=0))
      counter++;
    
    processSignal();
    
    if((processFlag!=0)&&(counter!=0)&&(signalDecimal<10)&&(signalDecimal>=0))
      store();
    
    if((processFlag!=0)&&(signalDecimal>9)&&(signalDecimal<0))
      counter--; 
    
    delay(30);  //Add delay to prevent false readings
    receiver.resume();
    signalDecimal=0;
    lcdDisplay(page);
  }
    digitalWrite(13,LOW);
    digitalWrite(LED,LOW);
      
}//loop-end

void adjust(byte flag){
  if(flag==0){//motor-angle
    if(temporary>180)
       temporary=map(temporary,0,999,0,180);
    motorAngle=temporary;
    engine.write(temporary);
    }
  else if(flag==1){//contrast
    contrast=temporary;
    temporary=map(temporary,0,999,0,255);
    analogWrite(lcdContrast,temporary);
    }
  else if(flag==2){//brightness
    brightness=temporary;
    temporary=map(temporary,0,999,0,255);
    analogWrite(light,temporary);
    }
  
  temporary=counter=processFlag=0;
  
}//adjust


void store(void){
    if(counter==1){
      temporary+=(signalDecimal)*100;
      }
    if(counter==2){
      temporary+=(signalDecimal)*10;
      }
    if(counter==3){
      temporary+=(signalDecimal);
      counter++;}
    if(counter==4){
      if(page==1){
        if(processFlag==1)
           adjust(0);
      }
      else if(page==2){
        if(processFlag==1)
           adjust(1);
        else if(processFlag==2)
           adjust(2);
      }
    }
}//store


void processSignal(void){
  
  switch(receivedSignal.value){
    
    case 0xFD08F7 : signal[0]='1';   //number 1
                    signal[1]='\0'; 
                    signalDecimal=1; 
                    break;
   
    case 0xFD8877 : signal[0]='2';   //number 2
                    signal[1]='\0'; 
                    signalDecimal=2; 
                    break;
   
    case 0xFD48B7 : signal[0]='3';   //number 3
                    signal[1]='\0'; 
                    signalDecimal=3; 
                    break;
   
    case 0xFD28D7 : signal[0]='4';   //number 4
                    signal[1]='\0';
                    signalDecimal=4; 
                    break;
   
    case 0xFDA857 : signal[0]='5';   //number 5
                    signal[1]='\0'; 
                    signalDecimal=5; 
                    break;
   
    case 0xFD6897 : signal[0]='6';   //number 6
                    signal[1]='\0'; 
                    signalDecimal=6;
                    break;
   
    case 0xFD18E7 : signal[0]='7';  //number 7
                    signal[1]='\0'; 
                    signalDecimal=7; 
                    break;
    
    case 0xFD9867 : signal[0]='8';  //number 8
                    signal[1]='\0'; 
                    signalDecimal=8; 
                    break;
    
    case 0xFD58A7 : signal[0]='9';  //number 9
                    signal[1]='\0';
                    signalDecimal=9;
                    break;
   
    case 0xFD30CF : signal[0]='0';  //number 0
                    signal[1]='\0';
                    signalDecimal=0; 
                    break;
    
    case 0xFD807F : signal[0]='+';  // VOL +
                    signal[1]='\0';
                    motorAngle+=10; 
                    break;
    
    case 0xFD906F : signal[0]='-';   // VOL - 
                    signal[1]='\0'; 
                    motorAngle-=10; 
                    break;
    
    case 0xFD50AF : signal[0]='C'; //CH+ button
                    signal[1]='H'; 
                    signal[2]='+'; 
                    signal[3]='\0';
                    break;
    
    case 0xFF629D : signal[0]='C'; //CH button
                    signal[1]='H';
                    signal[2]='\0'; 
                    break;
   
    case 0xFD10EF : signal[0]='C';  //CH- button
                    signal[1]='H'; 
                    signal[2]='-'; 
                    signal[3]='\0';
                    break;
   
    case 0xFD00FF : Serial.println("POWER"); // POWER
                    lcd.clear();
                    power=!power;
                    digitalWrite(light,power); 
                    if(power)
                      lcdDisplay(3);
                    break;    
   
    case 0xFD609F : if(page==1){       //>>| (NEXT) button adjust-light
                      signal[0]='>'; 
                      signal[1]='>'; 
                      signal[2]='|'; 
                      signal[3]='\0';
                      engine.write(motorAngle=0);
                      delay(1000);
                      for(int i=0;i<=180;i++){
                        motorAngle=i;
                        engine.write(i);
                        lcdDisplay(1);
                        delay(20);
                        }
                      motorAngle=0;
                    }
                    if(page==2){
                      processFlag=2;
                    }
                    break;
    
    case 0xFD20DF : if(page==1){            // |<< (PREV) button  adjust-contrast
                      signal[0]='<'; 
                      signal[1]='<'; 
                      signal[2]='|'; 
                      signal[3]='\0';
                      engine.write(motorAngle=180);
                      delay(1000);
                      for(int i=180;i>=0;i--){
                        motorAngle=i;
                        engine.write(i);
                        lcdDisplay(1);
                        delay(20);
                      }
                      motorAngle=0;
                    }
                    if(page==2){
                      processFlag=1;
                    }
                    break;
   
    case 0xFDA05F : signal[0]='>'; // (>||) button to change page
                    signal[1]='|'; 
                    signal[2]='|'; 
                    signal[3]='\0';
                    page++;
                    if(page==3)
                      page=0;
                    break;
    
    case 0xFDB04F : signal[0]='E';   // EQ  adjust angle
                    signal[1]='Q';
                    signal[2]='\0';
                    if(page)
                      processFlag=1;
                    break;
    
    case 0xFF9867 : signal[0]='1';   // 100+
                    signal[1]='0'; 
                    signal[2]='0'; 
                    signal[3]='+'; 
                    signal[4]='\0';
                    break;
    
    case 0xFFB04F : signal[0]='2';   // 200+
                    signal[1]='0'; 
                    signal[2]='0'; 
                    signal[3]='+'; 
                    signal[4]='\0'; 
                    break;
   
    default : signal[0]='?'; 
              signal[1]='?'; 
              signal[2]='?';
              signal[3]='\0';
  }//switch-end
}//processSignal-end


void lcdDisplay(byte flag){
    Serial.println();
    lcd.clear();
  switch(flag){
    case 1:  //motor mode
        lcd.setCursor(7,0);
        lcd.print("|");
        lcd.setCursor(7,1);
        lcd.print("|");
        lcd.setCursor(0,0);
        lcd.print("Angle");
    
        lcd.setCursor(9,0);
        lcd.print("Signal");
        lcd.setCursor(0,1);
        lcd.print(motorAngle);
        
        Serial.print("signal\t");
        for(byte i=0;i<=4;i++){
          if(signal[i]=='\0')
            break;lcd.setCursor((11+i),1);
          lcd.print(signal[i]);
          Serial.print(signal[i]);
        }//for
        Serial.println();
        Serial.print("angle\t");
        Serial.println(motorAngle);
        break;
    
    case 0:  //main menu
        lcd.setCursor(0,0);
        lcd.print("page:1");
        lcd.setCursor(0,1);
        lcd.print("page:2");
        lcd.setCursor(8,0);
        lcd.print("servo");
        lcd.setCursor(8,1);
        lcd.print("settings");
        break;
    
    case 2:  //contrast-brightness mode
        lcd.setCursor(0,0);
        lcd.print("contrast");
        lcd.setCursor(0,1);
        lcd.print("light");
        lcd.setCursor(9,0);
        lcd.print(contrast);
        lcd.setCursor(9,1);
        lcd.print(brightness);
        break;
    
    case 3:  //starting process
        lcd.setCursor(0,0);
        lcd.print("Turkish Eagle");
        delay(3000);
        lcd.clear();
        temporary=counter=processFlag=page=0;
        motorAngle=90;
        break;
    }//switch
}

//url of this project:
//https://www.tinkercad.com/things/aI2LjdJPgoZ
