#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DBentry.h"
#include "DBentry.cpp"

using namespace std;


int main() {
	
	//DBentry newDB;
	string line, command;
	ifstream ifile("input.txt");
	ofstream ofile("output.txt");
	ofile << "> ";
	getline (ifile, line); // Get a line from standard input
	ofile << line << endl;
	while ( !ifile.eof() ) {
		// Put the line in a stringstream for parsing
		// Making a new stringstream for each line so flags etc. are in a known state
		
		stringstream Sline (line);
		Sline >> command;
			

		//ofile << line <<endl;
		
		if (command == "insert") {
			
			// parse an insertR command
			string _name;
	        string __active;
			unsigned int _IPaddress;
	        bool _active;
	        Sline >> _name;
	        Sline >> _IPaddress;
	        Sline >> __active;
	        _active = __active == "active" ? true : false;
	        DBentry newDB (_name, _IPaddress, _active);
	        ofile << newDB;


		}
		
		//else if ( ... ) {
		//...
		//}
		ofile << "> ";
		getline (ifile, line);
		ofile << line << endl;
	} // End input loop until EOF.
	ifile.close();
	ofile.close();
	return 0;
}