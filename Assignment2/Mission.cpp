#include "Mission.h"
#include <iostream>
#include <cstdlib>
/*
* Mihriban Nur Kocak
* 150180090
*/
Mission::Mission(const string name_given, int cost_given, int fault_given)
{
	//constructor
	/*Each mission has an "XX-YY" name where X is an uppercase letter and
	Y is a digit. If the mission name does not satisfy this condition, an error
	message should be printed and the default name ("AA-00") should be set as
	mission name.*/
	if (name_given.length() != 5 || name_given[2] != '-')
	{
		//directly non-accepting name
		cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl; //error message
		name = "AA-00";
	}
	else
	{
		if (name_given[0] <= 90 && name_given[0] >= 65 && name_given[1] <= 90 && name_given[1] >= 65 && name_given[3] <= 57 && name_given[3] >= 48 && name_given[4] <= 57 && name_given[4] >= 48)
		{
			//according to ASCII table
			name = name_given;
		}
		else
		{
			cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl; //error message
			name = "AA-00";
		}
	}
	numMissions++;
	missionNumber = numMissions;
	cost = cost_given;
	faultProbability = fault_given;
	completed = false;
	passengers = NULL;
	crew = NULL;
	numPasssengers = 0;
	numAstronouts = 0;
	next = NULL;
}
Mission::~Mission()
{ //deconstructor, should delete allocated memory
	if (crew != NULL)
	{
		AstronautNode *traverse1 = crew;
		while (traverse1->getNext() != NULL)
		{
			AstronautNode *buffer = traverse1;
			traverse1 = traverse1->getNext();
			delete buffer;
		}
		delete traverse1;
	}
	if (passengers != NULL)
	{
		PassengerNode *traverse2 = passengers;
		while (traverse2->getNext() != NULL)
		{
			PassengerNode *buffer = traverse2;
			traverse2 = traverse2->getNext();
			delete buffer;
		}
		delete traverse2;
	}
}

Mission::Mission(const Mission &to_copy)
{ //copy constructor, should allocate new memory
	name = to_copy.name;
	missionNumber = to_copy.missionNumber;
	cost = to_copy.cost;
	faultProbability = to_copy.faultProbability;
	completed = to_copy.completed;

	if (to_copy.crew != NULL)
	{
		crew = new AstronautNode;
		crew->setData(to_copy.crew->getData());
		AstronautNode *traverse_new = crew;
		AstronautNode *traverse_old = to_copy.crew->getNext();
		while (traverse_old != NULL)
		{
			AstronautNode *to_add = new AstronautNode;
			to_add->setData(traverse_old->getData());
			traverse_new->setNext(to_add);
			traverse_new = traverse_new->getNext();
			traverse_old = traverse_old->getNext();
		}
	}
	else
		crew = NULL;

	if (to_copy.passengers != NULL)
	{
		passengers = new PassengerNode;
		passengers->setData(to_copy.passengers->getData());
		PassengerNode *traverse_new = passengers;
		PassengerNode *traverse_old = to_copy.passengers->getNext();
		while (traverse_old != NULL)
		{
			PassengerNode *to_add = new PassengerNode;
			to_add->setData(traverse_old->getData());
			traverse_new->setNext(to_add);
			traverse_new = traverse_new->getNext();
			traverse_old = traverse_old->getNext();
		}
	}
	else
		passengers = NULL;
	next = NULL;
	numPasssengers = to_copy.numPasssengers;
	numAstronouts = to_copy.numAstronouts;
}

