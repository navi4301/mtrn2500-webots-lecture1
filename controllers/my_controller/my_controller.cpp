// File:          my_controller.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

const int TIME_STEP {64};
const double MAX_SPEED {6.28};

int main(int argc, char **argv) {
  // tut dynamically allocate memory but for assignment purposes we can define on stack
  // also dont use namespace
  webots::Robot robot {};
  // we need to define the two motors
  // motos are defined as class in motor
  // we use get motor to return a pointer that points to motor with name
  webots::Motor* leftMotor {robot.getMotor("left wheel motor")};
  webots::Motor* rightMotor {robot.getMotor("right wheel motor")};
  // need to set absolute position of motor
  // leftMotor->setPosition(10.0);
  // rightMotor->setPosition(10.0);

  // set position to infinity so that we can set velocity
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);

  // leftMotor->setVelocity(0.1 * MAX_SPEED);
  // rightMotor->setVelocity(0.1 * MAX_SPEED);

  // to rotate our robot we set one of the motors to -ve speed (in this case rotates clockwise)
  leftMotor->setVelocity(0.1 * MAX_SPEED);
  rightMotor->setVelocity(-0.1 * MAX_SPEED);


  while(robot.step(TIME_STEP) != -1);

  return 0;
}
