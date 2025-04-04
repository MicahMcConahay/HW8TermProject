#pragma once
#include <string>
using namespace std;

class Wire;

class Gate {
public:
	Gate(string, int, Wire*, Wire*, Wire*);
	int getDelay() const;
	Wire* getInput() const;
	Wire* getSecondInput() const;
	Wire* getOutput() const;
	int evaluate() const;

private:
	string type;
	int delay;
	string extra;
	Wire* in1, * in2;
	Wire* out;
};
