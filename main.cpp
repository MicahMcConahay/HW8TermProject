#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void parseInput(string input){
	//parse the string for every space -> split the strings as said below:
	// find the line header (input, output, or gate type)

	// for input or output, find name. For gate, find delay

	//gate in1

	//gate in2 or out1

	//gate out1
}

void parseVector(string input) {
	//parse the vector file for every space -> split the remaining strings below:
	//find the header -> only input...?

	// find the input name

	//find the input time

	//find the input value
}


int main() {
	vector <int> wires;

	ifstream inFS;
	string text;
	string filename = "";
	cin >> filename;

	int filenamelength = filename.size();
	filename = filename + ".txt";
	inFS.open(filename);
	if (!inFS.is_open()) {
		cout << "Error opening file!" << '/n';
	}

	while (!inFS.eof()) {
		getline(inFS, text);
		parseInput(text);
	}
	filename.insert(filenamelength, "_v");
		inFS.open(filename);
	return 0;
}
