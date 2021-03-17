#include <Servo.h>

#define trigger 10
#define echo 4
#define ntc 0                //analog-pin 0

Servo myServo;

//Functions
void scan(void);
void readTemp(void);


//Global variables
float distance[180];
byte degree[180];
int temperature;

void setup(void)
{
  pinMode(13, OUTPUT);
  pinMode(trigger,OUTPUT);  //ultrasonic
  pinMode(echo,INPUT);      //ultrasonic
  pinMode(ntc,INPUT);
  
  myServo.attach(9);
  myServo.write(90);
  delay(20);

  Serial.begin(9600);
}//setup()


void loop(void)    //myServo.write();
{
  delay(1000);
  readTemp();
  scan();
  
  Serial.println();
  
}//loop-end


void scan(void){                    //tarama performansini artir ve arge yap
  float average=0;
  unsigned long int timee=0;
  byte counter=5;
  
  myServo.write(0);  //give some time to servo for re-positioning properly
  delay(80); 
  
  for(register byte i=0;i<=180;i++){ //this for-loop are complete up to (max) 16.4 seconds (at 25˚C)
    myServo.write(i);
    delay(30);        // Operating speed: 0.1 s/60˚ of the Servo
      for(register byte j=0;j<5;j++ ){ //this for-loop are complete up to (max) 91.06 milliseconds (at 25˚C)
        digitalWrite(trigger,LOW);
        delayMicroseconds(2);
        digitalWrite(trigger,HIGH);
        delayMicroseconds(10);    //transmits 40kHz ultrasonic waves 8 times 
        digitalWrite(trigger,LOW);  // 
        timee=pulseIn(echo,HIGH,10000);  //measures in range of 1.5 meters  at 25˚C 
        if(timee==0)counter--;           //if connat measure anaything (in case out of range),do not consider
        average+=(timee)*(0.01657+(0.0000303*temperature)); //measures in cm in terms of microseconds
      }//for-end (icteki)
    if(counter==0)distance[i]=0;          //in case no obstacle measured (if out of range),consider it as '0'
    else distance[i]=(average)/(counter);   
    degree[i]=i;
    average=0;
    counter=5;
    //#
    Serial.print("degree\t");  //degree
    Serial.print(degree[i]);
    Serial.print("\t|\t");
    Serial.print("distance\t");  //centimeter
    Serial.print(distance[i]);
    Serial.print("\t|\t");
    Serial.print("time\t"); //microsecond
    Serial.print(timee); 
    Serial.print("\t|\t");
    Serial.print("temperature\t");  //˚C
    Serial.println(temperature);
    //#
    
    
    }//for-end (en distaki)
  }//scan-end

void readTemp(void){
  temperature=map(analogRead(0),20,358,-40,125);
}//readTemp()

//project:
//https://www.tinkercad.com/things/9SpAQEDkcmp-classic-ultrasonic-radar/editel
