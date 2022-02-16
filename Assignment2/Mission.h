#pragma once
#include <string>
#include "Person.h"
/*
* Mihriban Nur Kocak
* 150180090
*/
using namespace std;
class Mission {
	string name;
	int missionNumber;
	int cost;
	int faultProbability; // between 0-100 if 100, fail every launch
	bool completed; //All successful missions are considered as completed, rescheduled and not executed missions are considered as not completed
	PassengerNode* passengers; //head of the passenger list of a mission
	AstronautNode* crew; //head of the astronout list pf a mission
	static int numMissions; //is initialized once and it is initialized to 0
	/*This static variable should be increased by 1 at each mission object creation. After
	increasing the variable result should be assigned to missionNumber variable.For example first
	mission should increase the static variable from 0 to 1 and assign the 1 to itself.*/
	int numPasssengers; // I added to avoid traversing whole list every time 
	int numAstronouts; // I added to avoid traversing whole list every time
	Mission* next; //next of each mission in mission list
public:
	Mission(const string name_given = "unkown", int cost_given = 0, int fault_given = 0);//constructor
	Mission(const Mission& to_copy);//copy constructor
	~Mission();//destructor

	/*Passengers can be added only if they have a ticket. If they don’t have a ticket,
	error message should be shown. Astronauts are directly added to the crew list/array*/
	Mission* operator+=(Passenger* to_add);//for adding a Passenger to the mission passenger list.
	Mission* operator+=(Astronaut* to_add);//for adding a Astronout to the mission crew list.

	bool executeMission(); //invokes random number generator (std::rand)
	/*if the number is bigger than fault probability then mission will be successful.
	It will print whether mission is successful or not. If mission is successful it will
	invoke completeMission method of each astronaut in the crew list/array. Then it will print 
	each astronaut name with number of completed missions. Finally, it will set the completed
	attribute according to the result of the mission and return the result as a boolean.*/

	int calculateProfit(int ticket_price);
	/*It checks whether the mission is completed by checking the class attribute completed. 
	If the mission is successful, then the function multiplies the ticket price with the number of passengers on board. 
	Cost of the mission will be subtracted from the profit whether mission is successful or not. 
	After that the method returns net profit which can be a positive or negative integer value.*/

	//getter and setters
	string getName() const{
		return name;
	}
	void setName(string name_given); //should check the rules
	int getMissionNumber() const{
		return missionNumber;
	}
	void setMissionNumber(int given){
		missionNumber = given;
	}
	int getCost() const{
		return cost;
	}
	void setCost(int given) {
		cost = given;
	}
	int getFaultProbability() const{
		return faultProbability;
	}
	void setFaultProbability(int given) {
		faultProbability = given;
	}
	bool getCompleted() const{
		return completed;
	}
	void setCompleted(bool given) {
		completed = given;
	}
	int getNumPassengers() const{
		return numPasssengers;
	}
	void setNumPassengers(int given) {
		numPasssengers = given;
	}
	int getNumAstronouts() const{
		return numAstronouts;
	}
	void setNumAstronouts(int given) {
		numAstronouts = given;
	}
	Mission* getNext() const{
		return next;
	}
	void setNext(Mission* mission_given) {
		next = mission_given;
	}
	AstronautNode* getCrew() {
		return crew;
	}
	PassengerNode* getPassengers() {
		return passengers;
	}
};
