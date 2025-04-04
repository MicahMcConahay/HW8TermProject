#pragma once
#include <string>
#include <vector>
using namespace std;

class Gate;

class Wire {
public:
	Wire();
	void setValue();
	void setDrives();
	void setHistory();
	int getValue();
	int getDrives();
	int getIndex();
private:
	int iValue;
	char cValue;
	enum eValue;
	string sName;
	char cName;
	vector<Gate*> drives;
	int index;
};
