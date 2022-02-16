#pragma once
#include <string>
#include "Mission.h"
/*
* Mihriban Nur Kocak
* 150180090
*/
using namespace std;
class Agency {
	string name;
	int cash;
	int ticketPrice;
	Mission* completedMissions; //head of linked list which contains completed missions 
	Mission* nextMissions; //head of linked list which contains next missions
public:
	Agency(const string name_given = "unkown", int cash_given = 0, int ticketprice_given = 0);//constructor
	~Agency();//destructor
	void addMission(Mission& to_add);
	void executeNextMission();
	/*this method takes the next mission from the nextMissions list/array and executes the mission. 
	If the mission is successful, it should be added to completedMissions list/array and the profit
	of the mission should be added to the agency cash. Otherwise, the mission should be moved to the end of the 
	nextMissions list/array. Failed mission profit also should be added to the agency cash.*/
	friend ostream& operator<<(ostream&, const Agency&);
	/*put information about the Agency to the out stream. It should contain name, 
	current cash, ticket price, information (name, cost) of the nextMissions and 
	completedMissions. For every mission you should print mission number, mission
	name and mission cost. For more information you can check out the given output.*/

	//getters and setters
	int getTicketPrice() const {
		return ticketPrice;
	}
	void setTicketPrice(int price_given);// should check

	int getCash() const {
		return cash;
	}
	void setCash(int cash_given) {
		cash = cash_given;
	}
	Mission* getCompletedMissions() {
		return completedMissions;
	}
	Mission* getNextMissions() {
		return nextMissions;
	}
};
