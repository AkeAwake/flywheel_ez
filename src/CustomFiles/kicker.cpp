#include "main.h"

bool kickerToggle = false;
bool pressedKickerToggle = false;

bool verthang = false;
bool horizontalhang = false;
bool bringdown = false;

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

        PTO.set_value(false);
        Ratchet.set_value(false);
        Flywheel = 92.25;
        Kicker2 = 92.25;

    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){

        verthang = true;
        
    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){

        horizontalhang = true;

    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)){

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

        if((Flywheel.get_raw_position(&now2) > -4850) and !(Flywheel.get_raw_position(&now2) < -4750)){

            Flywheel = -127;
            Kicker2 = -127;

        } else {

            verthang = false;
        }
        

    }

    if (horizontalhang){

        PTO.set_value(true);
        Ratchet.set_value(false);
        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Flywheel.tare_position();
        Kicker2.tare_position();

        if((Flywheel.get_raw_position(&now2) > -2550) and !(Flywheel.get_raw_position(&now2) < -2450)){

            Flywheel = -127;
            Kicker2 = -127;

        } else {

            horizontalhang = false;
        }
        

    }

    if (bringdown){

        PTO.set_value(true);
        Ratchet.set_value(false);
        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Flywheel.tare_position();
        Kicker2.tare_position();

        if((Flywheel.get_raw_position(&now2) < 5) and !(Flywheel.get_raw_position(&now2) < 0)){

            Flywheel = 127;
            Kicker2 = 127;

        } else {

            bringdown = false;
        }
        

    }

    return 0;

}

void setHang(){

    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){

        PTO.set_value(true);
        pros::delay(400);
        Flywheel = -127;
        Kicker2 = -127;

    }

    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

        PTO.set_value(true);
        Ratchet.set_value(true);
        pros::delay(400);
        Flywheel = 127;
        Kicker2 = 127;

    }

    else {

        Flywheel = 0;
        Kicker2 = 0;

    }


}

void KickerON(){

    Flywheel = 127;

}

void KickerOFF(){

    Flywheel = 0;

}