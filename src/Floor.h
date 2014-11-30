#ifndef Floor_H
#define Floor_H
#include <string>
#include <vector>
#include "Passenger.h"
using namespace std;

class Floor {
public:
	Floor(string nameFloor, int numFloor);
	void addPassenger(Passenger p);
	void setStateFloorDoor(bool state);
	bool getStateFloorDoor();
	void openDoor();
	void closeDoor();
private:
	int numFloor;
	string nameFloor;
	vector<Passenger> passengers;
	bool stateFloorDoor;

};
#endif
