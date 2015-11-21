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

void print (TreeNode* temp){
	if (temp == NULL)
	{return;}
	else if (temp->getLeft()!=NULL)
	{print(temp->getLeft());}
	else if (temp !=NULL)
	{
		cout << temp->getEntry()->getName();
		cout << " : ";
		cout << temp->getEntry()->getIPaddress();
		cout << " : ";
		if (temp->getEntry()->getActive())
		cout << "active";
		else
		cout <<"inactive";
		cout << "\n";
	}
	else
	{print(temp->getRight());}
}

int main() {
	
	TreeDB* head = new TreeDB();
	string line, command;
	ifstream ifile("input.txt");
	cout << "> ";
	getline (ifile, line); // Get a line from standard input
	cout << line << endl;
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
	        	cout << "Success" << endl;
	        }
	        else
	        {
	        	cout << "Error: entry already exists" << endl;
	        }
		}
		else if (command == "find") {
			//find the DBentry
			string _name;
			Sline >> _name;
			DBentry *tempDB = head->find(_name); 
			if (tempDB == NULL)
			{
				cout << "Error: entry does not exist" << endl;
			}
			else {
				cout << tempDB << endl;
			}
		}
		else if (command == "printall"){	
			print(head->getRoot());
		}
		cout<< "> ";
		getline (ifile, line);
		cout << line <<endl;
	} // End input loop until EOF.
	ifile.close();
	return 0;
}
