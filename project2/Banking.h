#pragma once
#ifndef BANKING_H
#define BANKING_H
#include <string>
using namespace std;

/* Daniel Dobbs
*  Project 2 CS210
*  SNHU
*/

class Banking {
public:
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setInterestRate(double t_annualInterest);
	void setNumberOfYears(int t_numberOfYears);
	double getInitialInvestment() const;
	double getMontholyDeposit() const;
	double getInterestRate() const;
	int getNumberOfYears() const;
	double calculateBalanceWithoutMontholyDeposit(double t_initialInvestment, double t_annualInterest, int t_numberOfYears);
	double calculateBalanceWithMontholyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears);
	void printDetails(int year, double yearEndBalance, double interestEarned);
	string toCurrencyString(double money);
private:
	double totalAmount;
	double interestAmount;
	double yearlyTotalInterest;
	double monthlyDeposit;
	int numberOfYears;

};

#endif
