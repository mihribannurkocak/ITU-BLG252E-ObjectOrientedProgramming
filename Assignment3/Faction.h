#pragma once
#include <string>
#include <stdlib.h>
using namespace std;
/*
* Mihriban Nur Kocak
* 150180090
*/
class Faction {
protected: //private attributes is set as protected to make them reachable by derived classes
	string name; //name of the faction
	Faction* firstEnemy; //pointer to first enemy
	Faction* secondEnemy; //pointer to second enemy
	int numOfUnits; //number of manpower
	int attackPoint; //attack power
	int healthPoint; //health power
	int unitRegen; //num of regeneratable manpower
	int totalHealth;//multlipication of the number of units and health point
	bool isAlive; //alive status
public:
	/*
	* Constructor with parameter
	* I set some default values to all parameters in case paramaters aren't given
	*/
	Faction(string name_g = "default", int numOfUnits_g = 0, int attackPoint_g = 0, int healthPoint_g = 0, int unitRegen_g = 0);

	/*
	* to assign enemies for the faction. Enemy factions are assigned to the faction to manipulate during the game.
	*/
	void AssignEnemies(Faction*, Faction*);
	
	/*
	* a pure virtual method to perform attack by the faction’s attack behavior.
	*/
	virtual void PerformAttack() = 0;
	
	/*
	* a pure virtual method to receive attack from an enemy faction and act on it by the Faction’s damage behavior.
	*/
	virtual void ReceiveAttack(int, string) = 0;
	
	/*
	* a pure virtual method to receive weapon from the merchant and return the profit.
	*/
	virtual int PurchaseWeapons(int) = 0;
	
	/*
	* a pure virtual method to receive armor from the merchant and return the profit.
	*/
	virtual int PurchaseArmors(int) = 0;
	
	/*
	* a pure virtual method to print faction's information.
	*/

	virtual void Print() const;
	
	void EndTurn();
	/*
	* a method to set the Faction’s information at the end of the turn
	* this method updates the number of units, total health and alive status of the faction
	*/

	//getter and setters
	string GetName() const{
		return name;
	}
	Faction* GetFirstEnemy() const {
		return firstEnemy;
	}
	Faction* GetSecondEnemy() const {
		return firstEnemy;
	}
	int GetNumOfUnits() const {
		return numOfUnits;
	}
	int GetAttackPoint() const {
		return attackPoint;
	}
	int GetHealthPoint() const {
		return healthPoint;
	}
	int GetUnitRegen() const {
		return unitRegen;
	}
	int GetTotalHealth() const {
		return totalHealth;
	}
	bool IsAlive() const {
		return isAlive;
	}
	void SetName(string name_g){
		name = name_g;
	}	
	void SetFirstEnemy(Faction* enemy_g) {
		firstEnemy = enemy_g;
	}
	void SetSecondEnemy(Faction* enemy_g) {
		secondEnemy = enemy_g;
	}
	void SetNumOfUnits(int num_g) {
		numOfUnits= num_g;
	}
	void SetAttackPoint(int num_g) {
		attackPoint = num_g;
	}
	void SetHealthPoint(int num_g) {
		healthPoint = num_g;
	}
	void SetUnitRegen(int num_g) {
		unitRegen = num_g;
	}
	void SetTotalHealth(int num_g) {
		totalHealth = num_g;
	}
	void SetIsAlive(bool status_g) {
		isAlive = status_g;
	}
};
