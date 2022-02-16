#pragma once
#include "Faction.h"
/*
* Mihriban Nur Kocak
* 150180090
*/
class Elves:public Faction{
//is a Faction class.It uses all the private attributes of the Faction classand does not have any other private attributes.
public:
	//the constructor behaves exactly like Faction class constructor.
	Elves(string, int, int, int, int);

	void PerformAttack();//a method to perform attack to enemy factions.
	/*
	When attacking Dwarves, attack point is increased to 150 % .
	If there is only one enemy faction left alive, attacks the enemy faction with all of the units with attack point.
	If both enemy factions are alive, attacks Orcs with 60 % of its units with attack point and attacks Dwarves with rest of the units with attack point.
	*/
	void ReceiveAttack(int total_damage_received, string attacking_faction);//method to receive attack from an enemy faction.Reduces number of units by total damage received divided by health point.
	/*
	If attacking faction is Orcs, incoming attack point is increased to 125 % of its original value.
	If attacking faction is Dwarves, incoming attack point is reduced to 75 % of its original value.
	*/
	int PurchaseWeapons(int weapon);//method to purchase weapons from the merchant.Increases attack point by double of weapon points boughtand returns 15 gold for each weapon point bought.
	int PurchaseArmors(int armor);//method to purchase armors from the merchant.Increases health point by quadruple of armor points boughtand returns 5 gold for each armor point bought.
	void Print() const;// method to print Faction information.Prints the motto of Elves : “You cannot reach our elegance.” in quotes then prints the information as same as the Faction class.
};