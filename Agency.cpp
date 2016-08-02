#include <iostream>
#include <iomanip>
#include <fstream>
#include "Agency.h"

using namespace std;

Car::Car()
{
	char* makeptr = new char[5];
	make = makeptr;
	*makeptr = 'M';
	makeptr++;
	*makeptr = 'a';
	makeptr++;
	*makeptr = 'k';
	makeptr++;
	*makeptr = 'e';
	makeptr++;
	*makeptr = '\0';
	makeptr = make;
	
	char* modelptr = new char[6];
	model = modelptr;
	*modelptr = 'M';
	modelptr++;
	*modelptr = 'o';
	modelptr++;
	*modelptr = 'd';
	modelptr++;
	*modelptr = 'e';
	modelptr++;
	*modelptr = 'l';
	modelptr++;
	*modelptr = '\0';
	modelptr = model;
	
	year = 1950;
	price = 0.0;
	available = false;
}

Car::Car(char* init_make, char* init_model, int init_year, float init_price, bool init_available)
{
	char* init_makeptr = new char[20];
	make = init_makeptr;
	
	while(*init_make != '\0')
	{
		*init_makeptr = *init_make;
		init_makeptr++;
		init_make++;
	}
	*init_makeptr = '\0';
	init_makeptr = make;
	
	char* init_modelptr = new char[20];
	model = init_modelptr;
	
	while(*init_model !='\0')
	{
		*init_modelptr = *init_model;
		init_modelptr++;
		init_model++;
	}
	*init_modelptr = '\0';
	init_modelptr = model;
	
	year = init_year;
	price = init_price;
	available = init_available;
}

Car::Car(const Car& old_car)
{
	make = old_car.getMake();
	model = old_car.getModel();
	year = old_car.getYear();
	price = old_car.getPrice();
	available = old_car.getAvailable();
}

Car::~Car()
{
	delete[] make;
	make = NULL;
	delete[] model;
	model = NULL;
	year = 1950;
	available = false;
}

void Car::setMake(char* make_string)
{
	char* makehome;
	makehome = make;
	while(*make_string != '\0')
	{
		*make = *make_string;
		make++;
		make_string++;
	}
	*make = '\0';
	make = makehome;
}

void Car::setModel(char* model_string)
{
	char* modelhome;
	modelhome = model;
	while(*model_string != '\0')
	{
		*model = *model_string;
		model++;
		model_string++;
	}
	*model = '\0';	
	model = modelhome;
}

void Car::setYear(int car_year)
{
	year = car_year;
}

void Car::setPrice(float car_price)
{
	price = car_price;
}

void Car::setAvailable(bool car_available)
{
	available = car_available;
}

char* Car::getMake() const
{
	return make;
}

char* Car::getModel() const
{
	return model;
}

int Car::getYear() const
{
	return year;
}

float Car::getPrice() const
{
	return price;
}

bool Car::getAvailable() const
{
	return available;
}

void Car::print() const
{
	cout << year << " " << make << " " << model << " $" << setprecision(2) << fixed << price << "  Available: ";
	if(available)
	{
		cout << "Yes" << endl;
	}
	else if(!available)
	{
		cout << "No" << endl;
	}
}

void Car::copy(Car new_car)
{
	char* new_make;
	new_make = new_car.getMake();

	char* new_model;
	new_model = new_car.getModel();

	char* makehome;
	makehome = make;
	char* modelhome;
	modelhome = model;

	while(*new_make != '\0')
	{
		*make = *new_make;
		make++;
		new_make++;
	}
	*make = '\0';
	make = makehome;

	while(*new_model != '\0')
	{
		*model = *new_model;
		model++;
		new_model++;
	}
	*model = '\0';
	model = modelhome;

	year = new_car.getYear();
	price = new_car.getPrice();
	available = new_car.getAvailable();
}

Agency::Agency()
{
	char* nameptr = new char[5];
	name = nameptr;
	*nameptr = 'N';
	nameptr++;
	*nameptr = 'a';
	nameptr++;
	*nameptr = 'm';
	nameptr++;
	*nameptr = 'e';
	nameptr++;
	*nameptr = '\0';
	nameptr = name;
	
	int* zipcodeptr = new int;
	zipcode = zipcodeptr;
	*zipcodeptr = 89503;
	
	inventory = new Car[15];
}

