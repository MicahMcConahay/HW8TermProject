#pragma once
#include <string>
using namespace std;

class Wire;

class Gate {
	string type;
	int delay;
	string extra;

	Gate(string, int, Wire*, Wire*, Wire*);
	int getDelay() const;
	Wire* getInput() const;
	Wire* getOutput() const;
	int evaluate(Wire* in1,Wire* in2,Wire* out) const;

private:
	Wire* in1, * in2;
	Wire* out;
};