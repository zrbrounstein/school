//This program is the array based stack implementation where the top stays

#include "stack.h"

using namespace std;

Stack::Stack(int n){ //default constructor where if the parameter is not specified n is automatically set equal to 10
	max = n;
	top = -1;
	actual = 0;
	data = new char[max];
}

Stack::Stack(const Stack& s){ //copy constructor
	max = s.max;
	top = s.top;
	actual = s.actual;

	data = new char[max];
	for(int i = 0; i < actual; i ++){ //individual data members are copied by incrementing from 0 to actual
		data[i] = s.data[i];
	}
}

Stack::~Stack(){ //destructor
	delete[] data;
	data = NULL;
}

Stack& Stack::operator=(const Stack& array){ //assignement operator
	if(this == &array){ //done so members can chain
		return *this;
	}
	if(max != array.max){ //if maxes are different sizes, the entire array is deallocated
		max == array.max;
		delete[] data;
		data = new char[max];
	}
	top = array.top;
	actual = array.actual;
	if(top == 0){
		for(int i = 0; i < actual; i++){
			data[i] = array.data[i];
		}
	}
	return *this;
}

bool Stack::push(char c){ //pushes new data on top
	if(top < 0){ //checks to see if the stack is empty
		top++;
	}	
	if(full()){ //checks to see if the stack is full
		return false;
	}
	else if(actual < max){
		actual++;
		for(int i = actual-1; i > 0; i--){ //shuffles data downward
			data[i] = data[i-1];
		}		
		data[0] = c;	
	}
	return true;
}

bool Stack::pop(char& c){ //pops top data and obtains the value
	if(empty()){ //checks to see if the stack is empty
		return false;
	}
	else if(top == 0){
		c = data[0];
		for(int i = 0; i < actual; i++){ //shuffles data upwards
			data[i] = data[i+1];
		}
		actual--;
		if(actual == 0){
			top--;
		}
	}
	return true;
}

bool Stack::empty() const {
	if(top < 0){
		return true;
	}
	else if(top == 0){
		return false;
	}
}

bool Stack::full() const {
	if(actual == max){
		return true;
	}
	else if(actual < max){
		return false;
	}
}

bool Stack::clear(){
	if(empty()){ //if function does not perform any new operation, it is seen as false
		return false;
	}
	else{
		top = -1;
		actual = 0;
		return true;
	}
}

bool Stack::operator==(const Stack& array) const{ //'equal to' comparison operator
	bool test = true;
	if(top != array.top){ //checks if both stacks are empty or not
		return false;
	}
	if(actual != array.actual){ //checks if both stacks contain the same amount of data
		return false;
	}
	else if(actual == array.actual){
		for(int i = 0; i < actual; i++){
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
	output << '[' << array.data[0] << ']' << ' '; //first stack member has special formatting
	for(int i = 1; i < array.actual-1; i++){		
		output << array.data[i] << ' ';
	}
	output << '|' << array.data[array.actual-1] << '|'; //last stack member has special formatting
	return output;
}
