#include "main.h"

void setBrakes() {
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  middleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  middleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  //Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  Intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void matchloadBrakes(){
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  middleRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  middleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}