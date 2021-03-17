const int pinArray[]={13,12,11,10,9,8} ;
const int rgbArray[]={6,5,4} ;
int pot=A3 ;
int sayac=2 ;

void setup() {
  for(int i=0 ; i<6 ; i++) {
   pinMode(pinArray[i], OUTPUT) ;
   if(i<3)
     pinMode(rgbArray[i], OUTPUT) ;
  }
  pinMode(pot, INPUT) ;
  Serial.begin(9600) ;
}

void loop() {
  
  
  sayac+=1 ;
  
  for(int i=0 ; i<6 ; i++) {
    digitalWrite(pinArray[i], 1) ;
    delay(myFunction()*2) ;
    digitalWrite(pinArray[i], 0) ;
    
    if(i==5) {
      if(sayac%3==0)
        digitalWrite(rgbArray[2], 0) ;
      digitalWrite(rgbArray[(sayac%3)-1], 0) ;
      digitalWrite(rgbArray[sayac%3],1) ;\
      delay(myFunction()*2.5) ;
    }
  }
  
  sayac+=1 ;
  
  for(int i=5; i>-1 ; i--) {
    digitalWrite(pinArray[i] , 1) ;
    delay(myFunction()*2) ;
    digitalWrite(pinArray[i], 0) ;
    
    if(i==0) {
      if(sayac%3==0)
        digitalWrite(rgbArray[2], 0) ;
      digitalWrite(rgbArray[(sayac%3)-1], 0) ;
      digitalWrite(rgbArray[sayac%3],1) ;
      delay(myFunction()*2.5) ;
    
    }
  }
}

int myFunction() {   /* delay function*/
  int valuePot=map(analogRead(pot),0,1023,0,255) ;
  Serial.println(valuePot) ;
  return valuePot ;
}
