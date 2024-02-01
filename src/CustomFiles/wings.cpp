#include "main.h"

// Toggle states for different mechanisms
bool wingToggle = false;
bool pressedWingToggle = false;

bool leftToggle = false;
bool pressedLeftToggle = false;

bool rightToggle = false;
bool pressedRightToggle = false;

bool backToggle = false;
bool pressedBackToggle = false;

//bool blockerToggle = false;
//bool pressedBlockerToggle = false;

// Digital outputs for different mechanisms
pros::ADIDigitalOut leftWing('A', false);
pros::ADIDigitalOut backleftWing('F', false);
pros::ADIDigitalOut backrightWing('B', false);
pros::ADIDigitalOut parkHang('D', false);
pros::ADIDigitalOut rightWing('E', false);

// Function to set the states of wings and other mechanisms
void setWings() {
    // Blocker toggle logic
    /*if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !pressedBlockerToggle) {
        blockerToggle = !blockerToggle;
        pressedBlockerToggle = true;
        //pros::delay(100);
    }

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) || !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        pressedBlockerToggle = false;
        //pros::delay(100);
    }*/

    // Wing toggle logic
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !pressedWingToggle) {
        wingToggle = !wingToggle;
        pressedWingToggle = true;
        //pros::delay(100);
    }

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) || !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        pressedWingToggle = false;
        //pros::delay(100);
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !pressedBackToggle) {
        backToggle = !backToggle;
        pressedBackToggle = true;
        //pros::delay(100);
    }

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) || !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        pressedBackToggle = false;
        //pros::delay(100);
    }

    // Left wing toggle logic
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) && !pressedLeftToggle) {
        leftToggle = !leftToggle;
        pressedLeftToggle = true;
        //pros::delay(100);
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        pressedLeftToggle = false;
        //pros::delay(100);
    }

    // Right wing toggle logic
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && !pressedRightToggle) {
        rightToggle = !rightToggle;
        pressedRightToggle = true;
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        pressedRightToggle = false;
        //pros::delay(100);
    }

    // Set wing states based on toggle conditions
    if (wingToggle) {
        leftWing.set_value(true);
        rightWing.set_value(true);
        //pros::delay(100);
    } /*else if (!wingToggle && !leftToggle && rightToggle) {
        leftWing.set_value(false);
        rightWing.set_value(true);
        //pros::delay(100);
    } else if (!wingToggle && leftToggle && !rightToggle) {
        leftWing.set_value(true);
        rightWing.set_value(false);
        //pros::delay(100);
    } else if (!wingToggle && leftToggle && rightToggle) {
        leftWing.set_value(true);
        rightWing.set_value(true);
        //pros::delay(100);
    }*/ else if (!wingToggle /*&& !leftToggle && !rightToggle*/) {
        leftWing.set_value(false);
        rightWing.set_value(false);
        //pros::delay(100);
    }

    if (backToggle) {

        backleftWing.set_value(true);
        backrightWing.set_value(true);

    } else if (!backToggle) {

        backleftWing.set_value(false);
        backrightWing.set_value(false);

    }

    // Set blocker state based on blockerToggle
    /*if (blockerToggle) {
        hangUp.set_value(true);
    } else {
        hangUp.set_value(false);
    }*/

    // Manual control for hang mechanism
    /*if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        parkHang.set_value(true);
        pros::delay(700);
        parkHang.set_value(false);
    }*/
}

// Function to turn on both wings
void wingsOn() {
    leftWing.set_value(true);
    rightWing.set_value(true);
}

// Function to turn off both wings
void wingsOff() {
    leftWing.set_value(false);
    rightWing.set_value(false);
}
