#pragma once
#include <string>
using namespace std;

class Wire;

class Gate {
public:
	Gate(string typ, int d, Wire* input1, Wire* input2, Wire* output);
	Gate(string typ, int d, Wire* input1, Wire* output);
	string getType() const;
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
