#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DBentry.h"
#include "DBentry.cpp"
#include "TreeNode.h"
#include "TreeNode.cpp"
#include "TreeDB.h"
#include "TreeDB.cpp"

using namespace std;


int main() {
	
	TreeDB* head = new TreeDB();
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
			// parse an insert command
			string _name;
	        string __active;
			unsigned int _IPaddress;
	        bool _active;
	        Sline >> _name;
	        Sline >> _IPaddress;
	        Sline >> __active;
	        _active = __active == "active" ? true : false;
	        DBentry *tempDB = new DBentry(_name, _IPaddress, _active);
	        if (head->insert(tempDB))
	        {
	        	ofile << "Success" << endl;
	        }
	        else
	        {
	        	ofile << "Error: entry already exists" << endl;
	        }
		}
		else if (command == "find") {
			//find the DBentry
			string _name;
			Sline >> _name;
			DBentry *tempDB = head->find(_name); 
			if (tempDB == NULL)
			{
				ofile << "Error: entry does not exist" << endl;
			}
			else {
				ofile << *(tempDB->getEntry()) << endl;
			}
		}
		ofile << "> ";
		getline (ifile, line);
		ofile << line <<endl;
	} // End input loop until EOF.
	ifile.close();
	ofile.close();
	return 0;
}
