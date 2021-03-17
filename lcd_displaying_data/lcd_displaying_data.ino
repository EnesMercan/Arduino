// projem
// https://www.tinkercad.com/things/542sd4d5UN1-lcd-displaying-data-temperature


#include <LiquidCrystal.h>

#define RS 13
#define E 12
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define TMP 0
#define LDR 2

//Global Variables
    int tmpValue = 0;    //initialization of sensor variable, equivalent to EMA Y
    int ldrValue = 0;
    float EMA_a = 0.6;      //initialization of EMA alpha
    int EMA_TMP = 0;          //initialization of EMA S
    int EMA_LDR = 0;
 
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void filteringData(byte);

void setup(void) {

   lcd.begin(16,2);
   pinMode(TMP,INPUT);
   pinMode(13, OUTPUT);
   pinMode(LDR,INPUT);
   Serial.begin(9600);
   
   lcd.print("hello world!"); //check LCD is working
   delay(3000);
   lcd.clear();
  
   digitalWrite(13,HIGH); // nothing - just for fun :)
  
   EMA_TMP = analogRead(EMA_LDR);  //set EMA LDR for t=1
   EMA_ = analogRead(EMA_TMP);  //set EMA TMP for t=1
   
}

void loop(void) {

  {  //commands for TMP
    filteringData(TMP);    
    Serial.print("Temperature:\t");
    EMA_TMP=map(EMA_TMP,0,1024,-40,125);
    Serial.println(EMA_TMP);
    lcd.setCursor(0,0);
    lcd.print("Temp");
    lcd.setCursor(4,0);
    lcd.print(":");
    lcd.setCursor(7,0);
    if(EMA_TMP<0)
     lcd.print("-");
    lcd.setCursor(8,0);
    lcd.print(EMA_TMP);
    lcd.setCursor(11,0);
    lcd.print("C");
    
    delay(50); 
  }
  
  {  //commands for LDR
    filteringData(LDR);  
    Serial.print("Lihgt:\t\t");
    Serial.println(EMA_LDR);
    lcd.setCursor(0,1);
    lcd.print("Light:");
    lcd.setCursor(8,1);
    lcd.print(EMA_LDR);
    delay(50); 
  }
  //lcd.clear();
  
}

void filteringData(byte pin){
   if(pin==TMP)   //filtering formula for TMP Sensor    
     EMA_TMP = (EMA_a*(analogRead(pin))) + ((1-EMA_a)*EMA_TMP);
   if(pin==LDR)   //filtering formula for LDR Sensor    
     EMA_LDR = (EMA_a*(analogRead(pin))) + ((1-EMA_a)*EMA_LDR);
}

// If you wanna learn more about EMA filtering, see the link below:
//  https://www.tinkercad.com/things/km8pL6ictRU
// The url of this project
// 
