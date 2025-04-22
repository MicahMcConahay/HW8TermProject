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
	int    wireIndex, in1, in2, output, gateDelay;

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
		else if (keyword == "INPUT") {
			inFS >> wireName >> wireIndex;
			// now create the wire using ctor
			// stick the wire in w
			Wire n;
			n.setName(wireName);

			

		}
		else if (keyword == "NOT") {
			inFS >> gateDelay >> dummy >> in1 >> output;
			// check to make sure in1 and output exist, if not create them with your ctor
			// then create the gate
			// stick the gate in g
		}
		else {
			inFS >> gateDelay >> dummy >> in1 >> in2 >> output;
			//check to make sure in1, in2, and output exist, if not, create them with constructor
			//create gate
			//put gate in g

		}

		inFS >> keyword;
	}
	//filename.insert(filenamelength, "_v");
	//inFS.open(filename);

	return 0;
}
