#include "UserInterface.h"
#include <string>
#include <iostream>
using namespace std;

//Prints the menu of options
void UserInterface::displayMenu()
{
	cout << "\nMain Menu" << "\n=============" << endl;
	cout << "1; Print a list of all items purchased. " << endl;
	cout << "2: Search for an item.                  " << endl;
	cout << "3: Display Histogram                    " << endl;
	cout << "4: Quit                                 " << endl;

}

//Gets the menu option from the user
//@param maxChoice - maximum choice in menu
//@returns - the choice 
int  UserInterface::getMenuChoice(int maxChoice) {
	string stringChoice;
	cin >> stringChoice;
	int choice = -1;
	try {
		choice = stoi(stringChoice);
		while (choice > maxChoice) {
			cin >> stringChoice;
			choice = stoi(stringChoice);
		}
	}
	catch (invalid_argument e) {
	}
	return choice;
}

//handles the choice
//@param choice - selected choice
void UserInterface::handleChoice(int choice)
{
	switch (choice) {
	case 1:
		this->itemTracker.displayQuantityList();
		break;
	case 2:
		this->itemTracker.itemSearch();
		break;
	case 3:
		this->itemTracker.displayHistogram();
		this->itemTracker.readList();
		break;
	default:
		return;
	};
}

//The main method function used to display the main menu
void UserInterface::mainMenu()
{
	displayMenu();
	int choice = getMenuChoice(4);
	system("cls");
	handleChoice(choice);
	while (choice != 4)
	{
		cout << endl;
		displayMenu();
		choice = getMenuChoice(4);
		system("cls");
		handleChoice(choice);
	}
}