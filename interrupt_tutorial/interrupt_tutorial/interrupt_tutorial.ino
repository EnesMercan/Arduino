const int LEDarray[] = {2,3,4,5,6,7,8,9};
int j = 0;

void setup()
{
  Serial.begin(9600);
  
  for(int i=0; i<8 ;i++)    
  { 
    pinMode(LEDarray[i], OUTPUT); /* set LEDs as output */
  } 
  
  cli(); // Clear interrupt --> disable global int's before setting up them

  /* Timer1 interrupt has been set up to be used one time per second (1 Hz)*/
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 15624; // for 1HZ
  
  
  TCCR1B |= (1 << WGM12);  //  1/1024 of clock pulse
  
  // enable Timer1
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);

  sei(); // Enable back all (global) interrupts

}

// This function below will be called once in every second (when interrupt occurs...)
ISR(TIMER1_COMPA_vect){
  for(int i=0; i<8; i++){         
    digitalWrite(LEDarray[i],LOW);   
    // All LEDs turned off      
  }
  digitalWrite(LEDarray[j],HIGH); 
  // Next LED turned on
  j ++;
  if(j > 7)
    j = 0;
}

void loop()
{
 Serial.println("Arduino can do something else here in the loop");
 delay(100);
}
