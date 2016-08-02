#include "polynomial.h"
#include <fstream>
#include <cmath>

using namespace std;

polynomial::polynomial(){ //default polynomial is x^2 + x + 1
	degree = 2;

	coefficient = new int[degree+1];
	for(int i = 0; i < degree+1; i++){
		coefficient[i] = 1;
	}
}

polynomial::polynomial(int* coeff, int exponent){ //parameterized constructor
	degree = exponent;
	coefficient = new int[degree+1];

	for(int i = 0; i < degree+1; i++){
		coefficient[i] = coeff[i];
	}
}

polynomial::polynomial(const polynomial& poly){ //copy constructor
	degree = poly.degree;
	coefficient = new int[degree+1];

	for(int i = 0; i < degree+1; i++){
		coefficient[i] = poly.coefficient[i];
	}
}

polynomial::~polynomial(){ //destructor
	degree = 2;
	delete[] coefficient;
	coefficient = NULL;
}

int polynomial::solve(int input){ //user inputs a value and the a polynomial is evaluated
	int output = 0;
	
	for(int i = 0; i < degree+1; i++){
		output += coefficient[i]*pow((double)input,(double)(degree-i)); // pow works by pow(base,exponent)
		
	}
	return output;	
}

polynomial polynomial::operator=(const polynomial& poly){ //assignment operator
	if(this == &poly){
		return *this; //in case the two polynomials are equal
	}
	
	if(degree != poly.degree){
		degree = poly.degree;
		delete[] coefficient;
		coefficient = new int[degree+1];
	}

	for(int i = 0; i < (degree)+1; i ++){
		coefficient[i] = poly.coefficient[i];
	}

	return *this;
}

bool polynomial::operator==(const polynomial& poly){ //is equal operator
	bool test = true;
	if(degree != poly.degree){ //tests degree
		test = false;
	}
	else{
		for(int i = 0; i < degree+1; i++){
			if(coefficient[i] != poly.coefficient[i]){ //tests coefficients
				test = false;
			}	
		}
	}	

	return test;
}

bool polynomial::operator!=(const polynomial& poly){ // is not equal operator
	bool test = false;
	if(degree != poly.degree){ // tests degree
		test = true;
	}
	else{
		for(int i = 0; i < degree+1; i++){
			if(coefficient[i] != poly.coefficient[i]){ //tests coefficients
				test = true;
			}	
		}
	}

	return test;
}

polynomial polynomial::operator*(const polynomial& poly){ // multiplication of two polynomials
	polynomial multiply;

	if((degree != 0) || (poly.degree != 0)){
		multiply.degree = degree + poly.degree;
		delete[] multiply.coefficient;
		multiply.coefficient = new int[multiply.degree+1];
	}

	for(int i = 0; i < multiply.degree+1; i++){
		multiply.coefficient[i] = 0;
	}

	for(int i = 0; i < degree+1; i ++){
		for(int j = 0; j < poly.degree+1; j++){
			multiply.coefficient[i+j] = multiply.coefficient[i+j] + coefficient[i]*poly.coefficient[j];
		}
	}

	return multiply;
}

polynomial polynomial::operator*(int scalar){ //change the polynomial by a scalar in the coefficients
	polynomial scaled;
	if(degree != 2){
		scaled.degree = degree;
		delete[] scaled.coefficient;
		scaled.coefficient = new int[scaled.degree+1];
	}

	for(int i = 0; i < scaled.degree+1; i++){
		scaled.coefficient[i] = coefficient[i]*scalar;
	}
	return scaled;
}

