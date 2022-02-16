#include "Person.h"
#include <iostream>
/*
* Mihriban Nur Kocak
* 150180090
*/
using namespace std;
Passenger::Passenger(string name_given, string surname_given, int cash_given):Person(name_given, surname_given){
	//constructor
	//cash cannot be negative, if given is negative set zero and show given error message
	//"Passenger cash can’t be negative. It is set to 0."
	cash = 0;
	if (cash_given < 0) {
		cash = 0;
		cerr << "Passenger cash can’t be negative. It is set to 0." << endl;
	}
	else cash = cash_given;
	ticket = false;
}

void Passenger::setCash(int cash_given) {
	//cash cannot be negative, if given is negative set zero and show given error message
	//"Passenger cash can’t be negative. It is set to 0."
	if (cash_given < 0) {
		cash = 0;
		cerr << "Passenger cash can’t be negative. It is set to 0." << endl;
	}
	else cash = cash_given;
}

bool Passenger::buyTicket(int ticket_price){
//buys a ticket if the Passenger has enough cash to pay the ticket price
//return whether the person bought the ticket or not as a boolean
	if (cash >= ticket_price) {
		//bought ticket
		cash = cash - ticket_price;
		ticket = true;
		return true;
	}
	else {
		ticket = false;
		return false;
	}
}

Astronaut::Astronaut(string name_given, string surname_given,int numMissions_given):Person(name_given,surname_given){
	//constructor
	numMissions = numMissions_given;
	if (numMissions < 0) {
		numMissions = 0;
		cerr << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
	}
	else numMissions = numMissions_given;
}

void Astronaut::setNumMissions(int numMissions_given) {
	if (numMissions < 0) {
		numMissions = 0;
		cerr << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
	}
	else numMissions = numMissions_given;
}