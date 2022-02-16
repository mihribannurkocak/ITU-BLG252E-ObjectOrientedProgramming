
#include "GreatWarrior.h"
#include <iostream>
#include <fstream>

using namespace std;
//////////////////////////////////
/*   Mihriban Nur Kocak         */
/*          150180090           */
//////////////////////////////////

Character::Character(string name_given, int manpower_given, int gold_given, int numlands_given)
{
	name = name_given;
	manpower = manpower_given;
	gold = gold_given;
	numOfLands = numlands_given;
	lands = NULL;
}

Character::Character(const Character& character_given)
{
	name = character_given.name;
	manpower = character_given.manpower;
	gold = character_given.gold;
	numOfLands = character_given.numOfLands;
	lands = character_given.lands;
}

Character::~Character() {
	//cout << "Character Destructor is called" << endl; //for debugging
	
	Land* traverse = lands;

	while (traverse != NULL) {
		Land* buffer = traverse;
		traverse = traverse->get_next_land();
		delete buffer;
	}
}

void Character::addLand(Land& land_to_add)
{
	//add land to end of the linked list
	if (lands == NULL)
	{
		lands = &land_to_add;
	}
	else
	{
		Land* traverse = lands;
		while (traverse->get_next_land() != NULL)
		{
			traverse = traverse->get_next_land();
		}
		traverse->set_as_next(&land_to_add);
	}
	land_to_add.set_as_next();
}

void Character::getTaxes()
{
	Land* traverse = lands;
	while (traverse != NULL)
	{
		if (traverse->get_holding_of_land() == "village")
		{
			gold += 5;
		}
		else if (traverse->get_holding_of_land() == "castle")
		{
			gold += 7;
		}
		else if (traverse->get_holding_of_land() == "city")
		{
			gold += 10;
		}
		traverse = traverse->get_next_land();
	}
}

void Character::removeLand(string name_of_remove)
{

	///// FILL HERE /////

	if (numOfLands > 0)
	{
		//random select if name of remove is empty string
		if (name_of_remove.empty())
		{
			//to remove land randomly
			srand(time(NULL));
			int order_of_remove = rand() % numOfLands;
			//int order_of_remove = numOfLands;

			Land* choose_to_remove = lands;
			for (int i = 0; i < order_of_remove; i++) {
				choose_to_remove = choose_to_remove->get_next_land();
			}
			name_of_remove = choose_to_remove->get_name_of_land();
		}

		if (lands->get_name_of_land() == name_of_remove)
		{
			//remove from beginning
			if (lands->get_next_land() == NULL)
			{
				delete lands;
				lands = NULL;
			}
			else
			{
				Land* buffer = lands;
				lands = lands->get_next_land();
				delete buffer;
				buffer = NULL;
			}
			}
		else
		{
			Land* traverse = lands;
			while (traverse->get_next_land()->get_name_of_land() != name_of_remove)
			{
				traverse = traverse->get_next_land();
			}

			if (traverse->get_next_land()->get_next_land() == NULL)
			{
				//remove from end
				Land* buffer = traverse->get_next_land();
				delete buffer;
				buffer = NULL;
				traverse->set_as_next();
			}
			else
			{
				//remove from middle
				Land* buffer = traverse->get_next_land();
				traverse->set_as_next(buffer->get_next_land());
				delete buffer;
				buffer = NULL;
			}
		}
		numOfLands--;		
	}
}

CharacterList::CharacterList()
{
	size = 0;
	characters = NULL;
}


CharacterList::~CharacterList()
{
	//cout << "Destructor is called" << endl;//for debugging
	for (int i = 0; i < size; i++) {
		delete characters[i];
	}
	delete[] characters;
	size = 0;
}


void CharacterList::addCharacter(Character* character_to_add)
{
	if (size == 0)
	{
		size++;
		characters = new Character*[size];
		characters[size - 1] = character_to_add;
	}
	else
	{
		Character** buffer_array = characters;
		for (int i = 0; i < size; i++)
		{
			buffer_array[i] = characters[i];
		}
		size++;
		characters = new Character*[size];
		for (int i = 0; i < size - 1; i++)
		{
			characters[i] = buffer_array[i];
		}
		characters[size - 1] = character_to_add;
		delete[] buffer_array;
	}
}

Character* CharacterList::getLandOwner(string land_name)
{
	Character* to_return = NULL;
	for (int i = 0; i < size; i++)
	{
		Land* traverse = characters[i]->get_head_of_the_character();

		while (traverse != NULL)
		{
			if (traverse->get_name_of_land() == land_name)
			{
				to_return = characters[i];
			}
			traverse = traverse->get_next_land();
		}
	}
	return to_return;
}

Character* CharacterList::getPlayer(string player_name) {
	Character* traverse = characters[0];
	for (int i = 0; i < size; i++) {
		if (traverse[i].get_name_of_character() == player_name) {
			return &traverse[i];
		}
	}
	return NULL;
}
void CharacterList::delCharacter(Character* character_to_delete)
{
	if (size > 0)
	{
		Character** buffer_array = characters;
		int delete_index = 0;
		for (int i = 0; i < size; i++)
		{
			buffer_array[i] = characters[i];
			if (characters[i] == character_to_delete) delete_index = i;
		}
		size--;
		characters = new Character*[size];
		int buffer_index = 0;
		for (int i = 0; i <= size; i++)
		{
			if (i != delete_index) {
				characters[buffer_index] = buffer_array[i];
				buffer_index++;
			}
		}
		delete buffer_array[delete_index];
		delete[] buffer_array;
	}
}