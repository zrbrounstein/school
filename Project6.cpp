#include <iostream>
#include <iomanip>
#include <fstream>
#include "Agency.h"

using namespace std;

void menu(int&);

int main()
{
	int option = 0; //this chooses a menu option
	bool finished = false; //this exits the program
	char* file_in;
	file_in = new char[20];

	char* search_make;
	search_make = new char[20];

	Agency agent;
	
	do
	{
		menu(option);
		
		switch(option)
		{
			case 1:			
				agent.readInData(file_in);
				break;
			case 2:			
				agent.print();
				break;			
			case 3:
				agent.printAvailableCars();
				break;
			case 4:
				agent.findMostExpensive();
				break;
			case 5:
				int rent_num, rent_days;
				agent.print();
				cout << endl << "Please choose the rental car number you would like to explore:" << endl;
				cin >> rent_num;
				cout << endl << endl << "How many days would you like to rent this car?";
				cin >> rent_days;
				cout << endl;
				agent.estimateCost(rent_num, rent_days);
				break;
			case 6:
				agent.sortByPrice();
				agent.print();
				break;
			case 7:
				agent.sortByMake();
				agent.print();
				break;
			case 8:
				cout << "What make of car are you interested in? ";
				cin >> search_make;
				agent.searchByMake(search_make);
				break;
			case 9:
				finished = true;
				break;										
		}
	}
	while(!finished);
	
	delete[] file_in;
	file_in = NULL;

	delete[] search_make;
	search_make = NULL;

	return 0;
}

void menu(int& selection)
{
	cout << endl << endl << "Welcome to the Updated Rental Car Program!" << endl;
	cout << "==========================================" << endl << endl;
	cout << "Please select an option:" << endl << endl;
	cout << "1. Read in from a file" << endl;
	cout << "2. Print out entire Agency" << endl;
	cout << "3. Print only available cars" << endl;
	cout << "4. Find the most expensive car" << endl;	
	cout << "5. Estimate the rental cost" << endl;
	cout << "6. Sort the Agency by the price of cars in descending order" << endl;
	cout << "7. sort the Agency by the make of cars in alphabetical order" << endl;
	cout << "8. Search the Agency by the make of a car" << endl;
	cout << "9. Exit" << endl << endl;
	cin >> selection;
	cout << endl << endl;
}
