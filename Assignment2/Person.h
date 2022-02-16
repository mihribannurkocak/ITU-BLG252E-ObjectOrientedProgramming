#pragma once
#include <string>
/*
* Mihriban Nur Kocak
* 150180090
*/
using namespace std;

class Person {
	string name;
	string surname;
public:
	Person(string name_given = "unkown", string surname_given = "unkown"):name(name_given),surname(surname_given) {}//constructor

	//getter and setters
	string getName() const {
		return name;
	}
	string getSurname() const {
		return surname;
	}
	void setName(string name_given) {
		name = name_given;
	}
	void setSurname(string surname_given) {
		surname = surname_given;
	}
};

class Passenger:public Person{
	//Passenger class is a subclass of the Person class.
	int cash;//cash cannot be negative, if given is negative set zero and show given error message
	bool ticket;//shows whether a passenger has a ticket
public:
	Passenger(string name_g = "unkown", string surname_g = "unkown", int cash_g = 0);//constructor
	bool buyTicket(int ticket_price);//buys a ticket if the Passenger has enough cash to pay the ticket price
	
	//getter and setters
	bool getTicket() const{
		return ticket;
	}
	void setTicket(bool to_set) {
		ticket = to_set;
	}
	int getCash() const{
		return cash;
	}
	void setCash(int cash_given); //should check
};

class PassengerNode{//I have to create this because a passenger can join different missions
	Passenger* data; //the part which holds the data (specific to a passenger)
	PassengerNode* next; // the part which holds the next (can differ according to mission)
public:
	PassengerNode() { //constructor
		data = NULL;
		next = NULL;
	}

	//getter and setters
	PassengerNode* getNext() {
		return next;
	}
	void setNext(PassengerNode* new_passenger) {
		next = new_passenger;
	}
	Passenger* getData() {
		return data;
	}
	void setData(Passenger* new_passenger) {
		data = new_passenger;
	}
};
class Astronaut:public Person{
	//Astronaut class is a subclass of the Person class.
	int numMissions;//shows number of successful flights that an astronaut completed
public:
	Astronaut(string name_given = "unkown", string surname_given = "unkown",int numMissions_given = 0);//constructor
	void completeMission() { numMissions++; }//increment the numMissions by 1

	//getter and setters
	int getNumMissions() const{
		return numMissions;
	}
	void setNumMissions(int numMissions_given); //should check
};

class AstronautNode{//I have to create this because an astronout can join different missions
	Astronaut* data;//the part which holds the data (specific to a astronout)
	AstronautNode* next;// the part which holds the next (can differ according to mission)
public:
	AstronautNode() {//constructor
		data = NULL;
		next = NULL;
	}

	//getter and setters
	AstronautNode* getNext() {
		return next;
	}
	void setNext(AstronautNode* new_astronaut) {
		next = new_astronaut;
	}
	Astronaut* getData() {
		return data;
	}
	void setData(Astronaut* new_astronaut) {
		data = new_astronaut;
	}
};