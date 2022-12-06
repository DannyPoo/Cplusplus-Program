#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;



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
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("python_modules.my_python_code");
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
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_modules.my_python_code");
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
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_modules.my_python_code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
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

	return _PyLong_AsInt(presult);
}

//Get users input as a value then doubles
void doubleValue()
{
		int value;
		string currentInput;
		cout << "What value would you like to double?" << endl;
		cin >> currentInput;
		try {
			value = stoi(currentInput);
		}
		catch (invalid_argument e) {
			cout << "Value must be an integer" << endl;
			return;
		}
		cout << callIntFunc("DoubleValue", value);
	
}

//Prints the menu of options
void printMenu()
{
	cout << "\nMain Menu" << "\n=============" << endl;
	cout << "1; Print a Multiplicaiton Table" << endl;
	cout << "2: Double a Value" << endl;
	cout << "3: Quit" << endl;

}

//Get users input as a value then prints a multiplication table
void multiplicationTable()
{
	int value;
	string currentInput;
	cout << "What value would you like to see a multiplication table of?" << endl;
	cin >> currentInput;

	try {
		value = stoi(currentInput);
	}
	catch (invalid_argument e) {
		cout << "Value must be an integer" << endl;
		return;
	}

	cout << callIntFunc("MultiplicationTable", value);
}

//Gets the menu option from the user
//@param maxChoice - maximum choice in menu
//@returns - the choice 
int  getMenuChoice(int maxChoice) {
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
void handleChoice(int choice)
{
	switch (choice) {
	case 1:
		multiplicationTable();
		break;
	case 2:
		doubleValue();
		break;
	default:
		return;
	};
}

//The main method function used to display the main menu
void mainMenu()
{
	printMenu();
	int choice = getMenuChoice(3);
	system("cls");
	handleChoice(choice);
	while (choice != 3)
	{
		cout << endl;
		printMenu();
		choice = getMenuChoice(4);
		system("cls");
		handleChoice(choice);
	}
}

//The main entry point of the program
void main()
{
	mainMenu();
}
