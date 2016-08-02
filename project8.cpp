#include "stack.h"

using namespace std;

int main(){
	Stack asdf;
	asdf.push('g');
	asdf.push('d');
	asdf.push('e');
	asdf.push('g');
	asdf.push('d');
	asdf.push('e');
	asdf.push('g');
	asdf.push('d');
	asdf.push('e');
	asdf.push('g');
	asdf.push('d');
	asdf.push('e');
	asdf.push('g');
	asdf.push('d');
	asdf.push('e');
	asdf.push('g');
	asdf.push('d');
	asdf.push('e');
	cout << asdf;
	Stack qwer(asdf);
	cout << qwer;
	char a;
	qwer.pop(a);
	cout << endl << qwer << a << endl;
	if(asdf == qwer){
	cout << "equal";
	}
	else{
	cout << "not equal";
	}
	cout << endl;
	Stack uio;
	if(uio.empty()){
	cout << "empty";
	}
	uio = qwer;
	if(!uio.empty()){
	cout << "not anymore!" << endl;
	}
	asdf.clear();
	if(asdf.empty()){
	cout << "gone";
	}
	return 0;
}
