#include <iostream>
#include "Lift.h"
#include "Floor.h"
#include "Controller.h"
#include "Button.h"
#include <string>
#include "Safety.h"
using namespace std;



int main() {
	Safety safety;
	Controller controller;
	Lift l(0,5,400);
	Button openDoorB("OpenDoor", false);
	Floor f1("First", 1);
	Floor f2("Second", 2);
	Floor f3("Third", 3);
	Floor f4("Fourth", 4);
	Floor f5("Fifth", 5);
	l.setOnService(true);
	l.setSpeed(50);
	openDoorB.butState = true;
	controller.stopLift(l);	/// den doulevei kanonika prepei na kanei to speed tou lift =0
	//l.setSpeed(0);
	if (openDoorB.isPressed("OpenDoor")){
		controller.checkToOpenDoor(l,f1);
	}
	Button emergencyB("emergency", false);
	emergencyB.butState = true;
	controller.emergencyButton(l, emergencyB);


	return 0;
}
