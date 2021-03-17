/*project link:
//https://www.tinkercad.com/things/fchNwcXdRxH-how-to-adjust-brightness-contrast-of-lcd-with-remote-control

 USER MANUAL:
 *To turn off/on the screen , press 'POWER' button 
     power on/off... (POWER)
 *To adjust the brightness of the LCD, press 'UPWARD' button and 
  press numbers up to 3 times 
     brightness... (UPWARD)(9)(5)(3)
 *To adjust contrast of the LCD screen ,press 'DOWNWARD' button and
  input numers up to 3 times
     contrast.... (DOWNWARD)(3)(2)(1)
 *To restart the system ,firstly press 'POWER' ,after press '0' button
     restart.... (POWER)(0)
*/
#include<LiquidCrystal.h>
#include<IRremote.h>

#define receiver_pin 11
#define d4 2
#define d5 4
#define d6 8
#define d7 7
#define RS 3
#define En 9
#define lcdContrast 5
#define light 6
#define LED 13

IRrecv receiver(receiver_pin);
decode_results receivedData;
LiquidCrystal lcd(RS,En,d4,d5,d6,d7); 

void processSignal(void);
void storeData(bool);
void adjust(bool);
void lcdDisplay(int flag);

byte receivedDec=0;
byte counter=0;
bool brightnessFlag=false;
bool contrastFlag=false;
byte brightness[3]={2,5,5};
byte contrast[3]={2,5,5};
byte page=0; //page1:contrast/brightness page2:numara hesapla
bool power=1;

