#ifndef Controller_H
#define Controller_H
#include <string>
#include <vector>
#include "Button.h"
#include "Lift.h"
#include "Floor.h"
#include "Safety.h"
using namespace std;

class Controller {
public:
	vector<Lift> getLifts();
	vector<Floor> getFloors();
	vector<Floor> getListOfStops();
	void addStop(Floor f);
	void startLift(Lift l);
	void stopLift(Lift l);
	void checkToOpenDoor(Lift l, Floor f);
	void emergencyButton(Lift l, Button b);
	void hazard(Lift l);
	Controller(vector<Lift> lifts, vector<Floor> floors);
	vector<Lift> lifts;
	vector<Floor> floors;
	void overloaded(Lift l);
	Safety safety;

private:
	vector<Floor> listOfStops;

};
#endif
