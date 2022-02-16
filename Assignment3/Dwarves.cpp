#include "Dwarves.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
/*
* Mihriban Nur Kocak
* 150180090
*/

//the constructor only calls Faction constructor since it has no other attributes.
Dwarves::Dwarves(string name_g, int number_of_units_g, int attack_point_g, int health_point_g, int unit_regeneration_number_g) : Faction(name_g, number_of_units_g, attack_point_g, health_point_g, unit_regeneration_number_g) {}

void Dwarves::PerformAttack() {//a method to perform attack to enemy factions.
	if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()) {
		//If there is only one enemy faction left alive, attacks the enemy faction with all of the units with attack point.
		//only first enemy is alive
		firstEnemy->ReceiveAttack(attackPoint * numOfUnits, "Dwarves");
	}
	else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		//If there is only one enemy faction left alive, attacks the enemy faction with all of the units with attack point.
		//only second enemy is alive
		secondEnemy->ReceiveAttack(attackPoint * numOfUnits, "Dwarves");
	}
	else if (firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		//If both enemy factions are alive, attacks each enemy faction with half of its units with attack point.
		//both of them are alive
		firstEnemy->ReceiveAttack(attackPoint * (numOfUnits /2), "Dwarves");
		secondEnemy->ReceiveAttack(attackPoint * (numOfUnits / 2), "Dwarves");
	}
}

void Dwarves::ReceiveAttack(int total_damage_received, string attacking_faction) {//method to receive attack from an enemy faction
//Reduces number of units by total damage received divided by health point.
	numOfUnits = numOfUnits - total_damage_received / healthPoint;
}

int Dwarves::PurchaseWeapons(int weapon) {//method to purchase weapons from the merchant
//Increases attack point by weapon points bought and returns 10 gold for each weapon point bought.
	attackPoint += weapon;
	return weapon * 10;
}

int Dwarves::PurchaseArmors(int armor) {//method to purchase armors from the merchant
//Increases health point by double of armor points bought and returns 3 gold for each armor point bought.
	healthPoint += armor * 2;
	return armor*3;
}

void Dwarves::Print() const{//method to print Faction information
//Prints the battle cry of Dwarves : “Taste the power of our axes!” in quotes 
//then prints the information as same as the Faction class.
	cout << '"' << "Taste the power of our axes!" << '"' << endl;
	cout << "Faction Name:         " << name << endl;
	if (isAlive) cout << "Status:               " << "Alive" << endl;
	else cout << "Status:               " << "Defeated" << endl;
	cout << "Number of Units:      " << numOfUnits << endl;
	cout << "Attack Point:         " << attackPoint << endl;
	cout << "Health Point:         " << healthPoint << endl;
	cout << "Unit Regen Number:    " << unitRegen << endl;
	cout << "Total Faction Health: " << totalHealth << endl;
}