polynomial operator+(const polynomial& poly1,const polynomial& poly2){ //addition of two polynomials
	polynomial addition;
	if(poly1.degree > poly2.degree){ //checks if first degree is higher
		
		if(poly1.degree != 2){
			addition.degree = poly1.degree;		
			delete[] addition.coefficient;
			addition.coefficient = new int[addition.degree+1];
		}
		
		int difference = poly1.degree - poly2.degree;
		for(int i = 0; i < difference; i ++){
			addition.coefficient[i] = poly1.coefficient[i];
		}
		for(int i = difference; i < addition.degree+1; i++){
			addition.coefficient[i] = poly1.coefficient[i] + poly2.coefficient[i-difference];
		}
	}
	else if(poly1.degree < poly2.degree){ // checks if second degree is higher
		
		if(poly2.degree != 2){
			addition.degree = poly2.degree;		
			delete[] addition.coefficient;
			addition.coefficient = new int[addition.degree+1];	
		}

		int difference = poly2.degree - poly1.degree;
		for(int i = 0; i < difference; i ++){
			addition.coefficient[i] = poly2.coefficient[i];
		}
		for(int i = difference; i < addition.degree+1; i++){
			addition.coefficient[i] = poly2.coefficient[i] + poly1.coefficient[i-difference];
		}
	}
	else if(poly1.degree == poly2.degree){ //checks if degrees are equal
		
		if(poly1.degree != 2){
			addition.degree = poly1.degree;
			delete[] addition.coefficient;
			addition.coefficient = new int[addition.degree+1];
		}

		for(int i = 0; i < addition.degree; i ++){
			addition.coefficient[i] = poly1.coefficient[i] + poly2.coefficient[i];
		}
	}

	return addition;
}

polynomial operator-(const polynomial& poly1,const polynomial& poly2){ //subtraction of two polynomials
	polynomial subtraction;
	if(poly1.degree > poly2.degree){ //which degree is higher
		
		if(poly1.degree != 2){
			subtraction.degree = poly1.degree;		
			delete[] subtraction.coefficient;
			subtraction.coefficient = new int[subtraction.degree+1];
		}

		int difference = poly1.degree - poly2.degree;
		for(int i = 0; i < difference; i ++){
			subtraction.coefficient[i] = poly1.coefficient[i];
		}
		for(int i = difference; i < subtraction.degree+1; i++){
			subtraction.coefficient[i] = poly1.coefficient[i] - poly2.coefficient[i-difference];
		}
	}
	else if(poly1.degree < poly2.degree){
		
		if(poly2.degree != 2){
			subtraction.degree = poly2.degree;		
			delete[] subtraction.coefficient;
			subtraction.coefficient = new int[subtraction.degree+1];
		}

		int difference = poly2.degree - poly1.degree;
		for(int i = 0; i < difference; i ++){
			subtraction.coefficient[i] = poly2.coefficient[i];
		}
		for(int i = difference; i < subtraction.degree+1; i++){
			subtraction.coefficient[i] = poly2.coefficient[i] - poly1.coefficient[i-difference];
		}
	}
	else if(poly1.degree == poly2.degree){
		
		if(poly1.degree != 2){
			subtraction.degree = poly1.degree;		
			delete[] subtraction.coefficient;
			subtraction.coefficient = new int[subtraction.degree+1];
		}

		for(int i = 0; i < subtraction.degree; i ++){
			subtraction.coefficient[i] = poly1.coefficient[i] - poly2.coefficient[i];
		}
	}

	return subtraction;
}

ostream& operator<<(ostream& output,const polynomial& poly){ //output to terminal

	for(int i = 0; i < poly.degree+1; i++){
		if(poly.coefficient[i] != 0){
				if((poly.coefficient[i] > 0) && (i != 0)){
					output << " + ";
				}
				else if((poly.coefficient[i] < 0) && (i != 0)){
					output << " - ";
				}
				else if((poly.coefficient[i] < 0) && (i == 0)){
					output << "-";
				}

				if((abs(poly.coefficient[i]) != 1) || (i == poly.degree)){
					output << abs(poly.coefficient[i]);
				}			

			if(poly.degree-i == 1){
				output << "x" << " ";
			}
			else if(poly.degree-i == 0){
				output << " ";
			}
			else if(poly.degree-i > 1){
				output << "x^" << poly.degree-i << " ";
			}		 
		}
	}
	cout << endl;
	return output;
}

istream& operator>>(istream& input,polynomial& poly){ //input from terminal
	input >> poly.degree;
	delete[] poly.coefficient;
	poly.coefficient = new int[poly.degree+1];
	for(int i = 0; i < (poly.degree)+1; i++){
		input >> poly.coefficient[i];
	}

	return input;
}
