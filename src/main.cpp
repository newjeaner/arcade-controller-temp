/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       newjeaner                                                 */
/*    Created:      10/21/2023, 10:09:41 AM                                   */
/*    Description:  tank example                                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here

controller controller1 = controller(controllerType::primary); // adjust whether it's primary or secondary

// replace the numbers after 'PORT' with the actual port number (no spaces)
motor leftFrontMotor = motor(PORT1);
motor leftMiddleMotor = motor(PORT2);
motor leftBackMotor = motor(PORT3);
motor rightFrontMotor = motor(PORT4);
motor rightMiddleMotor = motor(PORT5);
motor rightBackMotor = motor(PORT6);

motor_group leftSide = motor_group(leftFrontMotor, leftMiddleMotor, leftBackMotor);
motor_group rightSide = motor_group(rightFrontMotor, rightMiddleMotor, rightBackMotor);

int main()
{

    Brain.Screen.printAt(10, 50, "Hello V5");

    while (1)
    {

        // x & y axis (left joystick)
        leftSide.spin(directionType::fwd, controller1.Axis3.position() + controller1.Axis1.position(), percentUnits::pct);
        // x & y axis (right joystick)
        rightSide.spin(directionType::fwd, controller1.Axis3.position() - controller1.Axis1.position(), percentUnits::pct);
    }
}
