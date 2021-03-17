/*
https://www.tinkercad.com/things/laxQNZixSoh
*/

#define BASE 3
#define BUTTON 9


void setup() {
  // put your setup code here, to run once:
   pinMode(BASE,OUTPUT);
   pinMode(BUTTON,INPUT);
   Serial.begin(9600);
}

void loop() {
  bool status=false;

  if(digitalRead(BUTTON)==1)
     status=true;
  else
      status=false;
      
  digitalWrite(BASE,status);
  digitalWrite(13,status);
  

}
