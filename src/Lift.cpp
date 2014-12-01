#include "Lift.h"
#include <sstream>
#include "Button.h"

using namespace std;

Lift::Lift(int id, int startFloor,int stopFloor, int maxWeight, int timeToNextFloor, int openDoorTime, int closeDoorTime ){
	this->id = id;
	this->startFloor = startFloor;
	this->stopFloor = stopFloor;
	this->maxWeightPeople = maxWeightPeople;
	this->speed = 0;
	this->onService = false;
	this->timeToNextFloor = timeToNextFloor;
	this->openDoorTime = openDoorTime;
	this->closeDoorTime = closeDoorTime;
	this->curWeight = 0;
	string floorName;
	stringstream out;
	for (int i=startFloor; i<=(stopFloor); i++){
		out << i;
		Button button(out.str(), false);
		buttons.push_back(button);
		out.str("");
	}
	Button button("Open Door", false);
	buttons.push_back(button);
	Button button1("Close Door", false);
	buttons.push_back(button1);
	Button button2("Emergency", false);
	buttons.push_back(button2);
	cout << "Lift " << id << " Buttons:" << endl;
	for (int i=0; i<= (stopFloor - startFloor + 3); i++)
		cout << "Button: " << buttons[i].buttonName << endl;
}

bool Lift::isMoveUp() {
	if (speed > 0) {
		return true;
	} else
		return false;
}
bool Lift::isMoveDown() {
	if (speed < 0) {
		return true;
	} else
		return false;
}
int Lift::getSpeed() {
	return speed;
}

bool Lift::isOnService() {
	if (onService == true)
		return true;
	else
		return false;
}
void Lift::addPassenger(Passenger p) {
	passengersInLift.push_back(p);
	curWeight += p.weight;
}

void Lift::removePassenger(Passenger p){
	/* pop the specific passenger and difference the weight from the current weight*/
}

int Lift::getCurWeight(){
	return curWeight;
}

void Lift::setSpeed(int s) {
	if (isOnService()){
		this->speed = s;
	}
	else
		cout << "This lift is not on service!!";
}

void Lift::setOnService(bool state) {
	onService = state;
}
void Lift::setStateLiftDoor(bool state) {
	stateLiftDoor = state;
}
bool Lift::getStateLiftDoor() {
	return stateLiftDoor;
}
void Lift::openDoor(){
	stateLiftDoor = true;
}
void Lift::closeDoor(){
	stateLiftDoor = false;
}
