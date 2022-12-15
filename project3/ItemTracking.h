#pragma once
#ifndef ITEM_TRACKING_H
#define ITEM_TRACKING_H
#define _CRT_SECURE_NO_WARNINGS
#include <string>


class ItemTracker {
public:
		void readList();
		void itemSearch();
		void displayQuantityList();
		void displayHistogram();

private:
	std::string itemName = "NoName";
	int quantity = -1;
	void callProcedure(std::string);
	int callIntFunc(std::string, std::string);
	//int callIntFunc(std::string, int);
};

#endif