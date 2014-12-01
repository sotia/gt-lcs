#ifndef Floor_H
#define Floor_H
#include <string>
#include <vector>
#include "Passenger.h"
#include "Button.h"
using namespace std;
class Floor {
public:
	Floor(string nameFloor, int numFloor, int openDoorTime, int closeDoorTime);
	void addPassenger(Passenger p);
	void setStateFloorDoor(bool state);
	bool getStateFloorDoor();
	void openDoor();
	void closeDoor();
	int numFloor;
	string nameFloor;
	int openDoorTime;
	int closeDoorTime;
	vector<Button> buttons;
private:

	vector<Passenger> passengers;
	bool stateFloorDoor;

};
#endif
