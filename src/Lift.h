#ifndef LIFT_H_
#define LIFT_H_
#include <string>
#include <vector>
#include "Passenger.h"
#include "Button.h"
using namespace std;

class Lift {

private:
	
	int curNumPeople;
	int curNumFloor;
	int speed;
	int toFloor;
	bool onService;
	bool stateLiftDoor;

public:
	int maxWeightPeople;

	int curWeight;
	int id;
	int startFloor;
	int stopFloor;
	int openDoorTime;
	int closeDoorTime;
	int timeToNextFloor;
	vector<Passenger> passengersInLift;
	vector<Button> buttons;
	Lift(int id, int startFloor,int stopFloor, int maxWeight, int timeToNextFloor, int openDoorTime, int closeDoorTime );
	bool isMoveUp();
	bool isMoveDown();
	bool isOnService();
	void addPassenger(Passenger p);
	void removePassenger(Passenger p);
	int getCurrentFloor();
	int getSpeed();
	int getCurWeight();
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
