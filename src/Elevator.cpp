#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "tinyxml.h"
#include "Lift.h"
#include <sstream>
#include "Floor.h"
#include "Controller.h"
#include <boost/random.hpp>
#include <time.h>
#include "Passenger.h"
//add all the above includes into the controller
#include <conio.h>
#include <windows.h>

using namespace std;

bool readConfig(char *configfilePath);
double GetRandomDoubleUsingNormalDistribution(double mean, double sigma);
int main() {
	vector<Passenger> passengers;

	//this just shows usage of the readConfig file
	if (!readConfig("sample.xml")) {
		cout << ("There was a problem reading the file\n");
	}
	double gen;
	int iteration;
	int passengers_count = 0;
	int from, to;
	for (int i = 0; i < 50; i++) {
		gen = GetRandomDoubleUsingNormalDistribution(7, 1.5);
		iteration = round(gen);
		for (int j = 0; j < iteration; j++) {
			from = rand() % 10;
			to = rand() % 10;
			while (from == to) {
				to = rand() % 10;
			}
			Passenger p((rand() % 95 + 5), from, to, time(NULL), 1, 1);
			passengers.push_back(p);
			passengers_count++;
		}
		Sleep(500);
		/*cout << gen << endl;
		cout << iteration << endl;*/
	}
	for (int i = 0; i < passengers_count; i++) {
		cout << "Passengers - " << i << " :- weight: " << passengers[i].weight
				<< " , from: " << passengers[i].originalFloor << " , to: "
				<< passengers[i].destinationFloor
				<< " , clock: " << passengers[i].time << endl;
	}

	return 0;
}

