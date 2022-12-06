#include "Banking.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

/*
* This method shows the starting display to the user before any input.
* There are no paramters
* The method returns a formatted table that displays what the user should input when asked for input.
*/
void DefaultDisplay() {
	cout << string(66, '*') << endl;
	cout << string(28, '*') << "Data Input" << string(28, '*') << endl;
	cout << "Initial investment amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	system("PAUSE");
}

/*
* This method gets input from the user and validates it.
* The paramters are used to hold the inputs in the values to be used at a later time.
* The method returns a table asking for input on each value and correctly validates input.
*/
void InputDisplay(double& t_initialInvestment, double& t_monthlyDeposit, double& t_annualInterest, int& t_numberOfYears) {
label:
	try {
		cout << string(66, '*') << endl;
		cout << string(28, '*') << "Data Input" << string(28, '*') << endl;
		string currentInput;
		cout << "Initial investment amount: " << endl;
		cin >> currentInput;
		t_initialInvestment = stod(currentInput);
		cout << "Monthly Deposit: $" << endl;
		cin >> currentInput;
		t_monthlyDeposit = stod(currentInput);
		cout << "Annual Interest: %" << endl;
		cin >> currentInput;
		t_annualInterest = stod(currentInput);
		cout << "Number of years: " << endl;
		cin >> currentInput;
		t_numberOfYears = stoi(currentInput);
		system("PAUSE");
		
		//This if statements make it so the user knows of an error when any value is a negative integer.
		if (t_initialInvestment < 0 || t_monthlyDeposit < 0 || t_annualInterest < 0 || t_numberOfYears < 0) {
			throw runtime_error("Invalid entry of negative integer");
		}
	}
	//This method catches the error of invalid integer and loops it so the user can reinput the integer as positive without breaking the calculations.
	catch (runtime_error except ) {
		cout << except.what() << endl;
		cout << "All inputs must be a positive integer" << endl;
		goto label;
	}
	//This method catches the error of invalid input if it has a letter in it so that it has to be a valid positive integer without breaking the calcuations.
	catch (invalid_argument except) {
		cout << except.what() << endl;
		cout << "All inputs must be a positive integer" << endl;
		goto label;
	}
}


int main() {
	Banking bank1;
	double intialAmount = 0.0;
	double totalAmount = 0.0;
	double interestAmount = 0.0;
	double yearlyTotalInterest = 0.0;
	double monthlyDeposit = 0.0;
	int numberOfYears = 0;
	DefaultDisplay();
	InputDisplay(intialAmount, monthlyDeposit, interestAmount, numberOfYears);

	bank1.calculateBalanceWithMontholyDeposit(intialAmount, monthlyDeposit, interestAmount, numberOfYears);
	bank1.calculateBalanceWithoutMontholyDeposit(intialAmount, interestAmount, numberOfYears);
	return 0;
}