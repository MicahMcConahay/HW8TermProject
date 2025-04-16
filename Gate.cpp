#include "Gate.h"
#include "Wire.h"

Gate::Gate(string typ, int d, Wire* input1, Wire* input2, Wire* output) {
	type = typ;
	delay = d;
	in1 = input1;
	in2 = input2;
	out = output;
}
Gate::Gate(string typ, int d, Wire* input1, Wire* output) {
	type = typ;
	delay = d;
	in1 = input1;
	out = output;
}

int Gate::getDelay() const {
	return delay;
}
Wire* Gate::getInput() const {
	return in1;
}
Wire* Gate::getSecondInput() const {
	return in2;
}
Wire* Gate::getOutput() const {
	return out;
}
int Gate::evaluate() const {
	int a = in1->getValue();
	int b = in2->getValue();
	//I don't know why this throws an error, it should work...

	if (type == "NOT") {
		if (a == 1) {
			return 0;
		}
		else if (a == 0) {
			return 1;
		}
		return -1;
	}
	else if (type == "AND") {
		if (a == 1 && b == 1) {
			return 1;
		}
		else if (a == 0 || b == 0) {
			return 0;
		}
		return -1;
	}
	else if (type == "OR") {
		if (a == 1 || b == 1) {
			return 1;
		}
		else if (a == -1 || b == -1) {
			return -1;
		}
		return 0;
	}
	else if (type == "XOR") {
		if (a == 1 && b == 0 || a == 0 && b == 1) {
			return 1;
		}
		else if (a == b) {
			return 0;
		}
		return -1;
	}
	else if (type == "NAND") {
		if (a == 1 && b == 1) {
			return 0;
		}
		else if (a == 0 || b == 0) {
			return 1;
		}
		return -1;
	}
	else if (type == "NOR") {
		if (a == 0 && b == 0) {
			return 1;
		}
		else if (a == 1 || b == 1) {
			return 0;
		}
		return -1;
	}
	else if (type == "XNOR") {
		if (a == 1 && b == 1 || a == 0 && b == 0) {
			return 1;
		}
		else if (a == 1 && b == 0 || a == 0 && b == 1) {
			return 0;
		}
		return -1;
	}
	return 1;
}
