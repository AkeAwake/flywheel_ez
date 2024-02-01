#define PROS_USE_LITERALS
#include "api.h"
#include "EZ-Template/api.hpp"

//Motors
extern pros::Motor frontLeft;
extern pros::Motor frontRight;
extern pros::Motor middleLeft;
extern pros::Motor middleRight;
extern pros::Motor backLeft;
extern pros::Motor backRight;
extern pros::Motor Flywheel;
extern pros::Motor Intake;
extern pros::Motor Kicker2;

//Sensors
//extern pros::ADIAnalogIn liftPot;
extern pros::Imu inertial;
extern pros::ADIDigitalOut leftWing;
extern pros::ADIDigitalOut rightWing;
extern pros::Rotation rotational_sensor;
//extern pros::ADIDigitalOut dumpTruckRight;
//extern pros::ADIEncoder trackingWheel;
//extern pros::ADIDigitalOut goalCover;
//extern pros::ADIDigitalOut elStick;

//Controller
extern pros::Controller controller;

//Helper Variables
//extern bool clawToggle;
//extern bool dumpToggle;
//extern bool stickToggle;