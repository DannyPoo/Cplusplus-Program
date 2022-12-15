#include "ItemTracking.h"
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include<string>
using namespace std;

/*
Description:
	This method is used to callIntFunc function for python code is public so it doesnt expose the logic.
Returns:
	This method returns a line saying how many times an item occurs.
*/
void ItemTracker::itemSearch() {
	cout << "What item would you like too search for?" << endl;
	cin >> itemName;
	itemName[0] = toupper(itemName[0]);
	cout << itemName << " occurs " << this->callIntFunc("determine_frequency", itemName) << " times";
}

/*
Description:
	This method is used to callProcedure function for python code is public so it doesnt expose the logic.
*/
void ItemTracker::displayHistogram() {
	this->callProcedure("output_histogram");
}

/*
Description:
	This method is used to callProcedure function for python code is public so it doesnt expose the logic. 
*/
void ItemTracker::displayQuantityList()
{
	this->callProcedure("determine_inventory");
}

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void ItemTracker::callProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("python_code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int ItemTracker::callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	This method is used to open the frequency.dat file and then read the files and convert what it read into a string.
Returns:
	The method returns a formatted string showing the itemname and how many stars there are.
*/
void ItemTracker::readList() {
	ifstream inFS;
	inFS.open("frequency.dat");
	while (!inFS.eof()) {
		inFS >> itemName;
		inFS >> quantity;
		
		if (!inFS.fail()) {
			cout << left << "   " << setw(15) << itemName << string(quantity, '*') << endl;
		}
	}
	inFS.close();

}
