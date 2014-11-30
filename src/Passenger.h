#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passenger {

public:
	int weight;
	int destinationFloor;
	int originalFloor;
	time_t time;

public:
	//constructor
	Passenger(int weight, int destinationFloor, int originalFloor, float time);
	float waitingTime();
	string pressButton();
	vector<Passenger> start(bool flag);

};
#endif /* PASSENGER_H_ */
