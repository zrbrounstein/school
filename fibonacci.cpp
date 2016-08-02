#include <iostream>
using namespace std;

int fibonacci(int index){
	if(index < 1){
		return 0;
	}
	if((index == 1) || (index == 2)){
		return 1;
	}
	else{
		return fibonacci(index-2) + fibonacci(index-1);
	}
}