#pragma once
#include "Faction.h"
/*
* Mihriban Nur Kocak
* 150180090
*/
class Dwarves:public Faction{
//is a Faction class.It uses all the private attributes of the Faction class and does not have any other private attributes.
public:
	//the constructor behaves exactly like Faction class constructor.
	Dwarves(string, int, int, int, int);
	
	//a method to perform attack to enemy factions.
	void PerformAttack();

	//method to receive attack from an enemy faction
	void ReceiveAttack(int, string);

	//method to purchase weapons from the merchant
	int PurchaseWeapons(int);

	//method to purchase armors from the merchant
	int PurchaseArmors(int);

	//method to print Faction information
	void Print() const;
};