Agency::Agency(const Agency& dealership)
{
	char* cpynameptr = new char[20];
	name = cpynameptr;
	
	char* dealername;
	dealername = dealership.name;
	
	while(*(dealername) != '\0')
	{
		*cpynameptr = *dealername;
		cpynameptr++;
		dealername++;
	}
	cpynameptr = name;
	
	int* cpyzipcodeptr = new int[5];
	zipcode = cpyzipcodeptr;
	
	int* dealerzipcode;
	dealerzipcode = dealership.zipcode;
	
	for(int i = 0; i < 5; i++)
	{
		*cpyzipcodeptr = *dealerzipcode;
		cpyzipcodeptr++;
		dealerzipcode++;
	}
	cpyzipcodeptr = zipcode;
	
	Car* cpyinventoryptr = new Car[15];
	inventory = cpyinventoryptr;
	
	Car* dealerinventory;
	dealerinventory = dealership.inventory;
	
	for(int i = 0; i < 15; i++)
	{
		(*cpyinventoryptr).copy(*dealerinventory);
		cpyinventoryptr++;
		dealerinventory++;
	}
}

Agency::~Agency()
{
	delete[] name;
	name = NULL;
	delete[] zipcode;
	zipcode = NULL;
	delete[] inventory;
	inventory = NULL;
}

void Agency::readInData(char* fileinput)
{
	cout << endl << "What is the name of the input file?" << endl;
	cin >> fileinput;

	ifstream fin;
	fin.open(fileinput);
	int* zipptr;
	zipptr = zipcode;
	Car* inventoryptr;
	inventoryptr = inventory;

	int readyear;

	char* readmake;
	readmake = new char[20];
	char* readmakehome;
	readmakehome = readmake;

	char* readmodel;
	readmodel = new char[20];
	char* readmodelhome;
	readmodelhome = readmodel;	

	float readprice;

	bool readavailable;
	
	fin >> name;
	fin >> *zipptr;

	for(int i = 0; i < 15; i++)
	{
		fin >> readyear;
		(*inventoryptr).setYear(readyear);
		fin >> readmake;
		(*inventoryptr).setMake(readmake);
		readmake = readmakehome;
		fin >> readmodel;
		(*inventoryptr).setModel(readmodel);
		readmodel = readmodelhome;
		fin >> readprice;
		(*inventoryptr).setPrice(readprice);
		fin >> readavailable;
		(*inventoryptr).setAvailable(readavailable);

		inventoryptr++;
	}

	delete[] readmake;
	readmake = NULL;

	delete[] readmodel;
	readmodel = NULL;
}

void Agency::print() const
{
	int* zipptr;
	zipptr = zipcode;
	cout << endl << name << " ";
	cout << *zipptr << endl;
	Car* inventoryptr;
	inventoryptr = inventory;
	for(int i  = 0; i < 15; i++)
	{
		cout << endl << "[" << i+1 << "]" << " ";
		(*inventoryptr).print();
		inventoryptr++;
	}
}

void Agency::printAvailableCars() const
{
	Car* inventoryptr;
	inventoryptr = inventory;
	for(int i = 0; i < 15; i++)
	{
		if((*inventoryptr).getAvailable())
		{
			(*inventoryptr).print();
		}
		inventoryptr++;
	}
}

void Agency::findMostExpensive() const //this function sets a max price and sorts throught the list for higher prices
{
	int k = 0;
	float max = -999.99;

	Car* inventoryptr;
	inventoryptr = inventory;

	for(int i = 0; i < 15; i++)
	{
		if((*inventoryptr).getPrice() > max)
		{
			max = (*inventoryptr).getPrice();
			k = i;
		}
		inventoryptr++;
	}

	inventoryptr = inventory;

	for(int i = 0; i < k; i++)
	{
		inventoryptr++;
	}

	cout << endl << endl << "The most expensive rental car is the:" << endl;
	cout << (*inventoryptr).getYear() << " " << (*inventoryptr).getMake() << " " << (*inventoryptr).getModel() << " $" << setprecision(2) << fixed << (*inventoryptr).getPrice();
	cout << endl;
	if((*inventoryptr).getAvailable())
	{
		cout << "Which is available to rent";
	}
	else
	{
		cout << "Which is not available to rent";
	}
	
}

