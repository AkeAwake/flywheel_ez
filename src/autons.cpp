#include "main.h"
#include "pros/imu.h"
#include "pros/screen.h"

pros::ADIDigitalOut lWing('F', false);
pros::ADIDigitalOut rWing('A', false);
pros::ADIDigitalOut blocker('G', false);


void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

void wingintask(){

  rWing.set_value(false);
  lWing.set_value(false);

}

void wingouttask(){

  rWing.set_value(true);
  lWing.set_value(true);

}

void leftwingouttask(){

  lWing.set_value(true);

}

void leftwingintask(){

  lWing.set_value(false);

}

void rightwingouttask(){

  rWing.set_value(true);

}

void rightwingintask(){

  rWing.set_value(false);

}

void start(){

  lWing.set_value(true);

  Intake = 127;

  pros::delay(400);

  lWing.set_value(false);

}

void drivermacro(){

    chassis.set_turn_pid(-30, 127);
    chassis.wait_drive();

    chassis.set_drive_pid(-70, 127, true);
    chassis.wait_drive();

    chassis.set_turn_pid(0, 127);
    chassis.wait_drive();

    chassis.set_drive_pid(15, 127, true);
    chassis.wait_drive();

    chassis.set_turn_pid(-111, 127);
    chassis.wait_drive();

    chassis.set_drive_pid(-6, 127, true);
    chassis.wait_drive();

    //rWing.set_value(true);

    Intake = 0;

    Flywheel = 127;

    pros::delay(50000);

    Flywheel = 0;


}

//pros::Imu inertial(19);


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 127; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 127;
const int SWING_SPEED = 127;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void maxdrive(){

  frontRight.move(127);
  frontLeft.move(-127);
  middleRight.move(127);
  middleLeft.move(-127);
  backRight.move(127);
  backLeft.move(-127);

  pros::delay(500);

  frontRight.move(0);
  frontLeft.move(0);
  middleRight.move(0);
  middleLeft.move(0);
  backRight.move(0);
  backLeft.move(0);
}


