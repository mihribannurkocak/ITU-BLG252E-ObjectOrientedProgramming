#include "Orcs.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
/*
* Mihriban Nur Kocak
* 150180090
*/

//the constructor only calls Faction constructor since it has no other attributes.
Orcs::Orcs(string name_g, int number_of_units_g, int attack_point_g, int health_point_g, int unit_regeneration_number_g) : Faction(name_g, number_of_units_g, attack_point_g, health_point_g, unit_regeneration_number_g) {}

void Orcs::PerformAttack() {
	if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()) {
		//If there is only one enemy faction left alive, attacks the enemy faction with all of the units with attack point.
		//only firstEnemy is alive
		firstEnemy->ReceiveAttack(attackPoint * numOfUnits,"Orcs");
	}
	else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		//If there is only one enemy faction left alive, attacks the enemy faction with all of the units with attack point.
		//only secondEnemy is alive
		secondEnemy->ReceiveAttack(attackPoint * numOfUnits,"Orcs");
	}
	else if (firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		//If both enemy factions are alive, attacks Elves with 70 % of its units with attack point and attacks Dwarves with rest of the units with attack point.
		//both of them are alive
		if (firstEnemy->GetName() == "Elves" && secondEnemy->GetName() == "Dwarves") {
			//first enemy is elves
			int seventy = numOfUnits * 70 / 100; //70% of units
			firstEnemy->ReceiveAttack(attackPoint * seventy, "Orcs");
			secondEnemy->ReceiveAttack(attackPoint * (numOfUnits- seventy), "Orcs");
		}
		else if (secondEnemy->GetName() == "Elves" && firstEnemy->GetName() == "Dwarves") {
			//second enemy is elves
			int seventy = numOfUnits * 70 / 100;//70% of units
			secondEnemy->ReceiveAttack(attackPoint * seventy, "Orcs");
			firstEnemy->ReceiveAttack(attackPoint *(numOfUnits - seventy), "Orcs");
		}
	}
}

void Orcs::ReceiveAttack(int total_damage_received, string attacking_faction) {//method to receive attack from an enemy faction
	//Reduces number of units by total damage received divided by health point.
/*
If attacking faction is Elves, incoming attack point is reduced to 75 % of its original value.
If attacking faction is Dwarves, incoming attack point is reduced to 80 % of its original value.
*/
	if (attacking_faction == "Elves") {
		//attacking faction is elves
		total_damage_received = total_damage_received * 75 / 100;
	}
	else if (attacking_faction == "Dwarves") {
		//attacking faction is dwarves
		total_damage_received = total_damage_received * 80 / 100;
	}
	numOfUnits = numOfUnits - total_damage_received / healthPoint;
}

int Orcs::PurchaseWeapons(int weapon) {//method to purchase weapons from the merchant
//Increases attack point by double of weapon points bought and returns 20 gold for each weapon point bought.
	attackPoint += weapon * 2;
	return weapon * 20;
}

int Orcs::PurchaseArmors(int armor) {//method to purchase armors from the merchant
//Increases health point by triple of armor points bought and returns 1 gold for each armor point bought.
	healthPoint += armor * 3;
	return armor;
}

void Orcs::Print() const {//method to print Faction information
//Prints the battle cry of Orcs : “Stop running, you’ll only die tired!” in quotes then prints the information as same as the Faction class.
	cout << '"'<< "Stop running, you'll only die tired!" << '"' << endl;
	cout << "Faction Name:         " << name << endl;
	if (isAlive) cout << "Status:               " << "Alive" << endl;
	else cout << "Status:               " << "Defeated" << endl;
	cout << "Number of Units:      " << numOfUnits << endl;
	cout << "Attack Point:         " << attackPoint << endl;
	cout << "Health Point:         " << healthPoint << endl;
	cout << "Unit Regen Number:    " << unitRegen << endl;
	cout << "Total Faction Health: " << totalHealth << endl;
}