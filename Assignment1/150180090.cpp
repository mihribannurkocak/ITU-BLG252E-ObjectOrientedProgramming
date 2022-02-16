//////////////////////////////////
/*   Mihriban Nur Kocak         */
/*          150180090           */
//////////////////////////////////

#include "GreatWarrior.h"
#include "GreatWarrior.cpp"
#include <iostream>
#include <fstream>

/*	Define necessary classes and attributes in GreatWarrior.h and GreatWarrior.cpp */

/*	= Fill in the blanks in this main.cpp file. The parts that you need to implemented are specified below.
    = Please write your code between ///// FILL HERE ///// lines.
    = The expressions you need to print out with cout operation are given in necessary format.
    = You can use them directly by filling the variable parts.
*/

using namespace std;

void listCharacters(CharacterList&);
void listLands(CharacterList&);
void readData(string, CharacterList&);
void printGameMenu();
bool endOfTurn(Character*, int);

int main()
{
    cout << "Welcome to the Great Warriors. Create your character and attack other lands to be a great warrior.\n"
        << endl;

    CharacterList charList; //an CharacterList object which has array of my characters and number of characters

    string fileName = "characters.txt"; //read characters.txt file
    readData(fileName, charList);

    /* creating player's character */
    string name, land, general;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter name of your capital: ";
    cin >> land;

    cout << "Enter name of your general: ";
    cin >> general;

    ///// FILL HERE /////

    /*  Create your constant general object and your own character object,
        then add your character into characters list */
    
    const Character my_general = Character(general, 0, 0, 0);
    Character* my_character = new Character(name, 3, 20, 1);
    Land* initial_land = new Land(land, "village");
    my_character->addLand(*initial_land);
    charList.addCharacter(my_character);
    
    ///// FILL HERE /////

    // In-game loop
    int choice = 0, round = 0;
    while (choice != 6)
    {
        printGameMenu();
        cin >> choice;
        bool go_next = true;
        switch (choice)
        {
        case 1:
        {
            cout << "You have rested in your palace." << endl;
            cout << "You've talked with your general " << my_general.print_name_for_constant() << "." << endl;
            round++;
            go_next = endOfTurn(my_character, round);
            break;
        }
        case 2:
        {
            listLands(charList);
            cout << "Enter name of the land to attack." << endl;

            string land;
            cin >> land;

            ///// FILL HERE /////

            /*	Get the attacked player and execute the attack considering the manpower each side has:

                    -	If you won, attacked side will lose all manpower and the attacked land will be yours.
                        You will also lose some manpower (as much as attacked lose).
                        Print this: cout << "You've won the battle and conquered " << land << "." << endl;

                    -	If you lose, you will lose all your manpower.
                        Print this: cout << "You've lost the battle and " << __number of manpower you lost__ << " manpower." << endl;
            */

            Character* player_to_be_attacked = charList.getLandOwner(land);
            if (player_to_be_attacked == my_character) {
                //when trying to attack your own land
                cout << "You can't attack to yourself" << endl;
                break;
            }
            else if (player_to_be_attacked == NULL) {
                //when trying to attack non-existing land
                cout << "There is no such land" << endl;
                break;
            }

            if (my_character->get_manpower_of_character() >= player_to_be_attacked->get_manpower_of_character())
            {
                //I am the winner of war
                Land* taken_land = player_to_be_attacked->get_head_of_the_character();
                while (taken_land->get_name_of_land() != land)
                {
                    taken_land = taken_land->get_next_land();
                }
                Land* land_to_add = new Land(*taken_land); //copy land to new one
                my_character->addLand(*land_to_add); //add copied land to me
                my_character->increase_numOfLands(1); //increase numOfLands by 1
                player_to_be_attacked->removeLand(land); //remove land from attacked player                                                                                    //delete land from loser
                my_character->change_manpower(my_character->get_manpower_of_character() - player_to_be_attacked->get_manpower_of_character()); //I lost some manpower
                cout << "You've won the battle and conquered " << land << "." << endl;
                if (player_to_be_attacked->get_landnum_of_character() == 0)
                    charList.delCharacter(player_to_be_attacked); //when attacked player has 0 land after attack delete character
            }
            else
            {
                //I am the looser of war
                cout << "You've lost the battle and " << my_character->get_manpower_of_character() << " manpower." << endl;
                my_character->change_manpower(0);//lost all manpower
            }

            ///// FILL HERE /////

            round++;
            go_next = endOfTurn(my_character, round);
            break;
        }
        case 3:
        {
            cout << "How much manpower do you need? (1 manpower=5 gold)" << endl;

            int order;
            cin >> order;

            ///// FILL HERE /////

            /* Check if you have enough money to get the requested manpower:

                    - 	If you have, you got the manpower you want.
                        Print this: cout << "Order successful. You have " << __number of manpower you have after purchase__ << " manpower." << endl;

                    -	If you do not, print this: cout << "You do not have enough money." << endl;
                */
            if (my_character->get_gold_of_character() >= order * 5)
            {
                //have enough money to buy manpower
                my_character->change_gold(my_character->get_gold_of_character() - (order * 5));
                my_character->change_manpower(order + my_character->get_manpower_of_character());
                cout << "Order successful. You have " << my_character->get_manpower_of_character() << " manpower." << endl;
            }
            else
            {
                cout << "You do not have enough money." << endl;
            }
            ///// FILL HERE /////

            //round++;
            //go_next = endOfTurn(*my_character, round);
            break;
        }
        case 4:
        {
            listCharacters(charList);
            break;
        }
        case 5:
        {
            listLands(charList);
            break;
        }
        case 6:
            return 0;
        default:
            cout << "You entered an invalid value. Try again." << endl;
        }

        ///// FILL HERE /////

        /*	Check if the game is over in two cases:

            -	Call the endOfTurn function which is defined below in the code.
                endOfTurn function executes the necessary end of turn process and
                returns a bool value which indicates if you can continue the game or not.

            -	Terminate the program if you are the only great warrior left.
                Print this: cout << __your player name__ << " is the only great warrior now." << endl;
        */

        //cout << "Head3 : " << my_character->get_head_of_the_character()->get_name_of_land() << endl;
        //cout << my_character->get_gold_of_character() << endl; //for testing
        if (charList.get_size_of_list() == 1 ){
            //game is over if there is only one warrior left
            choice = 6;
            cout << charList.get_name_of_first_character() << " is the only great warrior now." << endl;
        }
        else if (!go_next) {
            //game is over according to endOfTurn return value
            choice = 6;
        }
        ///// FILL HERE /////
    }
    return 0; //I addded this return it was not existed in template
}