double GetRandomDoubleUsingNormalDistribution(double mean, double sigma) {
	typedef boost::normal_distribution<double> NormalDistribution;
	typedef boost::mt19937 RandomGenerator;
	typedef boost::variate_generator<RandomGenerator&, NormalDistribution> GaussianGenerator;

	/** Initiate Random Number generator with current time */
	static RandomGenerator rng(static_cast<unsigned>(time(0)));

	/* Choose Normal Distribution */
	NormalDistribution gaussian_dist(mean, sigma);

	/* Create a Gaussian Random Number generator
	 *  by binding with previously defined
	 *  normal distribution object
	 */
	GaussianGenerator generator(rng, gaussian_dist);
	return generator();

}
bool readConfig(char *configfilePath) {

	const char *readVal = ""; //used to read values -- do not delete or rename
	int lift_count = 0; //used with vector to place new lifts

//list of variables to retrieve from  the config file.
//they can be modified to attach directly to controller vars

	int lifts_time_to_next_floor = 0;
	int lifts_max_weight = 0;
	int floors = 0;
	int doors_time_to_open = 0;
	int doors_time_to_close = 0;
	int passenger_lift_entry_time = 0;
	int passenger_lift_exit_time = 0;
	vector<Lift> lifts;
	vector<Floor> floorsVector;

//end of vars

	TiXmlDocument configFile(configfilePath);
	bool wasLoaded = configFile.LoadFile();
	if (wasLoaded) {
		//log entry for loading config file successfully --here
		TiXmlElement *root, *param, *param2;
		//fetch root element
		root = configFile.FirstChildElement("config");
		//if root element gotten (i.e "<config>")
		if (root) {

			//try to load the floors detail now
			param = root->FirstChildElement("floors");
			if (param) {	//if floor tag was found in the xml file
				readVal = param->Attribute("number");
				floors = atoi(readVal);
			} else {
				//log invalid config -- floors missing. --exit app
				return false;
			}

			//try to load the doors detail now
			param = root->FirstChildElement("doors");
			if (param) {
				readVal = param->Attribute("time-to-open");
				doors_time_to_open = atoi(readVal);
				readVal = param->Attribute("time-to-close");
				doors_time_to_close = atoi(readVal);
				//cout << doors_time_to_open << " --- " << doors_time_to_close;
			} else {
				//log invalid config file -- doors missing
				return false;
			}

			//try to load the passengers detail now
			param = root->FirstChildElement("passengers");
			if (param) {
				readVal = param->Attribute("lift-entry-time");
				passenger_lift_entry_time = atoi(readVal);
				readVal = param->Attribute("lift-exit-time");
				passenger_lift_exit_time = atoi(readVal);
			} else {
				//log invalid config file -- passengers missing
				return false;
			}

			//try to get lifts details now. remember we first handle lifts then each lift
			param = root->FirstChildElement("lifts");
			if (param) {
				readVal = param->Attribute("time-to-next-floor");
				lifts_time_to_next_floor = atoi(readVal);
				readVal = param->Attribute("max-weight");
				lifts_max_weight = atoi(readVal);

				//searching for the lifts. A while loop would be used so we can iterate well.
				//if the iteration ends, we will test the lifts vector's size to ensure we had at least one
				//lift specified. If we did we proceed else we exit with an error and log entry as the system ca nt start
				//with no elevators present.

				param2 = param->FirstChildElement("lift");

				while (param2) {
					int lift_start = 0;
					int lift_stop = 0;

					readVal = param2->Attribute("start");
					lift_start = atoi(readVal);
					readVal = param2->Attribute("stop");
					lift_stop = atoi(readVal);

					if (lift_start == lift_stop) {
						//log invalid liftentry
						//dont return false so we can move to next record
					} else {
						Lift l(lift_count, lift_start, lift_stop,
								lifts_max_weight, lifts_time_to_next_floor,
								doors_time_to_open, doors_time_to_close);
						lifts.push_back(l);
						lift_count++;
					}
					param2 = param2->NextSiblingElement("lift");

				}

				//final check to ensure we have a lift
				if (lift_count == 0) {
					//log error in config file - no lifts supplied
					return false;
				}

				/* create the floors objects */
				string floorName;
				stringstream out;
				for (int j = 0; j < floors; j++) {
					out << j;
					floorName.append("floor");
					floorName.append(out.str());
					Floor f(floorName, j, doors_time_to_open,
							doors_time_to_close);
					floorsVector.push_back(f);
					floorName.clear();
					out.str("");
				}

				/* create the controller object*/
				Controller controller(lifts, floorsVector);

				//if we reach here, it means all was well.

				/*********** REMOVE PLEASE - FOR VERIFICATION ONLY ************/
				cout << "XML FILE DATA" << endl;
				cout << "Passengers:- entry time: " << passenger_lift_entry_time
						<< " , exit time: " << passenger_lift_exit_time << endl;
				cout << "Doors:- open time: " << doors_time_to_open
						<< " close time: " << doors_time_to_close << endl;
				cout << "Number of floors: " << floors << endl;
				cout << "Lifts (general): max-weight: " << lifts_max_weight
						<< " time-to-next-floor: " << lifts_time_to_next_floor
						<< endl;
				cout << "All lifts:" << endl;
				for (int i = 0; i < lift_count; i++) {
					cout << "Lift - " << i << " :- start: "
							<< lifts[i].startFloor << " , stop: "
							<< lifts[i].stopFloor << endl;
				}
				cout << "All floors:" << endl;
				for (int i = 0; i < floors; i++) {
					cout << "Floors - " << i << " :- name: "
							<< floorsVector[i].nameFloor << " , number: "
							<< floorsVector[i].numFloor << endl;
				}
				cout << "************** END *******************";
				/***** END OF VERIFICATION BLOCK ***************/

			} else {
				//log invalid config file -- lifts missing
				return false;
			}

		} else { //if root not gotten it means this is the wrong config file.
				 //log invalid config file -- xml root must be "config" -- exit program
			return false;
		}

		return true;
	} else {
		//log entry for failed load of config file --here
		return false;
	}
}

