#include "Gate.h"

int Gate::getDelay() const {
	return delay;
}
Wire* Gate::getInput() const {
	return in1,in2;
}
Wire* Gate::getOutput() const {
	return out;
}
int Gate::evaluate() const {
	if (type == "NOT") {
	
	}
	else if (type == "AND") {
	
	}
	else if (type == "OR") {
	
	}
	else if (type == "XOR") {
	
	}
	else if (type == "NAND") {
	
	}
	else if (type == "NOR") {
	
	}
	else if (type == "XNOR") {
	
	}
	return 1;
}
