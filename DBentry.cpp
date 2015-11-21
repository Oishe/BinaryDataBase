#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DBentry.h"

using namespace std;

DBentry::DBentry (string _name, unsigned int _IPaddress, bool _active){
	name = _name;
	IPaddress = _IPaddress;
    active = _active;
}

void DBentry::setName(string _name){
	this->name = _name;
}

void DBentry::setIPaddress(unsigned int _IPaddress){
	this->IPaddress = _IPaddress;
}

void DBentry::setActive (bool _active){
	this->active = _active;	
}

string DBentry::getName() const{
	return this->name;
}
unsigned int DBentry::getIPaddress() const{
	return this->IPaddress;
}

bool DBentry::getActive() const{
	return this->active; 
}

DBentry::~DBentry(){
}

// prints the entry in the format 
// name : IPaddress : active  followed by newline	
// active is printed as a string (active or inactive)
ofstream& operator<< (ofstream& out, const DBentry& rhs){
	out << rhs.getName() << " : ";
	out << rhs.getIPaddress() << " : ";
	out <<(rhs.getActive()? "active":"inactive");
	return out;
}