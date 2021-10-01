/*steering straight = 140
steering right= 160
steering left= 120

3 ultrasonics,
go forward (67 power)
if finds a distance of 10 cm,
a) check right and left, to choose clockwise or anticlockwise
Ultra sonic pins:
right = 5
left = 3
forward = 6
echo = 2

servo pins:
steering = 9
motor = 10
*/


#include <HCSR04.h>
#include <Servo.h>

Servo steering;
Servo motor;

int t;
int x;
int y;

int distanceright;
int distanceleft;
int distanceforward;

UltraSonicDistanceSensor trigright(2,13);
UltraSonicDistanceSensor trigforward(4,7);
UltraSonicDistanceSensor trigleft(5,3);//doesnt work


const int left = 50;
const int right = 95;
const int straight = 70;

const int on= 67;
const int off=65;
int duration;

int compass = 0;
int lap=0;

void clockwise(){
  for (int i = 0; i <= 11; i++) {
    steering.write(right);
    motor.write(on);
    delay(1500);
    motor.write(off);
    delay(1500);
    steering.write(straight);
    delay(250);
    motor.write(on);
    delay(1000);
    motor.write(off);
    delay(500);    
    lap++;
    compass++; 
  }
}

void anticlockwise(){
  for (int i = 0; i <= 11; i++) {
    steering.write(left);
    motor.write(on);
    delay(1500);
    motor.write(off);
    delay(1500);
    steering.write(straight);
    delay(250);
    motor.write(on);
    delay(1000);
    motor.write(off);
    delay(500);
    lap++; 
    compass--;
  }
}
void clockwisefinal(){
  steering.write(right);
  motor.write(on);
  delay(1000);
  motor.write(off);
  delay(500);
  steering.write(straight);  
}
void anticlockwisefinal(){
  steering.write(left);
  motor.write(on);
  delay(3000);
  motor.write(off);
  delay(500);
  steering.write(straight);
}

void setup(){
    steering.attach(9);
    steering.write(straight);
    motor.attach(10);
    delay(1);
/*  motor.write(10);
    delay(5000);
*/
}
void loop() {
  delay(50);
  x=trigforward.measureDistanceCm();
  
  if(x > 50 && lap = 0){
    esc.write(67);
    delay(750);
    motor.write(66);
    delay(250);
    motor.write(65);
    delay(500);
  }
  
  if(x > 5 && x <= 50 && lap = 0){
    //check right distance
    distanceright=trigright.measureDistanceCm();
    //check left distance
    distanceleft=trigleft.measureDistanceCm();
    if (distanceright > 100){     
      clockwise();
    }
    else{
      anticlockwise();
    }
  }
  if (lap == 12 && compass>0){
    clockwisefinal();
  }
  else{
    anticlockwisefinal();
  }
}
