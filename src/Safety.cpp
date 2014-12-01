#include "Safety.h"
using namespace std;

void Safety::stopLift(Lift l){
	l.setSpeed(0);
	l.setOnService(false);
	cout << "The lift is stopped because of an emergency situation!!!" << endl;
}



