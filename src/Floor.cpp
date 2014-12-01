#include <vector>
#include "Floor.h"
using namespace std;

Floor::Floor(string nameFloor, int numFloor, int openDoorTime, int closeDoorTime){
	this->nameFloor = nameFloor;
	this->numFloor = numFloor;
	this->openDoorTime = openDoorTime;
	this->closeDoorTime = closeDoorTime;
	Button button("Button up", false);
	buttons.push_back(button);
	Button button1("Button down", false);
	buttons.push_back(button1);
	cout << nameFloor << " Buttons:" << endl;
	for (int i=0; i<2; i++){
		cout << "Button:" << buttons[i].buttonName << endl;
	}
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
