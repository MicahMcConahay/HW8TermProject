#include "Wire.h"
Wire::Wire() {
	
}
void Wire::setValue(int x) {
	if (x == LOW || x == HIGH || x == UNDEFINED) {
		iValue = x;
	}
	else { iValue = UNDEFINED; }
}
void Wire::setValue(char x) {
	if (x == '0' || x == '1') {
		iValue = x - '0';
	}
	else {
		iValue = UNDEFINED;
	}
	cValue = x;
}
void Wire::setDrives() {
//todo: implement
}
void Wire::setHistory() {
//todo: implement
}
int Wire::getValue() {
	return iValue;
}
vector<Gate*> Wire::getDrives() {
	return drives;
}
int Wire::getIndex() {
	return index;
}
