#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7
#define LED5 9
#define LED6 11
#define LED7 12

// For serial communication...
#define BAU_RATE 9600
#define TX_ARD 2  // Tx pin on this arduino (rx : receiver)
#define RX_ARD 3  // RX pin on this ardiuno (tx : transmitter)

#include <SoftwareSerial.h>

SoftwareSerial mySerial(RX_ARD, TX_ARD);

int message = 0;
  
  
void setup()
{
  Serial.begin(BAU_RATE);
  mySerial.begin(BAU_RATE);
  
  // pin configurations...
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  
  delay(100); // Wait little bit for stabilization
  
  //testing the first Arduino can send data via USB (arduino_1 ---> computer)
  // you will see this message on the serial monitor
  Serial.println("Hello! I'm first Arduino!");
}

void loop()
{
  
  mySerial.listen();
  if (mySerial.available() > 0) // Is there any data package coming from other arduino?
  {
    message = mySerial.read();  // Read what is coming and store in message
    
    mySerial.write(message);
  }
  
    if (message == '0') // Turn off all Leds
    {
    
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      
    }
    
    else if (message == '1')
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
    }
    
    else if (message == '2')
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
    }
    
    else if (message == '3')
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
    }
    
    else if (message == '4')
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
    }
    
    else if (message == '5')
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
    }
    
    else if (message == '6')
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED7, LOW);
    }
    
    else if (message == '7')
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, HIGH);
    }
    
    else if (message == 'A')  // If message is 'A'all, turn on all LEDs
    {
    digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED7, HIGH);
    }

    
}
