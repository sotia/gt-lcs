#include "Passenger.h"
#include <iostream>
#include <ctime>
using namespace std;

Passenger::Passenger(int weight, int destinationFloor, int originalFloor, float time) {
	this->weight = weight;
	this->destinationFloor = destinationFloor;
	this->originalFloor = originalFloor;
	this->time = time;
}

float Passenger::waitingTime(){
	float waiting = float(clock() - time);
	return waiting;
}

