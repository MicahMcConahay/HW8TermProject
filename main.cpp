#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
		cout << "Error opening file!" << '\n';
		return 0;
	}
	
	while (!inFS.eof()) {
		getline(inFS, text);
		if (text[0] != 'C') {
			parseInput(text);
		}
	}
	//filename.insert(filenamelength, "_v");
	//inFS.open(filename);
	
	return 0;
}
