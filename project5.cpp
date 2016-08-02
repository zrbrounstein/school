#include <iostream>
#include <fstream>
#include <cstdlib>
#include "String.h"

using namespace std;

void menu(int&);

int main()
{
	int menuoption = 0;
	int k = 0;

	char* fin;
	char* finhome;

	char* temp;
	temp = new char[30];
	char* temphome;
	temphome = temp;
	
	bool finished = false;

	String single_string, string1, string2;
	String* strarray;
	strarray = new String[10];
	String* strarrayhome;
	strarrayhome = strarray;
	
	ifstream myfile;
	
	do
	{
		menu(menuoption);
		
		switch(menuoption)
		{
			case 1:
				{
					cout << endl << endl << "What is the first string? ";
					cin >> temp;
					string1.initialize(temp);

					temp = temphome;

					cout << endl << endl << "What is the second string? ";
					cin >> temp;
					string2.initialize(temp);

					cout << "Let us compare the two strings!" << endl;
					cout << "String 1 compared to String 2: ";
					cout << string1.compare(string2);
					cout << endl << endl << "String 2 compared to String 1: ";
					cout << string2.compare(string1);

					cout << endl << endl << "Concatenating String 2 onto String 1 becomes:" << endl;
					string1.concat(string2);
					string1.print();

					cout << endl << endl << "Copying String 2 into String 1 becomes:" << endl;
					string1.copy(string2);
					string1.print();
					cout << endl;

					temp = temphome;
					string1.deallocate();
					string2.deallocate();
					break;
				}
			case 2:
				{
					cout << "What is the name of the file?";
					cin >> temp;
					while(*temp != '\0')
					{
						k++;
						temp++;
					}
					temp = temphome;
					fin = new char[k+1];
					finhome = fin;
					while(*temp != '\0')
					{
						*fin = *temp;
						fin++;
						temp++;
					}

					*fin = '\0';
					fin = finhome;
					temp = temphome;

					for(int i = 0; i < k; i++)
					{
						*temp = '\0';
						temp++;
					}
					temp = temphome;
				
					myfile.open(fin);
				
					myfile >> temp;
					string1.initialize(temp);
					temp = temphome;

					myfile >> temp;
					string2.initialize(temp);

					cout << endl;
					string1.print();
					cout << endl;
					string2.print();
					cout << endl;
				
					myfile.close();

					cout << "Let us compare the two strings!" << endl;
					cout << "String 1 compared to String 2: ";
					cout << string1.compare(string2);
					cout << endl << endl << "String 2 compared to String 1: ";
					cout << string2.compare(string1);

					cout << endl << endl << "Concatenating String 2 onto String 1 becomes:" << endl;
					string1.concat(string2);
					string1.print();

					cout << endl << endl << "Copying String 2 into String 1 becomes:" << endl;
					string1.copy(string2);
					string1.print();
					cout << endl;

					temp = temphome;
					string1.deallocate();
					string2.deallocate();

					break;
				}
			case 3:
				{
					cout << "What is the name of the file?";
					cin >> temp;
					while(*temp != '\0')
					{
						k++;
						temp++;
					}
					temp = temphome;
					fin = new char[k+1];
					finhome = fin;
					while(*temp != '\0')
					{
						*fin = *temp;
						fin++;
						temp++;
					}

					*fin = '\0';
					fin = finhome;
					temp = temphome;

					for(int i = 0; i < k; i++)
					{
						*temp = '\0';
						temp++;
					}
					temp = temphome;
				
					myfile.open(fin);

					myfile >> temp;
					temp = temphome;
					myfile >> temp;
					temp = temphome;

					for(int i = 0; i < 10; i++)
					{
						myfile >> temp;
						(*strarray).initialize(temp);
						temp = temphome;
						strarray++;
					}
					
					strarray = strarrayhome;
					cout << endl;
					for(int i = 0; i < 10; i++)
					{
						(*strarray).print();
						strarray++;
					}
					strarray = strarrayhome;
					temp = temphome;

					cout << endl << endl << "The following is a compilation of:" << endl;
					cout << endl << "The original string array," << endl << "which is modified by concatenating the third string onto the eighth string,";
					cout << endl << "printing the length of the second and seventh strings instead of the actual strings,";
					cout << endl << "and copying the ninth string into the tenth string" << endl << endl;

					String tempstring;
					tempstring.initialize(temp);
					for(int i = 0; i < 10; i++)
					{
						if(i == 2)
						{
							tempstring.copy(*strarray);
						}
						if(i == 7)
						{
							(*strarray).concat(tempstring);
						}
						if(i == 8)
						{
							tempstring.copy(*strarray);
						}
						if(i == 9)
						{
							(*strarray).copy(tempstring);
						}

						if((i != 1) && (i != 6))
						{
							(*strarray).print();
						}
						else
						{
							cout << endl << (*strarray).length() << endl;
						}

						strarray++;
						
					}
					tempstring.deallocate();
					strarray = strarrayhome;
					for (int i = 0; i < 10; ++i)
					{
						(*strarray).deallocate();
						strarray++;
					}

					break;
				}
			case 4:
				finished = true;
				break;
		}
	}
	while(!finished);

	fin = finhome;
	delete[] fin;
	fin = NULL;

	temp = temphome;
	delete[] temp;
	temp = NULL;

	strarray = strarrayhome;
	delete[] strarray;
	strarray = NULL;
	
	return 0;
}

void menu(int& selection)
{
	cout << endl << "Welcome to the String Program!" << endl << "==============================" << endl << endl;
	cout << "Please choose an option" << endl << endl;
	cout << "1. Write in two strings" << endl;
	cout << "2. Read in two strings from a file" << endl;
	cout << "3. Read in many strings from a file" << endl;
	cout << "4. Quit" << endl << endl << endl;
	cin >> selection;	
}
