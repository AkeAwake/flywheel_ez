#include "main.h"

bool kickerToggle = false;
bool pressedKickerToggle = false;

bool verthang = false;
bool horizontalhang = false;
bool bringdown = false;

bool pastv = false;
bool pasth = false;

std::uint32_t now2 = pros::millis();

pros::ADIDigitalOut PTO('C', false);
pros::ADIDigitalOut Ratchet('D', false);

int setKicker(){

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and !pressedKickerToggle) {
        kickerToggle = !kickerToggle;
        pressedKickerToggle = true;
    }

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        pressedKickerToggle = false;
    }

    if (kickerToggle){

        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        PTO.set_value(false);
        Ratchet.set_value(false);
        Flywheel = 92.25;
        Kicker2 = 92.25;

    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){

        verthang = true;
        
    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){

        horizontalhang = true;

    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

        bringdown = true;

    }

    else {

        Flywheel = 0;
        Kicker2 = 0;

    }

    if (verthang){

        PTO.set_value(true);
        Ratchet.set_value(false);
        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Flywheel.tare_position();
        Kicker2.tare_position();

        if ((Flywheel.get_position() > 1960)){

            pastv = true;

        }
        
        if((Flywheel.get_position() < 1960) and !pastv){

            Flywheel = -127;
            Kicker2 = -127;

        }
        
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

            Flywheel = 127;
            Kicker2 = 127;
        }
        

    } else {

        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    }

    if (horizontalhang){

        PTO.set_value(true);
        Ratchet.set_value(false);
        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Flywheel.tare_position();
        Kicker2.tare_position();

        if((Flywheel.get_position() > 1052)){

            pasth = true;

        }
        
        if((Flywheel.get_position() < 1052) and !pasth){

            Flywheel = -127;
            Kicker2 = -127;

        }

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

            Flywheel = 127;
            Kicker2 = 127;
        }
        

    } else {

        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    }

    /*if (bringdown){

        PTO.set_value(true);
        Ratchet.set_value(false);
        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Flywheel.tare_position();
        Kicker2.tare_position();

        if((Flywheel.get_raw_position(&now2) >= 0) ){

            Flywheel = 127;
            Kicker2 = 127;

        } else {

            bringdown = false;
        }
        

    }*/

    return 0;

}


void KickerON(){

    Flywheel = 127;

}

void KickerOFF(){

    Flywheel = 0;

}