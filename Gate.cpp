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
int Gate::evaluate(Wire* in1, Wire* in2, Wire* out) const {
	
}