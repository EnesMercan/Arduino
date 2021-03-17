const int pins[]={13,12,11,10,9,8,7} ;
int potSpeed=A3 ;
int potCurrency=A0 ;
int speedValue ;
int currencyValue ;

void setup()
{
  for(int i=0; i<7; i++)
  {
    pinMode(pins[i], OUTPUT) ;
  }
  pinMode(A0, INPUT) ;
  pinMode(A3, INPUT) ;
  Serial.begin(9600) ;
}

void loop() 
{
  
  
  
  
  for(int i=0;i<7;i++)
  {
    digitalWrite(pins[i],functionCurrency()) ;
    delay(functionSpeed()) ;
    digitalWrite(pins[i],0) ;
  }
  
  delay(speedValue*1.30) ;
  
  for(int i=5; i>=0;i--)
  {
    digitalWrite(pins[i],functionCurrency()) ;
    delay(functionSpeed()) ;
    digitalWrite(pins[i], 0) ;
  }
  
  delay(functionSpeed()*2.00) ;
}

int functionCurrency() 
{
 currencyValue=analogRead(potCurrency) ;
 Serial.print("currency:") ;
 Serial.print(currencyValue) ;
 Serial.print("\t") ;
 return currencyValue ;
}

int functionSpeed() 
{
 speedValue=analogRead(potSpeed) ;
  Serial.print("speed:") ;
  Serial.println(speedValue) ;
  return speedValue ;
}