void readData(string fileName, CharacterList& charList)
{
    fstream dataFile(fileName.c_str());

    if (dataFile.is_open())
    {

        string word;
        while (dataFile >> word)
        {

            string name, title;
            int money, manpower, numOfLands;

            name = word;
            dataFile >> manpower;
            dataFile >> money;
            dataFile >> numOfLands;

            ///// FILL HERE /////

            /* Create a new character with read data */
            Character* character_to_add = new Character(name, manpower, money, numOfLands);

            ///// FILL HERE /////

            string landName, holding;

            for (int i = 0; i < numOfLands; i++)
            {
                dataFile >> landName;
                dataFile >> holding;

                ///// FILL HERE /////

                /* Create a new land object with read data and assign the land to the character you have created */
                Land* land_to_add = new Land(landName, holding);
                character_to_add->addLand(*land_to_add);

                ///// FILL HERE /////
            }

            ///// FILL HERE /////

            /* Add the character into character list */
            charList.addCharacter(character_to_add);
            ///// FILL HERE /////
        }
        dataFile.close();
    }
    else
        cout << "Unable to open the file" << endl;

    return;
}

void printGameMenu()
{
    cout << endl;
    cout << "1. Stay in your palace" << endl;
    cout << "2. Attack to a land" << endl;
    cout << "3. Buy manpower" << endl;
    cout << "4. List characters" << endl;
    cout << "5. List lands" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

void listCharacters(CharacterList& charList)
{
    cout << endl;

    ///// FILL HERE /////

    /* Print out the names of each character in character list in a loop */

    for (int i = 0; i < charList.size; i++)
    {
        cout << charList.characters[i]->get_name_of_character() << endl;
    }
    ///// FILL HERE /////
}

void listLands(CharacterList& charList)
{
    cout << endl;

    ///// FILL HERE /////

    /*	Loop over each character in characters list and print out their lands in following format:
        cout << __name of land__ << " " << __type of land__ << " owned by " << __name of player__ << endl;
        (i.e. Gotham city owned by Batman)
    */
    for (int i = 0; i < charList.size; i++)
    {
        string name_of_player = charList.characters[i]->get_name_of_character();
        Land* traverse = charList.characters[i]->get_head_of_the_character();

        while (traverse != NULL)
        {
            string name_of_land = traverse->get_name_of_land();
            string type_of_land = traverse->get_holding_of_land();
            cout << name_of_land << " " << type_of_land << " owned by " << name_of_player << endl;
            traverse = traverse->get_next_land();
        }
    }

    ///// FILL HERE /////

    cout << endl;
}

bool endOfTurn(Character* player, int round)
{ //return a bool value that indicates if the game is over or not.

    ///// FILL HERE /////

    /* End of turn evaluations:
        -	Collect taxes and feed soldiers

        -	Check the number of lands you have and if you do not have any lands left, the game is over
            Print this:	cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
                        cout << endl;
                        cout << "GAME OVER." << endl;

        -	Check the number of manpower you have and if you do not have any manpower left, you lose one of your lands randomly.
            Print this:	cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;

        -	Check the amount of money you have, if you do not have enough money to feed your soldiers you lose
            the soldiers that you cannot feed. 1 gold for each soldier is needed. If you have 5 gold and 6 soldiers 1 soldier will
            run away from your army.
            Print this: cout << __number of runaway soldiers__ << " soldiers run away from your army because you don't have enough gold to feed them." << endl;

        -	At last, print your status in the following format:
            cout << "Turn " << round << ": " << " " << __name of your player__ << " has " << __number of lands you have__
        << " land(s), " << __number of manpower you have__ << " manpower and " << __number of golds you have__ << " golds." << endl;

    */
    bool situation = true; //flag value for game ending
    player->getTaxes(); //Firstly the taxes are collected according to lands
    
    if (player->get_landnum_of_character() == 0)
    {
        //Secondly numOfLands is checked, if it is zero the game is over
        cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
        cout << endl;
        cout << "GAME OVER." << endl;
        situation = false;
    }
    else
    {
        if (player->get_manpower_of_character() == 0)
        {
            //Thirdly if manpower is equal to zero, one of the random land will be lost
            
            player->removeLand(""); //sent empty string for random delete
            cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;
        }

        if (player->get_gold_of_character() < player->get_manpower_of_character())
        {
            //if you dont have enough money to feed soldiers, lose manpower
            cout << player->get_manpower_of_character() - player->get_gold_of_character() << " soldiers run away from your army because you don't have enough gold to feed them." << endl;
            player->change_manpower(player->get_gold_of_character());
            player->change_gold(0);
        }
        else
        {
            //feed soldiers
            player->change_gold(player->get_gold_of_character() - player->get_manpower_of_character());
        }

        cout << "Turn " << round << ": "
            << " " << player->get_name_of_character() << " has " << player->get_landnum_of_character()
            << " land(s), " << player->get_manpower_of_character() << " manpower and " << player->get_gold_of_character() << " golds." << endl;
    }

    return situation;
    ///// FILL HERE /////
}