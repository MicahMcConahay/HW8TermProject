#pragma once
#include <string>
#include <vector>
using namespace std;

class Gate;

class Wire {
public:
	Wire();
	void setValue(int x);
	void setValue(char x);
	void setDrives(Gate* g);
	void setHistory(string x);
	int getValue();
	vector<Gate*> getDrives();
	int getIndex();
	enum ValueType { LOW = 0, HIGH = 1, UNDEFINED = -1 };
private:
	int iValue;
	char cValue;
	string stringName;
	char charName;
	vector<Gate*> drives;
	int index;
	string history = "";
};
