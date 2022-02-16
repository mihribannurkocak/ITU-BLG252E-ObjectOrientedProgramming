#pragma once
#include <string>
#include <iostream>
using namespace std;
//////////////////////////////////
/*   Mihriban Nur Kocak         */
/*          150180090           */
//////////////////////////////////

class Land
{
	string name;
	string holding; 
	Land* next;

public:
	Land(string name_given, string holding_given) //constructor
	{
		name = name_given;
		holding = holding_given;
		next = NULL;
	};
	Land(const Land& land_given) //copy constructor
	{
		name = land_given.name;
		holding = land_given.holding;
		next = land_given.next;
	}
	Land* get_next_land() //to get next land of a land
	{
		return next;
	}
	string get_name_of_land() //to get name of a land
	{
		return name;
	}
	string get_holding_of_land() //to get holding of a land
	{
		return holding;
	}
	void set_as_next(Land* set_as_next = NULL) //to set one land's next as the other one, default parameter is NULL
	{
		next = set_as_next;
	}
};

class Character
{
	string name;
	int manpower;
	int gold;
	int numOfLands;
	Land* lands;

public:
	//Character();
	Character(string general = "unknown", int = 0, int = 0, int = 0);//constructor with default values
	Character(const Character& character_given); //copy constructor
	~Character();//destructor
	void getTaxes(); //to collect taxes
	void addLand(Land& land_to_add);   //add land to land linked list
	void removeLand(string to_remove); //remove land from linked list
	string get_name_of_character() //to get name of character
	{
		return name;
	}
	Land* get_head_of_the_character() //to reach head of character
	{
		return lands;
	}
	string print_name_for_constant() const //to get name of constant character
	{
		return name;
	}
	int get_gold_of_character() //to get number of golds of character
	{ 
		return gold;
	}
	int get_manpower_of_character() //to get number of manpower of character
	{ 
		return manpower;
	}
	int get_landnum_of_character() //to get number of lands of character
	{
		return numOfLands;
	}
	void set_head_as_null() //to set head as NULL
	{
		lands = NULL;
	}
	void change_manpower(int value) //to change manpower
	{
		manpower = value;
	}
	void change_gold(int value) //to change gold amount
	{
		gold = value;
	}
	void increase_numOfLands(int value) //to increase or decrease number of lands
	{
		numOfLands += value;
	}
	void set_head_as(Land* new_head) //to change head
	{
		lands = new_head;
	}
};

class CharacterList
{
	friend void listCharacters(CharacterList&);
	friend void listLands(CharacterList&);
	Character** characters; //Character* array which holds adresses of characters
	int size; //number of characters
public:
	CharacterList(); //constructor
	~CharacterList(); //destructor
	void addCharacter(Character*); //add character
	void delCharacter(Character*); //delete character
	Character* getPlayer(string player_name);//?get reference to asked character
	Character* getLandOwner(string land_name); //get reference to owner of asked land
	int get_size_of_list() //to get number of character
	{
		return size;
	}
	string get_name_of_first_character()//to get name of first character
	{
		return characters[0]->get_name_of_character();
	}
};
