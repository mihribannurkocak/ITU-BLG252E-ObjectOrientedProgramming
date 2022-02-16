#pragma once
#include <stdlib.h>
#include "Faction.h"
/*
* Mihriban Nur Kocak
* 150180090
*/
class Merchant {
	Faction* firstFaction;//representing first faction in the battlefield
	Faction* secondFaction;//representing second faction in the battlefield
	Faction* thirdFaction;//representing third faction in the battlefield
	const int startingWeaponPoint; // weapon point at begining
	const int startingArmorPoint; // armor point at begining
	int revenue; //wealth of merchant
	int weaponPoint; //current weapon point
	int armorPoint; //current armor point
public:
	//the constructor should optionally take the starting weapon point and starting armor point attributes
	//I set some default values to all parameters in case paramaters aren't given
	Merchant(int starting_w = 0, int starting_a = 0);

	//a method to assign factions in the battlefield
	void AssignFactions(Faction*, Faction*, Faction*);

	//a method to sell weapons to a faction.
	bool SellWeapons(string, int);
	
	//a method to sell armors to a faction.
	bool SellArmors(string, int);

	//a method to set the Merchant’s information at the end of the turn.
	void EndTurn();

	//getters and setters
	Faction* GetFirstFaction() const {
		return firstFaction;
	}
	Faction* GetSecondFaction() const {
		return secondFaction;
	}
	Faction* GetThirdFaction() const {
		return thirdFaction;
	}
	int GetStartingWeaponPoints() const {
		return weaponPoint;
	}
	int GetStartingArmorPoints() const {
		return armorPoint;
	}
	int GetRevenue() const {
		return revenue;
	}
	int GetWeaponPoints() const{
		return weaponPoint;
	}
	int GetArmorPoints() const{
		return armorPoint;
	}
	void SetFirstFaction(Faction* to_set) {
		firstFaction = to_set;
	}
	void SetSecondFaction(Faction* to_set) {
		secondFaction = to_set;
	}
	void SetThirdFaction(Faction* to_set) {
		thirdFaction = to_set;
	}
	void SetRevenue(int to_set) {
		revenue = to_set;
	}
	void SetWeaponPoints(int to_set) {
		weaponPoint = to_set;
	}
	void SetArmorPoints(int to_set) {
		armorPoint = to_set;
	}
};