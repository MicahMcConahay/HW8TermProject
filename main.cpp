#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Gate.h"
#include "Wire.h"

using namespace std;

int main() {
	vector <Wire*> wires;
	vector <Gate*> gates;

	ifstream inFS;
	string text;
	string filename = "";
	cin >> filename;

	string keyword, wireName, dummy, circuitName;
	int    wireIndex, in1, in2, output, gateDelay, wireTime, wireValue;

	std::queue<pair<int, pair<string, int>>> vfile;

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
			inFS >> circuitName;
		}
		else if (keyword == "INPUT" || keyword == "OUTPUT") {
			inFS >> wireName >> wireIndex;
			// now create the wire using ctor
			// stick the wire in w
			Wire* n = new Wire;
			n->setName(wireName);
			while (wires.size() < wireIndex + 1) {
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
			Gate* g = new Gate(keyword, gateDelay, wires[in1], wires[output]);
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
			Gate* g = new Gate(keyword, gateDelay, wires[in1], wires[in2],
				wires[output]);
			gates.push_back(g);
		}

		inFS >> keyword;
	}
	//the following are tests to make sure everything inputs as it should:
	/*
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
	*/
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
			// inturpret value as:    1, 0,    -1 respectively
			vfile.push(make_pair(wireTime, make_pair(wireName, wireValue)));
			//sort this by vfile[x].first value

		}
		inFS >> keyword;
	}
	for (int i = 0; i < vfile.size(); ++i) {
		cout << vfile.front().first << vfile.front().second.first << vfile.front().second.second << '\n';
		vfile.pop();
	}

	inFS.close();
	filename.erase(filenamelength);

	//for any gate, once either in1 or in2 changes, evaluate() instantly to avoid missing a value
	//but only change the output after delay number of time iterations
	
	//as time goes on, use the wire's history to keep track of high, low, or x
	//only display this output after the final delay in the circuit has ended
	
	// start of display below:

	cout << '\n' << "Simulating " << filename << ".txt" << '\n' << '\n'
		<< '\n' << "Wire traces:";
	for (int i = 0; i < wires.size(); ++i) {
		if (wires[i] != nullptr) {
			if (wires[i]->getName() != "") {
				cout << '\n' << wires[i]->getName() << " | ";
				wires[i]->printHistory();
				cout << "  | ";
			}
		}
	}
	// display "_" the same number of times as time iterations
	// then display time over 2 lines - tens position on first line, ones position on second
	// put 4 dashes between each timestamp in tens line, and however many dashes needed to end simulation
	
	cout << "  0";
	int x = 0;
	for (int i = 0; i < (wires[1]->getHistory()).size() ;++i) {
		if (((i + 1) % 5) == 0) {
			cout << x;
			
		}
		else {
			cout << "_";
		}
	}
	cout << endl;
	cout << "  0";
	x = 0;
	for (int i = 0; i < (wires[1]->getHistory()).size()  ;++i) {
		if (((i + 1) % 5) == 0) {
			cout << x;
			if (x == 5) {
				x = 0;
			}
			else {
				x = 5;
			}
		}
		else {
			cout << " ";
		}
	}
	//end with
	cout << '\n' << "Circuit Name: " << circuitName << '\n';
	cout << "Time elapsed: " <</* number of time iterations */"ns" << '\n';

	return 0;
}
