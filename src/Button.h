#ifndef Button_H
#define Button_H
#include <string>
#include <vector>
using namespace std;

class Button {
public:
	Button(string buttonName, bool butState);
	bool isPressed(string buttonName);
	string getButtonName();
	bool butState;
	string buttonName;
};
#endif
