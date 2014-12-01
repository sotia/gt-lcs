#include "Controller.h"
#include "Lift.h"
#include <string>
#include "Safety.h"
#include "Floor.h"
using namespace std;

Controller::Controller(vector<Lift> lifts, vector<Floor> floors){
	this->lifts = lifts;
	this->floors = floors;
}

void Controller::checkToOpenDoor(Lift l, Floor f) {
	int curSpeed = l.getSpeed();
	if (curSpeed == 0) {
		l.openDoor();
		f.openDoor();
	} else {
		cout << "Unable to open the doors!!!" << endl;
	}
}
void Controller::stopLift(Lift l) {
	l.setSpeed(0);
}

void Controller::emergencyButton(Lift l, Button b) {
	string buttonName = b.getButtonName();
	if (!buttonName.compare("Emergency")) {
		safety.stopLift(l);
	}
}

void Controller::hazard(Lift l) {
	safety.stopLift(l);
}

void Controller::overloaded(Lift l){
	if (l.getCurWeight() > l.maxWeightPeople){
		safety.stopLift(l);
	}
}
