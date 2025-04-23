#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Gate.h"
#include "Wire.h"

using namespace std;

/*
string smallParse(string& input) {
	int pos;
	string output;
	pos = input.find(' ');
	output = input.substr(0, pos);
	input.erase(0, pos+1);
	return output;
}
void parseInput(string input) {
	vector <string> first;
	string temp = "";

	//parse the string for every space -> split the strings as said below:
	// find the line header (input, output, or gate type)
	for() {
		temp = smallParse(input);
		if (temp != " " || temp != "") {
			first.push_back(temp);
			cout << temp;
		}
	}
}

void parseVector(string input) {
	//parse the vector file for every space -> split the remaining strings below:
	//find the header -> only input...?

	// find the input name

	//find the input time

	//find the input value
}
*/

int main() {
	vector <Wire*> wires;
	vector <Gate*> gates;

	ifstream inFS;
	string text;
	string filename = "";
	cin >> filename;

	string keyword, wireName, dummy;
	int    wireIndex, in1, in2, output, gateDelay, wireTime, wireValue;

	int filenamelength = filename.size();
	filename = filename + ".txt";
	inFS.open(filename);
	if (!inFS.is_open()) {
		cout << "Error opening file!" << '\n';
		return 0;
	}

	inFS >> keyword;

	while (!inFS.eof()) {
		if (keyword == "CIRCUIT") {
			inFS >> dummy;
		}
		else if (keyword == "INPUT" || keyword == "OUTPUT") {
			inFS >> wireName >> wireIndex;
			// now create the wire using ctor
			// stick the wire in w
			Wire* n = new Wire;
			n->setName(wireName);
			while (wires.size() < wireIndex+1) {
				wires.push_back(nullptr);
			}
			wires[wireIndex] = n;
			

		}
		else if (keyword == "NOT") {
			inFS >> gateDelay >> dummy >> in1 >> output;
			// check to make sure in1 and output exist, if not create them with your ctor
			// then create the gate
			// stick the gate in g
			while (wires.size() < in1 + 1 || wires.size() < output + 1) {
				wires.push_back(nullptr);
			}
			if (wires[in1] == nullptr) {
				wires[in1] = new Wire;
			}
			if (wires[output] == nullptr) {
				wires[output] = new Wire;
			}
			Gate* g = new Gate(keyword,gateDelay,wires[in1],wires[output]);
			gates.push_back(g);
		}
		else {
			inFS >> gateDelay >> dummy >> in1 >> in2 >> output;
			//check to make sure in1, in2, and output exist, if not, create them with constructor
			//create gate
			//put gate in g
			while (wires.size() < in1 + 1 || wires.size() < in2 + 1
				   || wires.size() < output + 1) {
				wires.push_back(nullptr);
			}
			if (wires[in1] == nullptr) {
				wires[in1] = new Wire;
			}
			if (wires[in2] == nullptr) {
				wires[in2] = new Wire;
			}
			if (wires[output] == nullptr) {
				wires[output] = new Wire;
			}
			Gate* g = new Gate(keyword, gateDelay, wires[in1], wires[in2], wires[output]);
			gates.push_back(g);
		}

		inFS >> keyword;
	}
	//the following are tests to make sure everything inputs as it should:
	for (int i = 0; i < wires.size(); ++i) {
		if (wires[i] != nullptr) {
			cout << wires[i]->getName();
			if (wires[i]->getName() == "") {
				cout << "0";
				wires[i]->setName("0");
			}
		}
		else cout << "x";
	}
	cout << '\n';
	for (int i = 0; i < gates.size(); ++i) {
		cout << gates[i]->getType() << gates[i]->getDelay() << gates[i]->getInput()->getName();
		if (gates[i]->getType() != "NOT") {
			cout << gates[i]->getSecondInput()->getName();
		}
		cout << gates[i]->getOutput()->getName() << '\n';
	}
	inFS.close();
	filename.insert(filenamelength, "_v");
	inFS.open(filename);
	if (!inFS.is_open()) {
		cout << "Failed to open Vector file!";
	}
	inFS >> keyword;
	while (!inFS.eof()) {
		if (keyword == "VECTOR") {
			inFS >> dummy;
		}
		else {
			inFS >> wireName >> wireTime >> wireValue;
			//name, time, value
			//name should match with an input value
			//list by order of time
			// value should be either 1, 0, or X.
			// inturpret value as:    1, 0,    -1


		}
		inFS >> keyword;
	}
	
	inFS.close();
	return 0;
}
