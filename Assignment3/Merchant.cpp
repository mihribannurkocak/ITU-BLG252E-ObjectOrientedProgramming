#include "Merchant.h"
#include <string>
#include <iostream>

using namespace std;
/*
* Mihriban Nur Kocak
* 150180090
*/

Merchant::Merchant(int starting_w, int starting_a) :startingWeaponPoint(starting_w), startingArmorPoint(starting_a), weaponPoint(starting_w),
armorPoint(starting_a){
	//the constructor should optionally take the starting weapon point and starting armor point attributes
	//It sets the weapon point and armor point and makes the revenue 0.
	revenue = 0;
	//there is no faction so set them as null at the begining
	firstFaction = NULL;
	secondFaction = NULL;
	thirdFaction = NULL;
}

void Merchant::AssignFactions(Faction* faction1, Faction* faction2, Faction* faction3) {
	//a method to assign factions in the battlefield.Factions in the battlefield 
	//are assigned to the merchant to manipulate during the game.
	firstFaction = faction1;
	secondFaction = faction2;
	thirdFaction = faction3;
}

bool Merchant::SellWeapons(string faction_name, int weapon_desired) {
	//a method to sell weapons to a faction.Sells weapons to faction named with weapon points given

	Faction* choosen_faction = NULL;

	if (firstFaction->GetName() == faction_name) {
		choosen_faction = firstFaction;
	}
	else if (secondFaction->GetName() == faction_name) {
		choosen_faction = secondFaction;
	}
	else if (thirdFaction->GetName() == faction_name) {
		choosen_faction = thirdFaction;
	}

	if (choosen_faction != NULL) { //one faction has choosen
		if (choosen_faction->IsAlive()) {
			//choosen faction is alive
			if (weapon_desired > weaponPoint) {
				//If weapon points tried to sell is greater than the available, notifies players with “You try to sell more weapons than you have in possession." and returns false.
				cout << "You try to sell more weapons than you have in possession." << endl;
				return false;
			}
			else {
				//notifies players with “Weapons sold!” and returns true.
				revenue += choosen_faction->PurchaseWeapons(weapon_desired); //increase revenue
				weaponPoint -= weapon_desired; //subrtract sold amount
				cout << "Weapons sold!" << endl;
				return true;
			}
		}
		else {
			//If faction tried to sell weapons is not alive, notifies players with “The faction you want to sell weapons is dead!" and returns false.
			cout << "The faction you want to sell weapons is dead!" << endl;
			return false;
		}
	}
	else return false;
}

bool Merchant::SellArmors(string faction_name, int armor_desired) {
	//a method to sell armors to a faction.Sells armors to faction named with armor points given, 

	Faction* choosen_faction = NULL;

	if (firstFaction->GetName() == faction_name) {
		choosen_faction = firstFaction;
	}
	else if (secondFaction->GetName() == faction_name) {
		choosen_faction = secondFaction;
	}
	else if (thirdFaction->GetName() == faction_name) {
		choosen_faction = thirdFaction;
	}

	if (choosen_faction != NULL) { //one faction has choosen
		if (choosen_faction->IsAlive()) {
			//choosen faction is alive
			if (armor_desired > armorPoint) {
				//If armor points tried to sell is greater than the available, notifies players with “You try to sell more armors than you have in possession." and returns false.
				cout << "You try to sell more armors than you have in possession." << endl;
				return false;
			}
			else {
				//notifies players with “Armors sold!” and returns true.
				revenue += choosen_faction->PurchaseArmors(armor_desired); //increase revenue
				armorPoint -= armor_desired; //subtract sold amount
				cout << "Armors sold!" << endl;
				return true;
			}
		}
		else {
			//If faction tried to sell armors is not alive, notifies players with “The faction you want to sell armors is dead!" and returns false.
			cout << "The faction you want to sell armors is dead!" << endl;
			return false;
		}
	}
	else return false;
}

void Merchant::EndTurn() {
	//a method to set the Merchant’s information at the end of the turn.
	//Sets the weapon and armor points to the starting values set in the constructor.
	weaponPoint = startingWeaponPoint;
	armorPoint = startingArmorPoint;
}