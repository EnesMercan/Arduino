/*
 * https://www.tinkercad.com/things/dBRIyUkM4yV
*/

#define LDR 0
#define LED 3

void setup(void) {
  pinMode(LDR,INPUT);
  pinMode(LED,OUTPUT);
  
  Serial.begin(9600);

}

void loop(void) {
  unsigned int light=0;
  
  light=analogRead(LDR);
  Serial.println(light);
  light=map(light,0,1024,0,255);
  analogWrite(LED,light);
}
