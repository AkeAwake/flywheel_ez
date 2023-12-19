#include "main.h"

bool debug = false;
bool spin = false;
//bool pressed = false;


void debugtest(){

/*//Motor1 = 600;

if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and !debug){

    spin = true;

} 

if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) and pressed = false){

    debug = true;
    spin = false;
    pros::delay(100);
    master.clear();

}

if (debug){

    int titleBlinkRate = 100;
    int cursorBlinkRate = 40;
    int numOptions = 4;
    bool titleOn = false;
    bool cursorOn = false;
    bool updateScreen = true;
    int count = 0;
    int option = 0;
    
    
    pros::delay(100);
    master.clear();
    pros::delay(100);
    

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){

        if(0 < option){
        option--;
        updateScreen = true;
      }
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

        if(option < numOptions-1){
        option++;
        updateScreen = true;
      }

    }

    if (controller.get_ditigal(pros::E_CONTROLLER_DIGITAL_A)){

        debugOptions(true, option);

    }

    if(count%titleBlinkRate == 0)
    {
      titleOn = !titleOn;
      updateScreen = true;
    }
    if(count%cursorBlinkRate == 0)
    {
      cursorOn = !cursorOn;
      updateScreen = true;
    }
 
    if(updateScreen){

        master.clear();
 
        if(option == 0){
        master.set_text(0, 0, "Debug Mode");
        }
    }

}




if (spin){

    Motor1 = 600;
}*/

}