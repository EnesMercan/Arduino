#define sensorPin 1 //potentiometer (above) will be used to apply EMA filtering.
              //any other (analog) sensor is acceptable rather than potentiometer

//Global Variables
    int sensorValue = 0;    //initialization of sensor variable, equivalent to EMA Y
    float EMA_a = 0.6;      //initialization of EMA alpha
    int EMA_S = 0;          //initialization of EMA S
    
void setup(void)
{
  pinMode(13, OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);  ////setup of Serial module, 115200 bits/second
  
  digitalWrite(13,HIGH); // nothing - just for fun :)
  
  EMA_S = analogRead(sensorPin);  //set EMA S for t=1
}

void loop(void)
{
    sensorValue = analogRead(sensorPin);                //read the sensor value using ADC
    EMA_S = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_S);    //run the EMA
    //Serial.println(sensorValue);                     //print the normal value of the pot
    Serial.println(EMA_S);                           //print the optimized value of the pot
    delay(50);  
}

//an articel about that "EMA filtereng Theory" thing below:
// https://www.norwegiancreations.com/2015/10/tutorial-potentiometers-with-arduino-and-filtering/
//url of this (my) project 
// https://www.tinkercad.com/things/km8pL6ictRU
