#include <vector>
#include "Floor.h"
using namespace std;

Floor::Floor(string nameFloor, int numFloor) {
	this->nameFloor = nameFloor;
	this->numFloor = numFloor;
}
void Floor::addPassenger(Passenger p){
	passengers.push_back(p);
}

void Floor::setStateFloorDoor(bool state) {
	stateFloorDoor = state;
}
bool Floor::getStateFloorDoor() {
	return stateFloorDoor;
}

void Floor::openDoor(){
	stateFloorDoor = true;
}
void Floor::closeDoor(){
	stateFloorDoor = false;
}
