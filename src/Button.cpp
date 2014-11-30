#include "Button.h"
using namespace std;

Button::Button(string buttonName, bool butState) {
	this->buttonName = buttonName;
	this->butState = butState;
}
bool Button::isPressed(string buttonName) {
	if (butState == true)
		return true;
	else
		return false;
}
string Button::getButtonName(){
	return buttonName;
}

