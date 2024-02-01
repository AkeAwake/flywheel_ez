#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::ADIDigitalOut liftUp('G', false);

int flywheel_ratio_fraction = 0.285714286;

double proportionalGain = 15.2;
double integralGain = 0.001;
double derivativeGain = 0.2;

int target = 10000;
int currentRPM = 0;

int delta_time = 0;
int last_time = 0;
int last_error = 0;

bool isFlywheelOn = false;
bool flypressed = false;

bool isFlywheelOn2 = false;
bool flypressed2 = false;

bool blockerToggle = false;
bool pressedBlockerToggle = false;

int setFlywheel() {
    int error = target - currentRPM;

    double proportional = proportionalGain * error;

    int sumError = error * integralGain * delta_time;

    if (sumError > 50) {
        sumError = 50;
    }

    double integral = sumError;

    double derivative = derivativeGain * (error - last_error) / delta_time;

    double result = (proportional + integral + derivative) + currentRPM + 100;

    if (result > 1000) {
        result = 1000;
    }

    if (result < 20) {
        result = 20;
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and !flypressed) {
        isFlywheelOn = !isFlywheelOn;
        flypressed = true;

        /*pros::delay(100);
        master.clear();
        pros::delay(100);
        master.print(0, 0, "speed %d", Flywheel.get_actual_velocity());*/
        
    }

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        flypressed = false;

        
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) and !flypressed2) {
        isFlywheelOn2 = !isFlywheelOn2;
        flypressed2 = true;
        
    }

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
        flypressed2 = false;

        
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !pressedBlockerToggle) {
        blockerToggle = !blockerToggle;
        pressedBlockerToggle = true;
        //pros::delay(100);
    }

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) || !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        pressedBlockerToggle = false;
        //pros::delay(100);
    }

    if (isFlywheelOn) {

        Flywheel = 127;
        liftUp.set_value(true);
        //Flywheel = 127;
        

    }

    else if (!isFlywheelOn and isFlywheelOn2) {

        Flywheel = result;

    }

    else if (!isFlywheelOn and !isFlywheelOn2) {

        Flywheel = 0;
        liftUp.set_value(false);

    }

    if (blockerToggle and !isFlywheelOn) {
        liftUp.set_value(true);
    } else if (!blockerToggle and !isFlywheelOn){
        liftUp.set_value(false);
    }

    return 0;

}

int updateFlywheelRPM() {
    int encoderValue = Flywheel.get_actual_velocity();
    // If get_actual_velocity() already returns RPM, no need for conversion
    currentRPM = encoderValue;

    return 0;
}

int updateDelta() {
    int current_time = pros::millis();
    delta_time = current_time - last_time;
    last_time = current_time;

    return 0;
}


/*#include "main.h"

pros::Rotation rotational_sensor(15);

bool pressedonce = false;
bool pos1 = true;
bool matchload = false;
bool matchloadtoggle = false;
int speed = 0;

bool switchHasBeenPressedAlready = true;
bool buttonHasBeenPressedAlready = false;
bool Catapultstopped = false;

// IN MILISECONDS
int CataStoppingTime = 0;

// This is the height to push into goal
int degree1 = 120;

//This is the height the lowest the Catapult can physically go
int bottomheight = 106;

// This is where you want the Catapult to start slowing down at
int topheight = 145;

// This is the height to intake at
//int degree2 = 110;

int setFlywheel(){
    
    /*pros::delay(100);
    master.clear();
    pros::delay(100);
    master.print(0, 0, "Counter: %d", (rotational_sensor.get_angle()/100));
            
    if (!switchHasBeenPressedAlready and (rotational_sensor.get_angle()/100) <= degree1){ 
        switchHasBeenPressedAlready = true;
        buttonHasBeenPressedAlready = false;
        pros::delay(CataStoppingTime);
        Catapult = 0;
        Catapultstopped = true;
    }

    else if ((rotational_sensor.get_angle()/100) > degree1){
        switchHasBeenPressedAlready = false;
    }
 
    if (!buttonHasBeenPressedAlready and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        buttonHasBeenPressedAlready  = true;
        Catapult = 127;
        Catapultstopped = false;
        buttonHasBeenPressedAlready = false;
    }

    else if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        buttonHasBeenPressedAlready  = false;
    }

    if (Catapultstopped and (rotational_sensor.get_angle()/100) > degree1){
        Catapult = 127;
        Catapultstopped = false;
        switchHasBeenPressedAlready = false;
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        Catapult = 0;
    }
            
            
            
            
            /*((rotational_sensor.get_angle()/100) <= degree1 /*and pos1){
            
                Catapult = 0;
                speed = 0;

                if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and (rotational_sensor.get_angle()/100) >= bottomheight and pressedonce/*and !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

                    Catapult = 127;
                    speed = 127;

                }

            }
        
            /*if((rotational_sensor.get_angle()/100) < degree2 and !pos1){
            
                Catapult = 0;
                pos1 = true;

            }

            if((rotational_sensor.get_angle()/100) <= topheight and (rotational_sensor.get_angle()/100) >= degree1 /*and pos1){

                Catapult = 70;
                speed = 70;

            }

            /*if((rotational_sensor.get_angle()/100) < topheight and (rotational_sensor.get_angle()/100) > degree2 and !pos1){

                Catapult = 70;
                speed = 70;

            }

            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and !pressedonce /*and (rotational_sensor.get_angle()/100) > 120 and !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

                Catapult = 127;
                speed = 127;

                pressedonce = true;

            }

            

            /*if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

                pos1 = false;

            }


    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        Catapult = 0;
        speed = 0;
    }

    return 0;

}

int autocata(){

    /*while (true){
    pros::delay(100);
    master.clear();
    pros::delay(100);
    master.print(0, 0, "Counter: %d", (rotational_sensor.get_angle()/100));

        if ((rotational_sensor.get_angle()/100) > topheight){

            Catapult = 127;
            speed = 127;

        }

        if((rotational_sensor.get_angle()/100) < topheight and (rotational_sensor.get_angle()/100) > (degree1) and !(speed == 0)){

            Catapult = 60;
            speed = 60;

        }

        if((rotational_sensor.get_angle()/100) < (degree1)){
                
            Catapult = 0;
            speed = 0;

        }
    }

    Catapult = 127;
    pros::delay(200);
    Catapult = 0;

    return 0;

}*/