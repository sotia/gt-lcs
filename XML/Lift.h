#ifndef LIFT_H_
#define LIFT_H_
#include <string>
#include <vector>
#include "Passenger.h"
using namespace std;

class Lift {

private:
	
	int maxWeightPeople;
	int curNumPeople;
	int curNumFloor;
	int speed;
	int toFloor;
	bool onService;
	bool stateLiftDoor;

public:
	int startFloor;
	int stopFloor;
	vector<Passenger> passengersInLift;
	Lift(int startFloor,int stopFloor, int maxWeight);
	bool isMoveUp();
	bool isMoveDown();
	bool isOnService();
	void addPassenger(Passenger p);
	void removePassenger(Passenger p);
	int getCurrentFloor();
	int getSpeed();
	int getWeight();
	int getNumPassengers();
	int getToFloor();
	void setOnService(bool state);
	void setSpeed(int speed);
	void setStateLiftDoor(bool state);
	bool getStateLiftDoor();
	void openDoor();
	void closeDoor();
};

#endif /* LIFT_H_ */
