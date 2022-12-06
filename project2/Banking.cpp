#include <iostream>
#include <iomanip>
#include <sstream>
#include "Banking.h"

using namespace std;

void Banking::setInitialInvestment(double t_initialInvestment) {
	totalAmount = t_initialInvestment;
}
void Banking::setMonthlyDeposit(double t_monthlyDeposit) {
	monthlyDeposit = t_monthlyDeposit;
}
void Banking::setInterestRate(double t_annualInterest) {
	yearlyTotalInterest = t_annualInterest;
}
void Banking::setNumberOfYears(int t_numberOfYears) {
	numberOfYears = t_numberOfYears;
}
double Banking::getInitialInvestment() const {
	return totalAmount;
}
double Banking::getMontholyDeposit() const {
	return monthlyDeposit;
}
double Banking::getInterestRate() const {
	return yearlyTotalInterest;
}
int Banking::getNumberOfYears() const {
	return numberOfYears;
}

/*
* This method makes a formated string for printing an int and string together.
* money is any money in the banking like totalamount or interest earned.
* This method returns a formatted string
*/
string Banking::toCurrencyString(double money) {
	stringstream formmatedString;
	formmatedString << "$" << fixed << setprecision(2) << money;
	return formmatedString.str();
}

/*
* This method prints the details of each year when calculating the balance.
* each parameter is the inputs that we find in each calculate method.
* The method prints out a formatted line with the correct position.
*/
void Banking::printDetails(int year, double yearEndBalance, double interestEarned) {
	cout << setw(6) << right << year << setw(23) << right << toCurrencyString(yearEndBalance) << setw(28) << right << toCurrencyString(interestEarned) << endl;
}

/*
* This method calculates money each year without a monthy deposit.
* The input the initial investment, the annual interest, and the number of years to calculate
* The method displays a table that is formatted to show the balance and interest of someone's account without monthly deposits.
*/
double Banking::calculateBalanceWithoutMontholyDeposit(double t_initialInvestment, double t_annualInterest, int t_numberOfYears) {
	totalAmount = t_initialInvestment;
	
	//Display table with a method
	cout << setw(57) << right <<  "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << string(62, '=') << endl;
	cout << setw(6) << right << "Year" << setw(23) << right << "Year End Balance" << setw(28) << right << "Year End Earned Interest" << endl;
	cout << string(62, '-') << endl;

	for (int i = 0; i < t_numberOfYears; i++) {
		interestAmount = totalAmount * (t_annualInterest / 100);
		totalAmount = totalAmount + interestAmount;
		printDetails(i + 1, totalAmount, interestAmount);
	}

	return totalAmount;
}

/*
* This method calculates money each year with a monthy deposit.
* The input is the initial investment,the monthly depoist, the annual interest, and the number of years to calculate
* The method displays a table that is formatted to show the balance and interest of someone's account with monthly deposits.
*/
double Banking::calculateBalanceWithMontholyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears) {
	totalAmount = t_initialInvestment;
	cout << setw(57) << right << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << string(62, '=') << endl;
	cout << setw(6) << right << "Year" << setw(23) << right << "Year End Balance" << setw(28) << right << "Year End Earned Interest" << endl;
	cout << string(62, '-') << endl;

	for (int i = 0; i < t_numberOfYears; i++) {
		yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			interestAmount = (totalAmount + t_monthlyDeposit) * ((t_annualInterest / 100.00) / 12.00);
			yearlyTotalInterest = yearlyTotalInterest + interestAmount;
			totalAmount = totalAmount + t_monthlyDeposit + interestAmount;
		}
		printDetails(i + 1, totalAmount, yearlyTotalInterest);
	}
	return totalAmount;
}
