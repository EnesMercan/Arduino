#define LED1 3
#define LED2 5
#define LED3 6
#define LED4 9
#define LED5 10
#define LED6 11
#define POT 0 //controller
#define POT2 1 //how fast it flows


void upload(void);
 
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(POT, INPUT);
  pinMode(POT2, INPUT);
  Serial.begin(9600);
  {//blink to show code uploaded without any error
      unsigned short int i=0;
      for(;i<3;i++)
      {  upload();
         delay(500);}
   }
}

void loop()
{
  unsigned short int potValue=analogRead(0);
  unsigned short int ledPower1=0;
  unsigned short int ledPower2=0;
  unsigned short int ledPower3=0;
  unsigned short int ledPower4=0;
  unsigned short int ledPower5=0;
  unsigned short int ledPower6=0;
  
  digitalWrite(LED1,0);
  digitalWrite(LED2,0);
  digitalWrite(LED3,0);
  digitalWrite(LED4,0);
  digitalWrite(LED5,0);
  digitalWrite(LED6,0);
  
  if((potValue>0)&&(potValue<512)){
    ledPower1=map(potValue,0,512,0,255);
    analogWrite(LED1,ledPower1);
  }
  if((potValue>170.66)&&(potValue<614.4)){
    ledPower2=map(potValue,170.77,614.4,0,255);
    analogWrite(LED2,ledPower2);
  }
  if((potValue>341.32)&&(potValue<716.8)){
    ledPower3=map(potValue,341.32,716.8,0,255);
    analogWrite(LED3,ledPower3);
  }
  if((potValue>511.98)&&(potValue<819.2)){
    ledPower4=map(potValue,511.98,819.2,0,255);
    analogWrite(LED4,ledPower4);
  }
  if((potValue>682.64)&&(potValue<921.6)){
    ledPower5=map(potValue,682.64,921.6,0,255);
    analogWrite(LED5,ledPower5);
  }
  if((potValue>853.3)&&(potValue<1024)){
    ledPower6=map(potValue,853.3,1023,0,255);
    analogWrite(LED6,ledPower6);
  }
  
  Serial.print(potValue);
  Serial.print("\t");
  Serial.print(ledPower1);
  Serial.print("\t");
  Serial.print(ledPower2);
  Serial.print("\t");
  Serial.print(ledPower3);
  Serial.print("\t");
  Serial.print(ledPower4);
  Serial.print("\t");
  Serial.print(ledPower5);
  Serial.print("\t");
  Serial.println(ledPower6);

  
}

void upload(void){
  
  unsigned short int i=0;
  for(;i<6;i++){
    if(i%2==0){
      digitalWrite(13,HIGH);
      delay(150);
    }
    else {
      digitalWrite(13,LOW);
      delay(100);
    }
  }
  
}
