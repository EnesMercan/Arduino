/*
 * https://www.tinkercad.com/things/8cFeahcXUno
 */

#include "pitches.h" //add Equivalent frequency for musical note
#include "themes.h" //add Note vale and duration 

//to download the libraries click the link below:
// https://circuitdigest.com/sites/default/files/Arduino_code_for_playing_tone_on_buzzer.zip

#define BUZZER 3  //just one buzzer connected to pin (6)
#define buzzer 3  //just one buzzer connected to pin (6)

void national_anthem(void);

void Play_Pirates()
{ 
  for (int thisNote = 0; thisNote < (sizeof(Pirates_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / Pirates_duration[thisNote];//convert duration to time delay
    tone(BUZZER, Pirates_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.05; //Here 1.05 is tempo, increase to play it slower
    delay(pauseBetweenNotes);
    noTone(BUZZER); //stop music on pin 8 
    }
}

void Play_CrazyFrog()
{
  for (int thisNote = 0; thisNote < (sizeof(CrazyFrog_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / CrazyFrog_duration[thisNote]; //convert duration to time delay
    tone(BUZZER, CrazyFrog_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;//Here 1.30 is tempo, decrease to play it faster
    delay(pauseBetweenNotes);
    noTone(BUZZER); //stop music on pin 8 
    }
}

void Play_MarioUW()
{
    for (int thisNote = 0; thisNote < (sizeof(MarioUW_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / MarioUW_duration[thisNote];//convert duration to time delay
    tone(BUZZER, MarioUW_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.80;
    delay(pauseBetweenNotes);
    noTone(BUZZER); //stop music on pin 8 
    }
}

void Play_Titanic()
{
    for (int thisNote = 0; thisNote < (sizeof(Titanic_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / Titanic_duration[thisNote];//convert duration to time delay
    tone(BUZZER, Titanic_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 2.70;
    delay(pauseBetweenNotes);
    noTone(BUZZER); //stop music on pin 8 
    }
}

void setup() {

pinMode(2, INPUT_PULLUP); //Button 1 with internal pull up
pinMode(3, INPUT_PULLUP); //Button 2 with internal pull up
pinMode(4, INPUT_PULLUP); //Button 3 with internal pull up
pinMode(5, INPUT_PULLUP); //Button 4 with internal pull up

Serial.begin(9600);

a=440;
ad=466;
b=494;

c=523;
cd=554;
d=587;
dd=622;
e=659;
f = 698;
fd = 740;
g = 784;
gd = 830;

a2 = 880;
ad2 = 932;
b2 = 988;
c2 = 1046;
cd2 = 1108;
d2 = 1174;
dd2 = 1244;
e2 = 1318;
f2 = 1396;
fd2 = 1480;
g2 = 1568;
gd2 = 1660;
a3 = 1760;

Serial.println();
Serial.print("\t1\t");
Serial.println("He is a Pirate");
Serial.print("\t2\t");
Serial.println("Crazy Frog");
Serial.print("\t3\t");
Serial.println("Mario UnderWorld");
Serial.print("\t4\t");
Serial.println("Titanic");
Serial.print("\t5\t");
Serial.println("National Anthem");
Serial.println("\n\tWhat do you wanna listen?");

}

void loop() {

    char responce;

    responce=0;
    
    if(Serial.available()){
      responce=Serial.read();
      Serial.println(responce);
      }
    
    switch(responce)
      { 
        case '1' :
          Serial.println("Selected -> 'He is a Pirate' ");  
          Play_Pirates();
          break ;
        case '2' :
          Serial.println("Selected -> 'Crazy Frog' ");  
          Play_CrazyFrog();
          break ;
        
        case '3' :
          Serial.println("Selected -> 'Mario UnderWorld' ");  
          Play_MarioUW();
          break ;
        
        case '4' :
          Serial.println("Selected -> 'Titanic' ");  
          Play_Titanic();
          break ;

         case '5' :
          Serial.println("Selected -> 'National Anthem' ");  
          national_anthem();
          break ;
          }
    
}

void national_anthem(void)
{  
//Korkma Sönmez Bu Şafak  
    tone(buzzer, c);
    delay(800);
    tone(buzzer, f);
    delay(800);
    tone(buzzer, g);
    delay(800);
    tone(buzzer, gd);
    delay(800);
    tone(buzzer, e);
    delay(400);
    tone(buzzer, g);
    delay(200);        
    tone(buzzer, f);
    delay(1600);        
    noTone(buzzer);
    delay(300);
//Larda Yüzden Al Sancak
    tone(buzzer, f);
    delay(800);        
    tone(buzzer, ad2);
    delay(800);        
    tone(buzzer, c2);
    delay(800);        
    tone(buzzer, cd2);
    delay(800);
    tone(buzzer, a2);
    delay(400);
    tone(buzzer, c2);
    delay(200);
    tone(buzzer, ad2);
    delay(1600);        
//Sönmeden Yurdumun Üstünde Tüten En Son Ocak O Be
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, ad2);
    delay(200);        
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, g);
    delay(400);        
    noTone(buzzer);
    delay(100);  
    tone(buzzer, g);
    delay(400);        
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(400);   
    tone(buzzer, e);
    delay(200);
    tone(buzzer, f);
    delay(400);   
    tone(buzzer, g);
    delay(200);
    tone(buzzer, gd);
    delay(400);        
    tone(buzzer, ad);
    delay(200);        
    tone(buzzer, c2);
    delay(400);        
    tone(buzzer, cd2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);        
    tone(buzzer, f2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);     
//Nim Milletimin
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, d);
    delay(200);
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(800);
    tone(buzzer, gd);
    delay(1600);
// Yıldızıdır Parlayacak O benim
    tone(buzzer, c);
    delay(200);
    tone(buzzer, b);
    delay(200);
    tone(buzzer, c);
    delay(200);
    tone(buzzer, g);
    delay(800);
    tone(buzzer, c);
    delay(800);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, f);
    delay(800);
//Dir O Benim Milletimindir Ancak
    tone(buzzer, f2);
    delay(800);
    tone(buzzer, dd2);
    delay(200);
    tone(buzzer, cd2);
    delay(400);
    tone(buzzer, c2);
    delay(200);
    tone(buzzer, ad);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g);
    delay(400);
    tone(buzzer, f);
    delay(200);
    tone(buzzer, c2);
    delay(400);
    tone(buzzer, c);
    delay(800);
    tone(buzzer, f);
    delay(1600);

/////////////ikinci kıt'a

//Çatma Kurban Olayım
    tone(buzzer, c);
    delay(800);
    tone(buzzer, f);
    delay(800);
    tone(buzzer, g);
    delay(800);
    tone(buzzer, gd);
    delay(800);
    tone(buzzer, e);
    delay(400);
    tone(buzzer, g);
    delay(200);        
    tone(buzzer, f);
    delay(1600);        
    noTone(buzzer);
    delay(300);
//Çehreni Ey Nazlı Hilal
    tone(buzzer, f);
    delay(800);        
    tone(buzzer, ad2);
    delay(800);        
    tone(buzzer, c2);
    delay(800);        
    tone(buzzer, cd2);
    delay(400);
    tone(buzzer, ad2);
    delay(400);
    tone(buzzer, a2);
    delay(400);
    tone(buzzer, c2);
    delay(400);
    tone(buzzer, ad2);
    delay(800);        
//Kahraman Irkıma Bir Gül Ne Bu Şiddet Bu Celal Sana
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, ad2);
    delay(200);        
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, g);
    delay(400);        
    noTone(buzzer);
    delay(100);  
    tone(buzzer, g);
    delay(400);        
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(400);   
    tone(buzzer, e);
    delay(200);
    tone(buzzer, f);
    delay(400);   
    tone(buzzer, g);
    delay(200);
    tone(buzzer, gd);
    delay(400);        
    tone(buzzer, ad);
    delay(200);        
    tone(buzzer, c2);
    delay(400);        
    tone(buzzer, cd2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);        
    tone(buzzer, f2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);     
//Olmaz Dökülen
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, d);
    delay(200);
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(800);
    tone(buzzer, gd);
    delay(1600);
//Kanlarımız Sonra Helal Hakkıdır
    tone(buzzer, c);
    delay(200);
    tone(buzzer, b);
    delay(200);
    tone(buzzer, c);
    delay(200);
    tone(buzzer, g);
    delay(800);
    tone(buzzer, c);
    delay(800);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, f);
    delay(800);
//Hakk'a Tapan Milletimin İstiklal
    tone(buzzer, f2);
    delay(800);
    tone(buzzer, dd2);
    delay(200);
    tone(buzzer, cd2);
    delay(400);
    tone(buzzer, c2);
    delay(200);
    tone(buzzer, ad);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g);
    delay(400);
    tone(buzzer, f);
    delay(200);
    tone(buzzer, c2);
    delay(400);
    tone(buzzer, c);
    delay(800);
    tone(buzzer, f);
    delay(1600);

    noTone(buzzer);
    delay(2000);
    
}
/*
sources:
http://www.etkilesimliogrenme.com/arduino-buzzer-istiklal-marsi
https://circuitdigest.com/microcontroller-projects/playing-melodies-on-piezo-buzzer-using-arduino-tone-function
*/
