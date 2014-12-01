#include "Passenger.h"
#include <iostream>
#include <ctime>
using namespace std;

Passenger::Passenger(int weight, int destinationFloor, int originalFloor, float time, int entryTime, int exitTime){
	this->weight = weight;
	this->destinationFloor = destinationFloor;
	this->originalFloor = originalFloor;
	this->time = time;
	this->entryTime = entryTime;
	this->exitTime = exitTime;
	this->direction = this->destinationFloor - this->originalFloor ;
}

float Passenger::waitingTime(){
	float waiting = float(clock() - time);
	return waiting;
}

