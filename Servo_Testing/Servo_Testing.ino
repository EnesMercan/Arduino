#include <Servo.h>

#define POT 5
Servo motor;

void setup(void) {
  // put your setup code here, to run once:
  motor.attach(10);
  pinMode(POT,INPUT);
  Serial.begin(9600);
}

void loop(void) {

  char control='0';
  if(Serial.available()){
    control=Serial.read();
    Serial.print(control);
    if(control=='1'){ //activate automatic control
      motor.write(0);
      delay(1000);
      for(byte i=0;i<=180;i++){motor.write(i);delay(20);}
      for(byte i=180;i>0;i--){motor.write(i);delay(20);}
      
    }
  }
  byte angle=map(analogRead(POT),0,1024,0,186);
  motor.write(angle);
  Serial.println(angle);
  delay(20);
}
