#include "Agency.h"
#include <iostream>
/*
* Mihriban Nur Kocak
* 150180090
*/
using namespace std;
Agency::Agency(const string name_given, int cash_given, int ticketprice_given) {
	//constructor
	name = name_given;
	cash = cash_given;
	ticketPrice = 0;
	/*
	if (cash_given < 0) {
		//cash cannot be negative
		cash = 0;
		cerr << "Cash can't be negative. It is set to 0." << endl;
	}
	else {
		cash = cash_given;
	}*/

	//ticket price cannot be negative
	if (ticketprice_given < 0) {
		ticketPrice = 0;
		cerr << "Ticket price can't be negative. It is set to 0." << endl;
	}
	else {
		ticketPrice = ticketprice_given;
	}
	completedMissions = NULL; 
	nextMissions = NULL;
}

Agency::~Agency() {//deconstructor, should delete allocated memory
	if (nextMissions != NULL) {
		Mission* traverse1 = nextMissions;
		while (traverse1->getNext() != NULL) {
			Mission* buffer = traverse1;
			traverse1 = traverse1->getNext();
			delete buffer;
		}
		delete traverse1;
	}
	if (completedMissions != NULL) {
		Mission* traverse1 = completedMissions;
		while (traverse1->getNext() != NULL) {
			Mission* buffer = traverse1;
			traverse1 = traverse1->getNext();
			delete buffer;
		}
		delete traverse1;
	}
}

void Agency::setTicketPrice(int ticketprice_given) {
	//ticket price cannot be negative
	if (ticketprice_given < 0) {
		ticketPrice = 0;
		cerr << "Ticket price can't be negative. It is set to 0." << endl;
	}
	else {
		ticketPrice = ticketprice_given;
	}
}


void Agency::addMission(Mission& to_add) {
	/*this method takes a mission as an argument and adds 
	the mission to the agency’s nextMissions list*/
	Mission* new_mission = new Mission(to_add); //copy constuctor called
	if (nextMissions == NULL) {
		//add to begining
		nextMissions = new_mission;
	}
	else {
		//add to end
		Mission* traverse = nextMissions;
		while (traverse->getNext() != NULL) {
			traverse = traverse->getNext();
		}
		traverse->setNext(new_mission);
	}
}

void Agency::executeNextMission() {
	/*this method takes the next mission from the nextMissions list/array and executes the mission.
	If the mission is successful, it should be added to completedMissions list/array and the profit
	of the mission should be added to the agency cash. Otherwise, the mission should be moved to the end of the
	nextMissions list/array. Failed mission profit also should be added to the agency cash.*/
	//take mission from beginning of the linked list
	Mission* taken_mission = NULL;
	if (nextMissions == NULL) {
		//there is no next mission
		cerr << "No available mission to execute!" << endl;
	}
	else {
		if (nextMissions->getNext() == NULL) {
		//there is just one mission
		taken_mission = nextMissions;
		nextMissions = NULL;
		}
		else {
		//there are more than one mission
		Mission* buffer = nextMissions->getNext();
		taken_mission = nextMissions;
		nextMissions = buffer;
		}
		taken_mission->setNext(NULL);//get rid of old adresses

		//mission was taken
		bool successful = taken_mission->executeMission();
		if (successful) {
			//add to completedMissions list
			//the profit of the mission should be added to the agency cash
			if (completedMissions == NULL) {
				//add to begining
				completedMissions = taken_mission;
			}
			else {
				//add to end
				Mission* traverse = completedMissions;
				while (traverse->getNext() != NULL) {
					traverse = traverse->getNext();
				}
				traverse->setNext(taken_mission);
			}
		}
		else {
			//add to the end of the nextMissions list
			//Failed mission profit also should be added to the agency cash.
			if (nextMissions == NULL) {
				//there is no next mission
				nextMissions = taken_mission;
			}
			else {

				Mission* traverse = nextMissions;
				while (traverse->getNext() != NULL) {
					traverse = traverse->getNext();
				}
				traverse->setNext(taken_mission);
			}
		}
		cash = cash + taken_mission->calculateProfit(ticketPrice);
	}
}

ostream& operator<<(ostream& output, const Agency& agency_to_print){
/*put information about the Agency to the out stream. It should contain name,
current cash, ticket price, information (name, cost) of the nextMissions and
completedMissions. For every mission you should print mission number, mission
name and mission cost. For more information you can check out the given output.*/
	output << "Agency name: " << agency_to_print.name << ", Total cash: " << agency_to_print.cash << ", Ticket Price: " << agency_to_print.ticketPrice << endl;
	Mission* traverse_nextlist = agency_to_print.nextMissions;
	Mission* traverse_completedlist = agency_to_print.completedMissions;
	
	output << "Next Missions:" << endl;
	if (traverse_nextlist == NULL) {
		output << "No missions available." << endl;
	}
	else {
		while (traverse_nextlist != NULL) {
			output << "Mission number: " << traverse_nextlist->getMissionNumber()
				<< " Mission name: " << traverse_nextlist->getName()
				<< " Cost: " << traverse_nextlist->getCost() << endl;
			traverse_nextlist = traverse_nextlist->getNext();
		}
	}

	output << "Completed Missions:" << endl;
	if (traverse_completedlist == NULL) {
		output << "No missions completed before." << endl;
	}
	else {
		while (traverse_completedlist != NULL) {
			output << "Mission number: " << traverse_completedlist->getMissionNumber()
				<< " Mission name: " << traverse_completedlist->getName()
				<< " Cost: " << traverse_completedlist->getCost() << endl;
			traverse_completedlist = traverse_completedlist->getNext();
		}
	}
	return output;
}