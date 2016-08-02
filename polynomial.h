#include <iostream>

using namespace std;

class polynomial{
public:
	polynomial();
	polynomial(int*,int);
	polynomial(const polynomial&);
	~polynomial();

	int solve(int);
	
	polynomial operator=(const polynomial&);
	bool operator==(const polynomial&);
	bool operator!=(const polynomial&);
	polynomial operator*(const polynomial&);
	polynomial operator*(int);

	friend polynomial operator+(const polynomial&,const polynomial&);
	friend polynomial operator-(const polynomial&,const polynomial&);
	friend ostream& operator<<(ostream&,const polynomial&);
	friend istream& operator>>(istream&,polynomial&); 

private:
	int* coefficient;
	int degree;
};