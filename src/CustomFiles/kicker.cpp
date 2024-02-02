#include "main.h"

bool kickerToggle = false;
bool offToggle = true;
bool pressedKickerToggle = false;

bool verthang = false;
bool horizontalhang = false;
bool bringdown = false;

bool pastv = false;
bool pasth = false;

float pose = 0;

pros::ADIDigitalOut PTO('C', false);
pros::ADIDigitalOut Ratchet('D', false);
pros::ADIDigitalOut leftmatchloadWing('F', false);
pros::ADIDigitalOut rightmatchloadWing('B', false);

int setKicker(){

    pose = Flywheel.get_position();

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and !pressedKickerToggle) {
        kickerToggle = !kickerToggle;
        offToggle = !offToggle;
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
        leftmatchloadWing.set_value(true);
        rightmatchloadWing.set_value(true);

    } else if (!kickerToggle and (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) and !verthang and !horizontalhang and !bringdown){

        PTO.set_value(true);
        Ratchet.set_value(false);
        Flywheel.tare_position();
        verthang = true;
        
    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) and !verthang and !horizontalhang and !bringdown){

        PTO.set_value(true);
        Ratchet.set_value(false);
        Flywheel.tare_position();
        horizontalhang = true;

    } else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) and !bringdown){

        PTO.set_value(true);
        Ratchet.set_value(false);
        bringdown = true;

    }

    else {

        //Flywheel = 0;
        // Kicker2 = 0;

        leftmatchloadWing.set_value(false);
        rightmatchloadWing.set_value(false);

        Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    }

    if (verthang){

        //Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        //Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        if ((pose < -5050)){

            Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            
            Flywheel = 0;
            Kicker2 = 0;
            pastv = true;

        }
        
        if((pose > -5050) and !pastv){

            Flywheel.move_voltage(-12000);
            Kicker2.move_voltage(-12000);

        }
        
        if (bringdown){

            if ((pose < 0)){

                Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                
                Flywheel.move_voltage(12000);
                Kicker2.move_voltage(12000);

            }
        }
        

    }

    if (horizontalhang){

        //Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        //Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        if((pose < -2550)){

            Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

            Flywheel = 0;
            Kicker2 = 0;
            pasth = true;

        }
        
        if((pose > -2550) and !pasth){

            Flywheel.move_voltage(-12000);
            Kicker2.move_voltage(-12000);

        }

        if (bringdown){

            if ((pose < 0)){

                Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

                Flywheel.move_voltage(12000);
                Kicker2.move_voltage(12000);

            }
        }
        

    }

    return 0;

}


void KickerON(){

    Flywheel = 127;

}

void KickerOFF(){

    Flywheel = 0;

}