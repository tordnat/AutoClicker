
#include <Stepper.h>
#include <Wire.h>
#define A 4
#define B 5
#define C 6
#define D 7
#define NUMBER_OF_STEPS_PER_REV 512 //divide or multiply to adapt for clicking mechanism




void write(int a,int b,int c,int d){
digitalWrite(A,a);
digitalWrite(B,b);
digitalWrite(C,c);
digitalWrite(D,d);
}


void onestep(){
write(1,0,0,0);
delay(2);
write(1,1,0,0);
delay(2);
write(0,1,0,0);
delay(2);
write(0,1,1,0);
delay(2);
write(0,0,1,0);
delay(2);
write(0,0,1,1);
delay(2);
write(0,0,0,1);
delay(2);
write(1,0,0,1);
delay(2);
write(0,0,0,0);
}

void onebackstep(){
write(1,0,0,1);
delay(2);
write(0,0,0,1);
delay(2);
write(0,0,1,1);
delay(2);
write(0,0,1,0);
delay(2);
write(0,1,1,0);
delay(2);
write(0,1,0,0);
delay(2);
write(1,1,0,0);
delay(2);
write(1,0,0,1);
delay(2);
write(0,0,0,0);
}
void clockWise(void){
  int i;
  i=0;
  while(i<NUMBER_OF_STEPS_PER_REV){
  onestep();
  i++;
  
  }
}
void counterClockWise(void){
  int i;
  i=0;
  while(i<NUMBER_OF_STEPS_PER_REV){
  onebackstep();
  i++;
  }
}

void clickButton(void){
  Serial.print("Clicking button \n");
  Wire.begin();
  clockWise();
  counterClockWise();
}

long double interval = 1800;

int milisecond = 1000;

void intervalSleep(void){

   for (int i = 0; i<interval; ++i){
    delay(interval);
    }
    
 }

void setup()
{
    Serial.begin(9600);
    clickButton();
    
}

void loop()
{
  clickButton();
  intervalSleep();
    
}
