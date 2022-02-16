#include "Elves.h"
#include <string>
#include <iostream>

using namespace std;
/*
* Mihriban Nur Kocak
* 150180090
*/
//the constructor only calls Faction constructor since it has no other attributes.
Elves::Elves(string name_g, int number_of_units_g, int attack_point_g, int health_point_g, int unit_regeneration_number_g) : Faction(name_g, number_of_units_g, attack_point_g, health_point_g, unit_regeneration_number_g) {}

void Elves::PerformAttack() {//a method to perform attack to enemy factions.
	if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()) {
		//If there is only one enemy faction left alive, attacks the enemy faction with all of the units with attack point.
		//only first enemy is alive
		if (firstEnemy->GetName() == "Dwarves") {
			//When attacking Dwarves, attack point is increased to 150 % 
			firstEnemy->ReceiveAttack(attackPoint * 150 / 100 * numOfUnits, "Elves");
		}
		else {
			firstEnemy->ReceiveAttack(attackPoint * numOfUnits, "Elves");
		}
	}
	else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		//If there is only one enemy faction left alive, attacks the enemy faction with all of the units with attack point.
		//only second enemy is alive
		if (secondEnemy->GetName() == "Dwarves") {
			//When attacking Dwarves, attack point is increased to 150 % 
			secondEnemy->ReceiveAttack(attackPoint * 150 / 100 * numOfUnits, "Elves");
		}
		else {
			secondEnemy->ReceiveAttack(attackPoint * numOfUnits, "Elves");
		}
	}
	else if (firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		//If both enemy factions are alive, attacks Orcs with 60 % of its units with attack point and attacks Dwarves with rest of the units with attack point.
		//both of them are alive
		if (firstEnemy->GetName() == "Orcs" && secondEnemy->GetName() == "Dwarves") {
			int sixty = numOfUnits * 60 / 100; //60% of units
			//first enemy is orcs
			firstEnemy->ReceiveAttack(attackPoint * sixty, "Elves");
			//When attacking Dwarves, attack point is increased to 150 % 
			secondEnemy->ReceiveAttack(attackPoint * 150 / 100 * (numOfUnits - sixty), "Elves");
		}
		else if (secondEnemy->GetName() == "Orcs" && firstEnemy->GetName() == "Dwarves") {
			int sixty = attackPoint * 60 / 100; //60% of units
			//second enemy is orcs
			secondEnemy->ReceiveAttack(attackPoint * sixty, "Elves");
			//When attacking Dwarves, attack point is increased to 150 % 
			firstEnemy->ReceiveAttack(attackPoint * 150 / 100 * (numOfUnits - sixty), "Elves");
		}
	}
}
void Elves::ReceiveAttack(int total_damage_received, string attacking_faction) {//method to receive attack from an enemy faction.
	if (attacking_faction == "Orcs") {
		//If attacking faction is Orcs, incoming attack point is increased to 125 % of its original value.
		total_damage_received = total_damage_received * 125 / 100;
	}
	else if (attacking_faction == "Dwarves") {
		//If attacking faction is Dwarves, incoming attack point is reduced to 75 % of its original value.
		total_damage_received = total_damage_received * 75 / 100;
	}
	//Reduces number of units by total damage received divided by health point.
	numOfUnits = numOfUnits - total_damage_received / healthPoint;
}

int Elves::PurchaseWeapons(int weapon) {
	//method to purchase weapons from the merchant.
	//Increases attack point by double of weapon points bought and returns 15 gold for each weapon point bought.
	attackPoint += weapon * 2;
	return weapon * 15;
}

int Elves::PurchaseArmors(int armor) {
	//method to purchase armors from the merchant.
	//Increases health point by quadruple of armor points bought and returns 5 gold for each armor point bought.
	healthPoint += armor * 4;
	return armor*5;
}

void Elves::Print() const{// method to print Faction information.
//Prints the motto of Elves : “You cannot reach our elegance.” in quotes then prints the information as same as the Faction class.
	cout << '"' << "You cannot reach our elegance." << '"' << endl;
	cout << "Faction Name:         " << name << endl;
	if (isAlive) cout << "Status:               " << "Alive" << endl;
	else cout << "Status:               " << "Defeated" << endl;
	cout << "Number of Units:      " << numOfUnits << endl;
	cout << "Attack Point:         " << attackPoint << endl;
	cout << "Health Point:         " << healthPoint << endl;
	cout << "Unit Regen Number:    " << unitRegen << endl;
	cout << "Total Faction Health: " << totalHealth << endl;
}