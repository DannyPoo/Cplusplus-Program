#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

// intializing of variables
int hours = 0;
int minutes = 0;
int seconds = 0;

// This method converts numbers 1-9 to have a 0 in front of them like 01.
string twoDigitString(unsigned int number) {
	stringstream digitString;
	digitString << setw(2) << setfill('0') << number;
	return digitString.str();
}


//This method formats time in AM and PM for the Clock.
string formatTime12(unsigned int hours, unsigned int minutes, unsigned int seconds) {
	stringstream formattedString;
	if (hours == 0)
	{
		formattedString << twoDigitString(12) << ":" << twoDigitString(minutes) << ":" << twoDigitString(seconds) << " A M";
	}
	else if (hours < 12) {
		formattedString << twoDigitString(hours) << ":" << twoDigitString(minutes) << ":" << twoDigitString(seconds) << " A M";
	}
	else
	{
		formattedString << twoDigitString(hours - 12) << ":" << twoDigitString(minutes) << ":" << twoDigitString(seconds) << " P M";
	}
	return formattedString.str();
}


//This method formats the time in the 24 hour clock.
string formatTime24(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
	stringstream formattedString;
	formattedString << twoDigitString(hours) << ":" << twoDigitString(minutes) << ":" << twoDigitString(seconds);
	return formattedString.str();
}

//This method creates a string usefull for creating the * in the clock interface. 
string createStringByCharAndLength(unsigned int length, char character) {
	stringstream charString;
	charString << setw(length) << setfill(character) << "";
	return charString.str();
}

//This method displays the menu interface.
void printMenu(const char* strings[], unsigned int numStrings, unsigned char width)
{
	cout << createStringByCharAndLength(width, '*') << endl;
	for (int i = 0; i < numStrings; i++) {
		stringstream row;
		row  << "* " << i+1 << " - " << strings[i];
		cout << setw(width - 1) << setfill(' ') << left << row.str() << "*" << endl;
		if (i != numStrings - 1)
		{
			cout << endl;
		}
	}
	cout << createStringByCharAndLength(width, '*') << endl;
}

//This method gets the user choice and stores it to an integer.
unsigned int  getMenuChoice(unsigned int maxChoice) {
	string stringChoice;
	cin >> stringChoice;
	unsigned int choice = stoi(stringChoice);
	while (choice > maxChoice) {
		cin >> stringChoice;
		choice = stoi(stringChoice);
	}
	return choice;
}

//This method displays the clock like an interface
void displayClocks(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
	cout << createStringByCharAndLength(27, '*') << createStringByCharAndLength(3, ' ') << createStringByCharAndLength(27, '*') << endl;
	cout << '*' << createStringByCharAndLength(6, ' ') << "12-HOUR CLOCK" << createStringByCharAndLength(6, ' ') << '*' << createStringByCharAndLength(3, ' ');
	cout << '*' << createStringByCharAndLength(6, ' ') << "24-HOUR CLOCK" << createStringByCharAndLength(6, ' ') << '*' << endl;
	cout << endl;
	cout << '*' << createStringByCharAndLength(6, ' ') << formatTime12(hours, minutes, seconds) << createStringByCharAndLength(7, ' ') << '*' << createStringByCharAndLength(3, ' ');
	cout << '*' << createStringByCharAndLength(8, ' ') << formatTime24(hours, minutes, seconds) << createStringByCharAndLength(9, ' ') << '*' << endl;
	cout << createStringByCharAndLength(27, '*') << createStringByCharAndLength(3, ' ') << createStringByCharAndLength(27, '*') << endl;

}

//This method adds one hour to the clock.
void addOneHour()
{
	hours++;
	if (hours == 24)
	{
		hours = 0;
	}
}


//This method adds one minute to the clock.
void addOneMinute()
{
	minutes++;
	if (minutes == 60)
	{
		addOneHour();
		minutes = 0;
	}
}

//this method adds on second to the clock.
void addOneSecond()
{
	seconds++;
	if (seconds == 60)
	{
		addOneMinute();
		seconds = 0;
	}
}

//This method handles what choice does what in the menu.
void handleChoice(unsigned int choice)
{
	switch (choice) {
	case 1:
		addOneHour();
		break;
	case 2:
		addOneMinute();
		break;
	case 3:
		addOneSecond();
		break;
	default:
		return;
	}
	displayClocks(hours, minutes, seconds);
}

//This menu shows the menu and is the mainloop of the clock program. 
void mainMenu()
{
	const char* strings[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
	printMenu(strings, 4, 26);
	int choice = getMenuChoice(4);
	system("cls");
	handleChoice(choice);
	while (choice != 4)
	{
		cout << endl;
		printMenu(strings, 4, 26);
		choice = getMenuChoice(4);
		system("cls");
		handleChoice(choice);
	}
}

int main()
{
	mainMenu();
}
