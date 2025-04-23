#include "Wire.h"
using namespace std;
Wire::Wire() {

}
void Wire::setName(string n) {
	stringName = n;
}
void Wire::setName(char c) {
	charName = c;
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
void Wire::setDrives(Gate* g) {
	drives.push_back(g);
}
void Wire::setHistory(string x) {
	history += x;
}
string Wire::getName() {
	return stringName;
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
void Wire::printHistory() const {
	cout << history << endl;
}