Mission *Mission::operator+=(Passenger *to_add)
{ //operator overloading
	/*for adding a Passenger to the mission passenger list.
	Passengers can be added only if they have a ticket. If they don�t have a ticket,
	error message should be shown.*/
	if (to_add->getTicket() == true)
	{
		PassengerNode *new_passenger = new PassengerNode;
		new_passenger->setData(to_add);
		if (passengers == NULL)
		{
			//there is not other passenger so add to begining
			passengers = new_passenger;
		}
		else
		{
			//add to end
			PassengerNode *traverse = passengers;
			while (traverse->getNext() != NULL)
			{
				traverse = traverse->getNext();
			}
			traverse->setNext(new_passenger);
		}
		numPasssengers++;
	}
	else
	{
		cerr << "Passenger " << to_add->getName() << " " << to_add->getSurname() << " does not have a valid ticket!" << endl;
	}
	return this;
}

Mission *Mission::operator+=(Astronaut *to_add)
{ //operator overloading
	/*for adding an Astronaut to the mission crew list.
	Astronauts are directly added to the crew list/array*/
	AstronautNode *new_astronout = new AstronautNode;
	new_astronout->setData(to_add);
	if (crew == NULL)
	{
		//there is not other passenger so add to begining
		crew = new_astronout;
	}
	else
	{
		//add to end
		AstronautNode *traverse = crew;
		while (traverse->getNext() != NULL)
		{
			traverse = traverse->getNext();
		}
		traverse->setNext(new_astronout);
	}
	numAstronouts++;
	return this;
}

bool Mission::executeMission()
{										   //invokes random number generator (std::rand)
										   /*if the number is bigger than fault probability then mission will be successful.
It will print whether mission is successful or not. If mission is successful it will
invoke completeMission method of each astronaut in the crew list/array. Then it will print
each astronaut name with number of completed missions.
Finally, it will set the completed attribute according to the result of the mission and return the result as a boolean.*/
	int random_probability = rand() % 101; //to generate numbers between 0 to 100, 100 included
	if (faultProbability == 0)
	{
		//mission is failed all time
		cout << "MISSION " << name << " FAILED!" << endl;
		cout << "Agency reschedules the mission." << endl;
		completed = false;
		return false;
	}
	else if (faultProbability == 100 || random_probability > faultProbability)
	{
		//mission is successful
		cout << "MISSION " << name << " SUCCESSFUL!" << endl;
		AstronautNode *traverse = crew;
		while (traverse != NULL)
		{
			traverse->getData()->completeMission();
			cout << "Astronaut " << traverse->getData()->getName() << " " << traverse->getData()->getSurname() << " successfully completed " << traverse->getData()->getNumMissions() << " missions." << endl;
			traverse = traverse->getNext();
		}
		completed = true;
		return true;
	}
	else
	{
		//mission is failed
		cout << "MISSION " << name << " FAILED!" << endl;
		cout << "Agency reschedules the mission." << endl;
		completed = false;
		return false;
	}
}

int Mission::calculateProfit(int ticket_price)
{
	/*It checks whether the mission is completed by checking the class attribute completed.
If the mission is successful, then the function multiplies the ticket price with the number of passengers on board.
Cost of the mission will be subtracted from the profit whether mission is successful or not.
After that the method returns net profit which can be a positive or negative integer value.*/
	int profit = 0;
	if (completed)
	{
		int total_price = ticket_price * numPasssengers;
		profit = total_price + profit;
	}
	profit = profit - cost;
	return profit;
}

void Mission::setName(string name_given)
{
	/*Each mission has an "XX-YY" name where X is an uppercase letter and
	Y is a digit. If the mission name does not satisfy this condition, an error
	message should be printed and the default name ("AA-00") should be set as
	mission name.*/
	if (name_given.length() != 5 || name_given[2] != '-')
	{
		//directly non-accepting name
		cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl; //error message
		name = "AA-00";
	}
	else
	{
		if (name_given[0] <= 90 && name_given[0] >= 65 && name_given[1] <= 90 && name_given[1] >= 65 && name_given[3] <= 57 && name_given[3] >= 48 && name_given[4] <= 57 && name_given[4] >= 48)
		{
			//according to ASCII table
			name = name_given;
		}
		else
		{
			cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl; //error message
			name = "AA-00";
		}
	}
}