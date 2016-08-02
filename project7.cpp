#include "polynomial.h"
#include <fstream>

using namespace std;

void menu(int&);

int main(){
	char* filename;
	filename = new char[30]; //char* feel more comfortable than string
	
	int pairs;
	int polynomial_num;
	int choice;
	int preimage;
	int polynomial1,polynomial2;
	int scale;
	int option = 0;
	bool finished = false;

	polynomial result;
	polynomial polynomial_default1;
	polynomial polynomial_default2;

	cout << endl << "What is the name of the file to access?   ";
	cin >> filename;

	ifstream fin;
	fin.open(filename);
	
	fin >> pairs;
	polynomial_num = 2*pairs; //how many pairs equate to amount of polynomials
	
	polynomial* polynomial_set;
	polynomial_set = new polynomial[polynomial_num]; //array of polynomials
	for(int k = 0; k < polynomial_num; k++){
		fin >> polynomial_set[k];
	}
	fin.close();

	do{
		menu(option);

		switch(option){
			case 1:
				for(int k = 0; k < polynomial_num; k++){
				cout << "[" << k+1 << "] " << polynomial_set[k];
				}
				break;
			case 2:
				cout << endl << endl << "Choose a polynomial to evaluate:  ";
				cin >> choice;
				cout << endl << endl << "What is the integer value?  ";
				cin >> preimage;

				cout << endl << endl << "At " << preimage << " the polynomial  " << polynomial_set[choice-1];
				cout << endl << "evaluates to " << polynomial_set[choice-1].solve(preimage) << endl << endl;
				break;
			case 3:
				cout << "Choose two polynomials to add together:  ";
				cin >> polynomial1 >> polynomial2;
				result = polynomial_set[polynomial1-1] + polynomial_set[polynomial2-1];
				cout << endl << result;
				break;
			case 4:
				cout << "Choose two polynomials to subtract:  ";
				cin >> polynomial1 >> polynomial2;
				result = polynomial_set[polynomial1-1]-polynomial_set[polynomial2-1];
				cout << endl << result;
				break;
			case 5:
				cout << "Choose a polynomial to multiply by a scalar:  ";
				cin >> polynomial1;
				cout << endl << polynomial_set[polynomial1-1] << endl << "What scalar do you want to multiply this by?  ";
				cin >> scale;
				cout << endl << polynomial_set[polynomial1-1]*scale;
				break;
			case 6:
				cout << "Choose two polynomials to multiply together:  ";
				cin >> polynomial1 >> polynomial2;
				result = polynomial_set[polynomial1-1]*polynomial_set[polynomial2-1];
				cout << endl << result;
				break;
			case 7:
				cout << "Here is a default polynomial:  ";
				cout << polynomial_default1 << endl << endl;
				cout << "And now here is the same polynomial set equal to the" << endl << "second polynomial from the set:" << endl;
				polynomial_default1 = polynomial_set[1];
				cout << polynomial_default1 << endl;

				cout << "Is this polynomial equal to the default?  ";
				if(polynomial_default1 == polynomial_default2){
					cout << "Yes, it is" << endl;
				}
				else if(polynomial_default1 != polynomial_default2){
					cout << "No, it is not" << endl;
				}
	
				cout << "Is this polynomial equal to the second in the polynomial set?  ";
				if(polynomial_default1 == polynomial_set[1]){
					cout << "Yes it is" << endl;
				}
				else if(polynomial_default1 != polynomial_set[1]){
					cout << "No it is not" << endl;
				}
				break;
			case 8:
				{
					cout << endl << endl << "Thank you for using Jiminy's Polynomial Program!" << endl << endl;
					finished = true;
				}
				
				break;
		}

	} while(!finished);

	delete[] polynomial_set;
	polynomial_set = NULL;

	delete[] filename;
	filename = NULL;
	return 0;
}

void menu(int& selection) //menu function
{
	cout << endl << endl << "Welcome to Jiminy's Polynomial Program!" << endl;
	cout << "=======================================" << endl << endl;
	cout << "Please select an option:" << endl << endl;
	cout << "1. Print out all the polynomials" << endl;
	cout << "2. Evaluate a polynomial at an integer value" << endl;
	cout << "3. Add two polynomials" << endl;	
	cout << "4. Subtract two polynomials" << endl;
	cout << "5. Multiply a polynomial by a scalar quantity" << endl;
	cout << "6. Multiply two polynomials" << endl;
	cout << "7. Compare a default polynomial to an existing polynomial" << endl;
	cout << "8. Exit" << endl << endl;
	cin >> selection;
	cout << endl << endl;
}