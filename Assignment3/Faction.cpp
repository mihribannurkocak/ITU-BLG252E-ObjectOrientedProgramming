#include "Faction.h"
#include <string>
#include <iostream>
/*
* Mihriban Nur Kocak
* 150180090
*/
using namespace std;

Faction::Faction(string name_g, int numOfUnits_g, int attackPoint_g, int healthPoint_g, int unitRegen_g): attackPoint(attackPoint_g), name(name_g),
numOfUnits(numOfUnits_g),healthPoint(healthPoint_g),unitRegen(unitRegen_g){
/*
* the constructor should optionally take the name, number of units, attack point, health point, unit regeneration number attributes.
* It sets the total health value and makes the alive status true.
*/	
	totalHealth = numOfUnits_g * healthPoint;
	isAlive = true;
	//there is no enemy so set them as null at the begining
	firstEnemy = NULL;
	secondEnemy = NULL;
}

void Faction::AssignEnemies(Faction* enemy1, Faction* enemy2){
/*
* to assign enemies for the faction. Enemy factions are assigned to the faction to manipulate during the game.
*/
	firstEnemy = enemy1;
	secondEnemy = enemy2;
}

void Faction::Print() const{
/*
*
Faction Name:         <name> 
Status:               <"Alive" or "Defeated"> 
Number of Units:      <numOfUnits> 
Attack Point:         <attackPoint> 
Health Point:         <healthPoint> 
Unit Regen Number:    <unitRegen> 
Total Faction Health: <totalHealth> 
*/
	cout << "Faction Name:         " << name << endl;
	if (isAlive) cout << "Status:               " << "Alive" << endl;
	else cout << "Status:               " << "Defeated" << endl;
	cout << "Number of Units:      " << numOfUnits << endl;
	cout << "Attack Point:         " << attackPoint << endl;
	cout << "Health Point:         " << healthPoint << endl;
	cout << "Unit Regen Number:    " << unitRegen << endl;
	cout << "Total Faction Health: " << totalHealth << endl;
}

void Faction::EndTurn(){
/*
* a method to set the Faction’s information at the end of the turn. 
This method updates the number of units, total health and alive status of the faction.
If the number of units is less than 0 at the end of the turn, method should set it to 0.
If the number of units is 0, it should set alive status to false.
*/
	if (numOfUnits < 0) numOfUnits = 0;
	else {
		numOfUnits += unitRegen; //new units are born
	}

	totalHealth = numOfUnits * healthPoint; //need update because numofunits is changed
	if (numOfUnits == 0) isAlive = false; //not alive anymore
}