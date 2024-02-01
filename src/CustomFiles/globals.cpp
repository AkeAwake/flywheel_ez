#include "main.h"

//Motors
pros::Motor frontLeft(1, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRight(10, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor middleLeft(12, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor middleRight(19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeft(15, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRight(17, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Flywheel(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Intake(21, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Kicker2(16, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);

//Sensors & Pistons
//pros::ADIAnalogIn liftPot('C');
//pros::Imu inertial(19);
//pros::ADIDigitalOut leftWing('A', false);
//pros::ADIDigitalOut rightWing('B', false);
//pros::Rotation rotation_sensor(15);
//pros::ADIDigitalOut dumpTruckRight('G', false);
//pros::ADIDigitalOut goalCover('H', false);
//pros::ADIDigitalOut elStick('F', false);

//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);