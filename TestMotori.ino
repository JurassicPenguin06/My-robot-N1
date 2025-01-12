/******************************************************************************
TB6612FNG H-Bridge Motor Driver Example code
https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library
 
Uses 2 motors to show examples of the functions in the library

Resources:
TB6612 SparkFun Library
******************************************************************************/

#include <SparkFun_TB6612.h>
 
// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
#define PWMA 3
#define AIN1 4
#define AIN2 5
#define STBY 6
#define BIN1 7
#define BIN2 8
#define PWMB 9

 
// If 1 = standard motor direction: forward
// If -1 = standard motor direction: backwards
// Depends on the circuit
const int offsetA = 1;
const int offsetB = 1;
 
// Initializing motors
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int speed = 250;
 
void setup()
{
 //Nothing here
}
 
 
void loop()
{
   motor1.drive(speed, 250);  //goes left
   motor1.brake();  //brakes
   delay(300);
   motor1.drive(-speed,500);  //goes left backwards
   motor1.brake();  //brakes
   delay(300);
   motor1.drive(speed,250);   //goes left
   motor1.brake();  //brakes
   delay(1000);

   motor2.drive(speed,250); //goes right
   motor2.brake();  //brakes
   delay(300);
   motor2.drive(-speed,500);  //goes right backwards
   motor2.brake();  //brakes
   delay(300);
   motor2.drive(speed,250); //goes right
   motor2.brake();  //brakes
   delay(1000);
   

   forward(motor1, motor2, speed); //goes forward
   delay(250);
   brake(motor1, motor2); //brakes
   delay(300);
   back(motor1, motor2, -speed);  //goes backwards
   delay(500);
   brake(motor1, motor2); //brakes
   delay(300);
   forward(motor1, motor2, speed);  //goes forward
   delay(250);
   brake(motor1, motor2); //brakes
   delay(1000);
   

   left(motor1, motor2, speed); //turns left
   delay(300);
   brake(motor1, motor2); //brakes
   delay(300);
   right(motor1, motor2, speed);  //turns right
   delay(600);
   brake(motor1, motor2); //brakes
   delay(300);
   left(motor1, motor2, speed); //turns left
   delay(300);
   brake(motor1, motor2);  //brakes
   delay(1000);
   
}


