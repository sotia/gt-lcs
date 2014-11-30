#include "Lift.h"
using namespace std;

Lift::Lift(int startFloor, int stopFloor, int maxWeight) {
	this->startFloor = startFloor;
	this->stopFloor = stopFloor;
	this->maxWeightPeople = maxWeightPeople;
	this->speed = 0;
	this->onService = false;
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
