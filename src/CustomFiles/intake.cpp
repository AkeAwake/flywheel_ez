#include "main.h"

bool intaketoggle = false;
bool pressed = false;

// pros::Rotation rotation_sensor(15);

void setIntake(){

        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) and !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

            Intake = -127;

        }
    
        else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

            Intake = 127;

        }

        else {

            Intake = 0;

        }

}

void intakeON(){

    Intake = 127;

}

void intakeREVERSE(){

    Intake = -127;

}

void intakeOFF(){

    Intake = 0;

}