void fiveball() {
  
  //pros::Task catatask(autocata);
  
  intakeON();

  //pros::delay(400);
  
  chassis.set_drive_pid(10, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-63, 127, true);
  chassis.wait_drive();

  leftwingouttask();

  chassis.set_swing_pid(ez::LEFT_SWING, -77, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();

  leftwingintask();
  //lWing.set_value(false);

  chassis.set_turn_pid(-75, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-32, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(19, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-190, 127);
  chassis.wait_drive();

  pros::Task intake2(intakeREVERSE);

  chassis.set_swing_pid(ez::RIGHT_SWING, -270, 127);
  chassis.wait_drive();


  //rWing.set_value(true);

  //pros::delay(200);

  //maxdrive(); 

  chassis.set_drive_pid(-10, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(27, 127);
  chassis.wait_drive();

  pros::Task intake3(intakeOFF);

  //rWing.set_value(false);

  chassis.set_drive_pid(-15, 100, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-339, 127);
  chassis.wait_drive();

  pros::Task intake4(intakeON);

  chassis.set_drive_pid(92, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-210, 127);
  chassis.wait_drive();

  pros::Task intake5(intakeREVERSE);

  pros::delay(300);

  /*chassis.set_drive_pid(25, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-35, 127, true);
  chassis.wait_drive();*/

  pros::Task intake6(intakeON);

  chassis.set_turn_pid(-291, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(50, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-180, 127);
  chassis.wait_drive();

  pros::Task wings3(wingouttask);

  chassis.set_drive_pid(20, 127, true);
  chassis.wait_drive();

  pros::Task intake7(intakeREVERSE);

  chassis.set_drive_pid(50, 127, true);
  chassis.wait_drive();

  pros::Task wings4(wingintask);
  //rWing.set_value(false);
  //lWing.set_value(false);

  chassis.set_drive_pid(-30, 127, true);
  chassis.wait_drive();

  //chassis.set_turn_pid(45, 127);
  //chassis.wait_drive();

  //chassis.set_turn_pid(0, 127);
  //chassis.wait_drive();


}

void AWPUnder() {
  
  //pros::Task catatask(autocata);
  
  Intake = 127;

  pros::delay(400);
  
  //chassis.set_drive_pid(24, 127, true);
  //chassis.wait_drive();

  chassis.set_drive_pid(-50, 127, true);
  chassis.wait_drive();

  //Catapult = 0;

  lWing.set_value(true);

  chassis.set_swing_pid(ez::LEFT_SWING, -82, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, 127, true);
  chassis.wait_drive();

  lWing.set_value(false);
  lWing.set_value(false);

  chassis.set_drive_pid(35, 127, true);
  chassis.wait_drive();

  pros::delay(200);

  chassis.set_turn_pid(-235, 127);
  chassis.wait_drive();

  Intake = -127;

  //rWing.set_value(true);

  pros::delay(100);

  chassis.set_drive_pid(57, 127, true);
  chassis.wait_drive();

  Intake = 0;

  rWing.set_value(false);

  chassis.set_drive_pid(-15, 100, true);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_turn_pid(-333, 127);
  chassis.wait_drive();

  intakeON();

  pros::delay(100);

  chassis.set_drive_pid(70, 127, true);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_turn_pid(-200, 127);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(45, 127, true);
  chassis.wait_drive();
  
  Intake = -127;

  chassis.set_drive_pid(35, 127, true);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(-25, 127, true);
  chassis.wait_drive();

  Intake = 127;

  chassis.set_turn_pid(-30, 127);
  chassis.wait_drive();

  pros::delay(100);

  lWing.set_value(true);

  chassis.set_drive_pid(45, 127, true);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_turn_pid(10, 127);
  chassis.wait_drive();

  Intake = 0;

  //chassis.set_turn_pid(45, 127);
  //chassis.wait_drive();

  //chassis.set_turn_pid(0, 127);
  //chassis.wait_drive();


}

void RushNear(){

  //chassis.set_turn_pid(18, 127);
  //chassis.wait_drive();

  pros::Task starttask(start);

  chassis.set_drive_pid(100, 127, false);
  chassis.wait_drive();

  lWing.set_value(false);

  chassis.set_drive_pid(-13, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(72, 127);
  chassis.wait_drive();

  Intake = -127;

  //lWing.set_value(true);

  chassis.set_drive_pid(47, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(10, 127);
  chassis.wait_drive();

  Intake = 127;

  chassis.set_drive_pid(13, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-9, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(72, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(23, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-23, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(27, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-68, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 162, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(155, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(23, 127, true);
  chassis.wait_drive();

  rWing.set_value(true);

  //chassis.set_swing_pid(ez::RIGHT_SWING, 94, 127);
  //chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 45, 127);
  chassis.wait_drive();

  rWing.set_value(false);
  lWing.set_value(true);

  chassis.set_turn_pid(85, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(80, 127, true);
  chassis.wait_drive();

  //lWing.set_value(true);

}

void RushNearElims(){

  //chassis.set_turn_pid(18, 127);
  //chassis.wait_drive();

  pros::Task starttask(start);

  chassis.set_drive_pid(100, 127, false);
  chassis.wait_drive();

  lWing.set_value(false);

  chassis.set_drive_pid(-13, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(72, 127);
  chassis.wait_drive();

  Intake = -127;

  //lWing.set_value(true);

  chassis.set_drive_pid(47, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(10, 127);
  chassis.wait_drive();

  Intake = 127;

  chassis.set_drive_pid(13, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-9, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(72, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(23, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-23, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(27, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-68, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 162, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 55, 127);
  chassis.wait_drive();

  blocker.set_value(true);

  /*chassis.set_turn_pid(155, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(23, 127, true);
  chassis.wait_drive();

  rWing.set_value(true);

  //chassis.set_swing_pid(ez::RIGHT_SWING, 94, 127);
  //chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 45, 127);
  chassis.wait_drive();

  rWing.set_value(false);
  //lWing.set_value(true);

  chassis.set_turn_pid(55, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-20, 127, true);
  chassis.wait_drive();*/

  blocker.set_value(true);

  //lWing.set_value(true);

}

void AWPOver(){

  //pros::Task catatask(autocata);
  
  Intake = 127;

  pros::delay(400);

  chassis.set_turn_pid(-25, 127);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(40, 127, true);
  chassis.wait_drive();

  Intake = -127;
  
  pros::delay(100);

  chassis.set_drive_pid(5, 127, true);
  chassis.wait_drive();

  Intake = 0;

  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();

  lWing.set_value(true);

  pros::delay(100);

  chassis.set_swing_pid(ez::LEFT_SWING, -80, 127);
  chassis.wait_drive();

  //Catapult = 127;
  //pros::delay(200);
  //Catapult = 0;

  pros::delay(100);

  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();

  lWing.set_value(false);
  lWing.set_value(false);

  rWing.set_value(true);

  pros::delay(100);

  chassis.set_drive_pid(-20, 127, true);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_turn_pid(-65, 127);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(-20, 127, true);
  chassis.wait_drive();

  pros::delay(100);

  chassis.set_turn_pid(-35, 127);
  chassis.wait_drive();

  rWing.set_value(false);


}

void skills(){

  //Intake = 127;

  chassis.set_turn_pid(-30, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-70, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();

  Flywheel = 127;

  chassis.set_turn_pid(-111, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();

  //rWing.set_value(true);

  Intake = 0;
  
  blocker.set_value(true);

  pros::delay(27000);

  Flywheel = 0;

  blocker.set_value(false);

  chassis.set_turn_pid(-45, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(55, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(155, 127, true);
  chassis.wait_drive();

  Intake = 0;

  chassis.set_swing_pid(ez::RIGHT_SWING, -135, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(20, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -180, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(35, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(30, 127, true);
  chassis.wait_drive();

  //chassis.set_drive_pid(-10, 127, true);
  //chassis.wait_drive();

  Intake = 0;

  chassis.set_turn_pid(-270, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(75, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, -125, 127);
  chassis.wait_drive();

  wingouttask();

  Intake = -127;

  chassis.set_drive_pid(55, 127, true);
  chassis.wait_drive();

  wingintask();

  Intake = 0;

  chassis.set_drive_pid(-50, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-180, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(30, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();

  wingouttask();

  Intake = -127;

  chassis.set_drive_pid(50, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-50, 127, true);
  chassis.wait_drive();

  wingintask();

  Intake = 0;

  chassis.set_turn_pid(-150, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(90, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, -45, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(20, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, 0, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(20, 127, true);
  chassis.wait_drive();

  Intake = 0;

  chassis.set_swing_pid(ez::LEFT_SWING, -45, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(40, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(70, 127, true);
  chassis.wait_drive();

  wingouttask();

  Intake = -127;

  chassis.set_swing_pid(ez::RIGHT_SWING, -90, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(40, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, 127, true);
  chassis.wait_drive();

  wingintask();

  Intake = 0;



  /*Intake = -127;

  chassis.set_turn_pid(-109, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(95, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-195, 127);
  chassis.wait_drive();

  Intake = 127;

  chassis.set_drive_pid(40, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(35, 127, true);
  chassis.wait_drive();

  Intake = 0;

  chassis.set_drive_pid(-60, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(95, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(125, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-180, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(15, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -270, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(25, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, -180, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(40, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 127);
  chassis.wait_drive();

  wingouttask();

  chassis.set_drive_pid(60, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-70, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-60, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-110, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(60, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();

  //wingintask();

  Intake = 0;

  chassis.set_turn_pid(-65, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-50, 127, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-135, 127);
  chassis.wait_drive();

  wingouttask();

  chassis.set_drive_pid(90, 127, true);
  chassis.wait_drive();

  leftwingintask();

  chassis.set_turn_pid(-65, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(25, 127, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, 0, 127);
  chassis.wait_drive();

  Intake = -127;

  chassis.set_drive_pid(25, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(30, 127, true);
  chassis.wait_drive();

  Intake = 0;

  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();*/

  

}

void skillstest(){

  Flywheel = 127;

  pros::delay(30000);

  Flywheel = 0;

}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  lWing.set_value(true);

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(1000);

  lWing.set_value(false);

  pros::delay(500);

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///


// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .