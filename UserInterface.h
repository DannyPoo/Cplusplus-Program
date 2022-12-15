#pragma once
#ifndef USER_INTERACE_H
#define USER_INTERFACE_H
#include "ItemTracking.h"
#include <string>

class UserInterface {
public:
	int getMenuChoice(int);
	void handleChoice(int);
	void displayMenu();
	void mainMenu();
private:
	ItemTracker itemTracker;

};
#endif