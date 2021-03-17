//220Ω resistor is not necessary. You. may not use it. If you want
//longer LCD lifetime , keep the resistor mounted

#include <LiquidCrystal.h> // special library need to be used for LCD

#define RS 13 //register select (RS) pin of the LCD
#define E 12  //enable pin of the lcd
#define D4 5  //other digital pins to transmit data from Arduino to LCD
#define D5 4
#define D6 3
#define D7 2
 
LiquidCrystal lcd(RS,E,D4,D5,D6,D7); //define the pins

void greeting(void); //this is my personal function to say "hello"

void setup(void) {

   lcd.begin(16,2);    //that means that we use 16x2 LCD screen
   Serial.begin(9600); //frequency for communication
   
   lcd.print("Hello World!"); //print hello world
   delay(3000);
   lcd.clear();  //it clears the (whole) screen
   
}

void loop(void) {

  
  lcd.setCursor(0,0);     //
  lcd.print("hey mom!");  //standart print format
  lcd.setCursor(8,0);
  lcd.blink();             //blink animation
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("L");
  delay(500);
  lcd.setCursor(1,0);
  lcd.print("O");
  delay(500);
  lcd.setCursor(2,0);
  lcd.print("V");
  delay(500);
  lcd.setCursor(3,0);
  lcd.print("E");
  delay(500);
  lcd.setCursor(5,1);
  lcd.print("Y");
  delay(500);
  lcd.setCursor(6,1);
  lcd.print("O");
  delay(500);
  lcd.setCursor(7,2);
  lcd.print("U");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("YOU");
  lcd.setCursor(7,0);
  lcd.print("LOVE");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("LOVE");
  lcd.setCursor(7,1);
  lcd.print("YOU");
  delay(2000);
  lcd.clear();
  
  
}

/*
 * LiquidCrystal(RS, E, D4, D5, D6, D7). RS, E, D4, D5, D6, D7 are the LCD pins.
 * lcd.begin(columns, rows); 
 * lcd.clear(); //clears any text or data already displayed on the LCD
 * lcd.home(); //places the cursor in the upper left hand corner of the screen, and prints any subsequent text from that position.
 * lcd.setCursor(column, row) //Cursors can be placed anywhere on the screen
 * lcd.write(); //write different types of data to the LCD
 * lcd.print(); //is used to print text to the LCD //lcd.print(100, BIN) prints “1100100”
 * lcd.noCursor(); //turns the cursor off
 * lcd.setCursor();
 * lcd.blink(); lcd.noBlink(); //creates a block style cursor that blinks on and off at approximately 500 milliseconds per cycle.
 * lcd.noDisplay(); //turns off any text or cursors printed to the LCD, without clearing it from the LCD’s memory.
 * lcd.scrollDisplayLeft(); //This function takes anything printed to the LCD and moves it to the left.
 * lcd.scrollDisplayRight();
 * lcd.autoscroll(); //takes a string of text and scrolls it from right to left in increments of the character count of the string. 
 * lcd.noAutoscroll(); //For example, if you have a string of text that is 3 characters long, it will shift the text 3 spaces to the left with each step:
 * lcd.rightToLeft(); //sets the direction that text is printed to the screen.
 * lcd.createChar(); //allows you to create your own custom characters.
  */

//GUIDE WEBSITE
// https://www.circuitbasics.com/how-to-set-up-an-lcd-display-on-an-arduino/
//MY PROJECT LINK
// https://www.tinkercad.com/things/3fjueL3R1z6
