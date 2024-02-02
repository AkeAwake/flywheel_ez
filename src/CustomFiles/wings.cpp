#include "main.h"

// Digital outputs for different mechanisms
pros::ADIDigitalOut leftWing('A', false);
pros::ADIDigitalOut backleftWing('F', false);
pros::ADIDigitalOut backrightWing('B', false);
pros::ADIDigitalOut rightWing('E', false);

// Function to set the states of wings and other mechanisms
void setWings() {

    // Wing logic
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        
        leftWing.set_value(true);
        rightWing.set_value(true);

        Intake = -127;

    } else {

        leftWing.set_value(false);
        rightWing.set_value(false);

    }

    // Back right wing logic
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        
        backrightWing.set_value(true);

    } else {

        backrightWing.set_value(false);

    }

    // Back left wing toggle logic
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        
        backleftWing.set_value(true);

    } else {

        backleftWing.set_value(false);

    }
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

// Function to turn on both back wings
void backwingsOn() {
    backleftWing.set_value(true);
    backrightWing.set_value(true);
}

// Function to turn off both back wings
void backwingsOff() {
    backleftWing.set_value(false);
    backrightWing.set_value(false);
}
