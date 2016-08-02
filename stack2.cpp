//This program is the array based stack implementation where the top moves up

#include "stack.h"

using namespace std;

Stack::Stack(int n){ //default constructor where if the parameter is not specified n is automatically set equal to 10
	max = n;
	top = -1;
	data = new char[max];
}

Stack::Stack(const Stack& s){ //copy constructor
	max = s.max;
	top = s.top;
	data = new char[max];
	for(int i = top; i >= 0; i--){ //copy constructor by decrementing from top to 0
		data[i] = s.data[i];
	}
}

Stack::~Stack(){ //destructor
	delete[] data;
	data = NULL;
}

Stack& Stack::operator=(const Stack& array){ //assignment operator
	if(this == &array){ //done so members can chain
		return *this;
	}
	if(max != array.max){ //if maxes are different sizes, the entire array is deallocated
		max == array.max;
		delete[] data; 
		data = new char[max];
	}
	top = array.top;
	for(int i = top; i >= 0; i--){
		data[i] = array.data[i];
	}
	return *this;
}

bool Stack::push(char c){ //pushes new data on top
	if(full()){ //checks to see if the stack is full
		return false;
	}
	else if(top < max-1){
		top++;
		data[top] = c;	
	}
	return true;
}

bool Stack::pop(char& c){ //pops top data and obtains the value
	if(empty()){//checks to see if the stack is empty
		return false;
	}
	else if(top >= 0){
		c = data[top];
		top--;
	}
	return true;
}

bool Stack::empty() const {
	if(top < 0){
		return true;
	}
	else if(top >= 0){
		return false;
	}
}

bool Stack::full() const {
	if(top == max-1){
		return true;
	}
	else if(top < max-1){
		return false;
	}
}

bool Stack::clear(){
	if(empty()){ //if function does not perform any new operation, it is seen as false
		return false;
	}
	else{	
	top = -1;
	return true;
	}
}

bool Stack::operator==(const Stack& array) const{ //'equal to' comparison operator
	bool test = true;
	if(top != array.top){ //checks if both stacks contain the same amount of data
		return false;
	}
	else if(top == array.top){
		for(int i = 0; i < top+1; i++){
			if(data[i] != array.data[i]){
				test = false;
			}
		}
	}
	return test;
}

ostream& operator<<(ostream& output,const Stack& array){ //insertion operator
	if(array.empty()){
		output << endl;
		return output;
	}
	output << '[' << array.data[array.top] << ']' << ' '; //first stack member has special formatting
	for(int i = array.top-1; i > 0; i--){
		output << array.data[i] << ' ';
	}
	output << '|' << array.data[0] << '|'; //last stack member has special formatting
	return output;
}