void setup(void) {
  
  lcd.begin(16,2);
  receiver.enableIRIn();
  
  pinMode(lcdContrast,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(LED,OUTPUT);
  
  Serial.begin(9600); Serial.println("####Serial.begin(9600)");/////////
  
  lcd.clear();
  delay(1000); Serial.println("####setup 1000 bekledi");/////////
  lcdDisplay(10);  
  lcd.clear();
  Serial.println("####setup sonu");/////////
}

void loop(void) {
  if(receiver.decode(&receivedData)){
    digitalWrite(LED,1);
    Serial.println("####IR kontrol edip if girdi");/////////
    Serial.println("####processSignal cagiracak");/////////
    processSignal();
    Serial.println("####processSignal cikti");/////////
    if((brightnessFlag==1)&&(contrastFlag==1)){
      Serial.println("error code:1");
      counter=brightnessFlag=contrastFlag=0;
    }
    if((brightnessFlag==1)&&(receivedData.value!=0xFD50AF)){ //store data for brightness
      Serial.println("####if code:1");storeData(1);}

    if((contrastFlag==1)&&(receivedData.value!=0xFD10EF)) {//store data for contrast
      Serial.println("####if code:2");storeData(0);}
    
    delay(30);  //Add delay to prevent false readings
    receiver.resume();
  } //major if
  digitalWrite(LED,0);
}//loop

void processSignal(void){
  Serial.println("####processSignal basi (girdi)");/////////
  switch(receivedData.value){
    case 0xFD08F7 : receivedDec=1;                  //case for number 1
                    Serial.println(receivedDec); 
                    break;
    case 0xFD8877 : receivedDec=2;                  //case for number 2
                    Serial.println(receivedDec); 
                    break;
    case 0xFD48B7 : receivedDec=3;                  //case for number 3
                    Serial.println(receivedDec); 
                    break;
    case 0xFD28D7 : receivedDec=4;                  //case for number 4
                    Serial.println(receivedDec); 
                    break;
    case 0xFDA857 : receivedDec=5;                  //case for number 5
                    Serial.println(receivedDec); 
                    break;
    case 0xFD6897 : receivedDec=6;                 //case for number 6
                    Serial.println(receivedDec); 
                    break;
    case 0xFD18E7 : receivedDec=7;                 //case for number 7
                    Serial.println(receivedDec); 
                    break;
    case 0xFD9867 : receivedDec=8;                 //case for number 8
                    Serial.println(receivedDec); 
                    break;
    case 0xFD58A7 : receivedDec=9;                //case for number 9
                    Serial.println(receivedDec); 
                    break;
    case 0xFD30CF : receivedDec=0;                 //case for number 0
                    Serial.println(receivedDec);
                    if(power==0){lcdDisplay(15);lcd.clear();lcdDisplay(10);}
                    break;
    case 0xFD807F : Serial.println("+"); break;       // Vol +
    case 0xFD906F : Serial.println("-"); break;       // Vol - 
    case 0xFD00FF : Serial.println("POWER");          //power
                    power=!power;
                    digitalWrite(light,power);
                    break;
    case 0xFD50AF : Serial.println("Brightness:\t");    //brightness (upward button)
                    lcd.clear();
                    lcdDisplay(12);
                    lcdDisplay(11);
                    if(brightnessFlag){ //brightnessFlag=1 ?
                       adjust(1);
                       lcd.clear();
                       lcdDisplay(12);
                       lcdDisplay(11);
                    }
                    else       
                       brightnessFlag=1;
                    break;
                                     
    case 0xFD10EF : Serial.println("Contrast:\t"); //contrast  (downward button)
                    lcd.clear();
                    lcdDisplay(11);
                    lcdDisplay(12);
                    if(contrastFlag){ //ContrastFlag=1 ?
                       adjust(0);
                       lcd.clear();
                       lcdDisplay(12);
                       lcdDisplay(11);
                    }
                    else       
                       contrastFlag=1;
                    break;    
  }//switch
}//processSignal()

void storeData(bool flag){
  Serial.println("####storeData girdi");/////////
  if(flag){
    Serial.println("####storeData flag==1 girdi");/////////
    brightness[counter]=receivedDec;
    lcd.clear();
    lcdDisplay(12); //print brightness
    lcdDisplay(11);
    counter++;
    receivedDec=0;
    if(counter==3)
       adjust(1);
    }
  else if(flag==0){
    Serial.println("####storeData flag==0 girdi");/////////
    contrast[counter]=receivedDec;
    lcd.clear();
    lcdDisplay(11); //print contrast
    lcdDisplay(12);
    counter++;
    receivedDec=0;
    if(counter==3)
      adjust(0);
  }
  Serial.println("####storeData sonu");/////////
}//storeData()

void adjust(bool flag){
  Serial.println("####adjust() girdi");/////////
  unsigned int total=0;
  if(flag){  //adjust brightness 
    Serial.println("####adjust() if(flag)");/////////
    /*for(byte i=1;i<=counter;i++)
       total+=brightness[(i-1)]*pow(10,(counter-i));*/
      total+=(brightness[0]*100)+(brightness[1]*10)+(brightness[2]);
    Serial.println(total);/////////
    total=map(total,0,999,0,255);Serial.println(total);/////////
    analogWrite(light,total);
  }
  else{      //adjust contrast
    total+=(contrast[0]*100)+(contrast[1]*10)+(contrast[2]);
    total=map(total,0,999,0,255);
    analogWrite(lcdContrast,total);
  }
  counter=0;
  brightnessFlag=0;
  contrastFlag=0;
  Serial.println("####adjust() sonu");/////////
}//adjust()

void lcdDisplay(int flag){
  Serial.println("####lcdDisplay girdi");/////////
  if(flag==0){
    }
  if(flag){ //display the value received
    //lcd.setCursor();
    }
  if(flag==2){ //display the value received
    //lcd.setCursor();
    }
  if(flag==3){
    
    }
  if(flag==4){
    
    }
  if(flag==5){
    
    }
  if(flag==6){
    
    }
  if(flag==7){
    
    }
  if(flag==8){
    
    }
  if(flag==9){
    
    }
  if(flag==10){ //start process
    
    Serial.println("####lcdDisplay(10)");/////////
    analogWrite(light,255);
    analogWrite(lcdContrast,0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hello ENES!");
    Serial.println("Hello User!");
    delay(3000);
    lcd.clear();
    power=1;
    }
  if(flag==11){  //print contrast
    
    lcd.setCursor(0,0);
    lcd.print("contrast:");
    lcd.setCursor(9,0);
    lcd.print(contrast[0]);
    lcd.setCursor(10,0);
    lcd.print(contrast[1]);
    lcd.setCursor(11,0);
    lcd.print(contrast[2]);
    lcd.setCursor(13,0);
    lcd.print("%");
    lcd.setCursor(14,0);
    lcd.print((contrast[0]*10)+(contrast[1]));
    Serial.print(contrast[0]);
    Serial.print(contrast[1]);
    Serial.print(contrast[2]);
    Serial.print("%");
    Serial.print((contrast[0]*10)+(contrast[1]*1)+(contrast[2]*0.1));
    }
  if(flag==12){  //print back light
    
    lcd.setCursor(0,1);
    lcd.print("light");
    lcd.setCursor(8,1);
    lcd.print(":");
    lcd.setCursor(9,1);
    lcd.print(brightness[0]);
    lcd.setCursor(10,1);
    lcd.print(brightness[1]);
    lcd.setCursor(11,1);
    lcd.print(brightness[2]);
    lcd.setCursor(13,1);
    lcd.print("%");
    lcd.setCursor(14,1);
    lcd.print((brightness[0]*10)+(brightness[1]));
    Serial.print(brightness[0]);
    Serial.print(brightness[1]);
    Serial.print(brightness[2]);
    Serial.print("%");
    Serial.print((brightness[0]*10)+(brightness[1]*1)+(brightness[2]*0.1));
    }
  if(flag==15){  //restart the system process
    analogWrite(lcdContrast,0);
    analogWrite(light,255);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("restarting.");
    lcd.setCursor(11,0);
    delay(1000);
    lcd.print(".");
    lcd.setCursor(12,0);
    delay(1000);
    lcd.print(".");
    lcd.setCursor(13,0);
    delay(1000);
    lcd.print(".");
    lcd.setCursor(14,0);
    delay(1000);
    lcd.print(".");
    lcd.setCursor(15,0);
    delay(1000);
    lcd.print(".");
    analogWrite(lcdContrast,0);
    for(word i=255;i>=1;i--){analogWrite(light,i);delay(10);Serial.println(i);}
    lcd.clear();
    counter=brightnessFlag=contrastFlag=power=page=0;
    brightness[0]=2;brightness[1]=5;brightness[2]=5;
    contrast[0]=1;contrast[1]=2;contrast[2]=8;
    delay(1000);
  }
    Serial.println("####lcdDisplay sonu");/////////
}//lcdDisplay