float Agency::estimateCost(int car_number, int days) const
{
	Car* inventoryptr;
	inventoryptr = inventory;
	for(int i = 0; i < car_number-1; i++)
	{
		inventoryptr++;
	}

	cout << endl << "You chose the " << (*inventoryptr).getYear() << " " << (*inventoryptr).getMake() << " " << (*inventoryptr).getModel();
	cout << endl << "which costs $" << setprecision(2) << fixed << (*inventoryptr).getPrice() << " per day";
	cout << endl << "which makes your total venture cost $" << setprecision(2) << fixed << (*inventoryptr).getPrice() * days;
}

void Agency::searchByMake(char* check_make) const //this function uses a string compare functionality to check against the car makes
{
	bool compare = true;

	Car* inventoryptr;
	inventoryptr = inventory;

	char* str1;
	char* str2;

	for(int i = 0; i < 15; i++)
	{
		str1 = (*inventoryptr).getMake();
		str2 = check_make;

		while((*str1 != '\0') && (*str2 != '\0'))
   		{
        	if(*str1 != *str2)
        	{
           		compare = false;
           		break;
        	}
  
 		str1++;
 		str2++;
    	}

    	if(*str1 != '\0')
    	{
    		compare = false;
    	}
    	if(*str2 != '\0')
    	{
    		compare = false;
    	}

    	if(compare)
    	{
    		cout << endl;
    		(*inventoryptr).print();
    	}

    	inventoryptr++;
    	compare = true;
	}
}

void Agency::sortByMake() //this function uses bubble sort to alphabetize the makes of cars
{
	Car tempcar;
	bool swapped = true;
	Car* inventoryptr;
	Car* minimum;
	char* inventorymake;
	char* minimummake;

	while(swapped)
	{
		swapped = false;
		inventoryptr = inventory;
		minimum = inventory;
		inventoryptr++;
		for(int i = 0; i < 14; i++)
		{
			inventorymake = inventoryptr->getMake();
			minimummake = minimum->getMake();

			while((*minimummake != '\0') && (*inventorymake != '\0')) //string compare
   			{
        		if(*inventorymake < *minimummake)
        		{
           			tempcar.copy(*minimum);
           			minimum->copy(*inventoryptr);
           			inventoryptr->copy(tempcar);
           			swapped = true;	
     				break;          		 
        		}

        		else if(*inventorymake > *minimummake)
        		{
        			break;
        		}
   						
 				minimummake++;
 				inventorymake++;
 				
    		}

    		minimum++;
    		inventoryptr++;
    	}
    }	
}

void Agency::sortByPrice() //this function uses insertion sort to sort by price in descending order
{
	Car* sortedinventory;
	Car* inventoryptr;
	Car* inventorysort;
	sortedinventory = new Car[15];

	float inventoryprice;
	float sortedprice;
	int counter = 0;
	
	Car tempcar1;
	Car tempcar2;

	inventoryptr = inventory;
	inventorysort = sortedinventory;

	inventorysort->copy(*inventoryptr);

	for(int i = 0; i < 14; i++)
	{
		inventoryptr++;
		inventoryprice = inventoryptr->getPrice();

		inventorysort = sortedinventory;
		sortedprice = inventorysort->getPrice(); //this sets the first item in the sorted list

		while(inventoryprice < sortedprice)
		{	
			counter++;				
			inventorysort++;
			sortedprice = inventorysort->getPrice();
		}

		tempcar1.copy(*inventorysort);
		inventorysort->copy(*inventoryptr);

		for(int j = 0; j < ((i+1)-counter); j++) // $0.0 is the default price
		{
			
			inventorysort++;
			tempcar2.copy(*inventorysort);
			inventorysort->copy(tempcar1);
			tempcar1.copy(tempcar2);
		}
		counter = 0;				
	}

	inventoryptr = inventory;
	inventorysort = sortedinventory;

	for(int i = 0; i < 15; i++) //this copies each element from the sorted list into the original list
	{
		inventoryptr->copy(*inventorysort);
		inventorysort++;
		inventoryptr++;
	}

	delete[] sortedinventory;
	sortedinventory = NULL;
}