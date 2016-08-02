#include "alist.h"
using namespace std;

/*Constructors*/
ListArray::ListArray(int n){
	if(n < 1){ //in case there is an invalid entry
		size = 10;
	}
	else{
		size = n;
	}	
	cursor = -1;
	actual = 0;
	data = new int[size];
}

ListArray::ListArray(const ListArray& listarray){
	size = listarray.size;
	data = new int[size];
	actual = listarray.actual;
	cursor = listarray.cursor;
	for(int i = 0; i < actual; i++){
		data[i] = listarray.data[i];
	}
}

ListArray::~ListArray(){
	delete data;
	data = NULL;
}

/*Edit List*/

bool ListArray::insertBefore(const int& value){
	if(isFull()){
		return false;
	}
	else{
		if(isEmpty()){
			cursor++;
			actual++;
			data[cursor] = value;
		}
		else{
			for(int i = actual; i > cursor; i--){
				data[i] = data[i-1];
			}
			data[cursor] = value;
			actual++;
		}
		return true;
	}
}

bool ListArray::insertAfter(const int& value){
	if(isFull()){
		return false;
	}
	else{
		if(isEmpty()){
			cursor++;
			actual++;
			data[cursor] = value;
		}
		else{
			for(int i = actual; i > cursor+1; i--){
				data[i] = data[i-1];
			}
			data[cursor+1] = value;
			cursor++;
			actual++;
		}
		return true;
	}
}

bool ListArray::get(int& value)const{
	if(isEmpty()){
		return false;
	}
	else{
		value = data[cursor];
		return true;
	}
}

bool ListArray::remove(int& value){
	if(isEmpty()){
		return false;
	}
	else{
		value = data[cursor];
		actual--;
		if(cursor == actual){	
			cursor = 0;
		}
		else{
			for(int i = cursor; i < actual; i++){
				data[i] = data[i+1];
			}
		}
		return true;
	}
}

/*CLEAR LIST*/

void ListArray::clear(){
	cursor = -1;
	actual = 0;
}

void ListArray::changeSize(int change){
	cursor = -1;
	actual = 0;
	delete data;
	size = change;
	data = new int[size];
}

/*Move Cursor*/

bool ListArray::goToBeginning(){
	if((cursor > 0) && (actual > 1)){
		cursor = 0;
		return true;
	}
	else{
		return false;
	}
}

bool ListArray::goToEnd(){
	if((cursor < size-1) && (actual > 1)){
		cursor = actual-1;
		return true;
	}
	else{
		return false;
	}
}

bool ListArray::goToNext(){
	if(cursor < actual-1){
		cursor++;
		return true;
	}
	else{
		return false;
	}
}

bool ListArray::goToPrior(){
	if((cursor > 0) && (actual > 1)){
		cursor--;
		return true;
	}
	else{
		return false;
	}
}

/*Conditions*/

bool ListArray::isEmpty()const{
	if(actual == 0){
		return true;
	}
	else{
		return false;
	}
}

bool ListArray::isFull()const{
	if(actual == size){
		return true;
	}
	else{
		return false;
	}
}

/*Assignment operator*/

ListArray& ListArray::operator=(const ListArray& listarray){
	if(this == &listarray){
		return *this;
	}
	if(size != listarray.size){
		delete data;
		size = listarray.size;
		data = new int(size);
	}
	actual = listarray.actual;
	cursor = listarray.cursor;
	for(int i = 0; i < actual; i++){
		data[i] = listarray.data[i];
	}
	return *this;
}

/*Insertion Operator*/

ostream& operator<<(ostream& os,const ListArray& listarray){
	if(!listarray.isEmpty()){
		for(int i = 0; i < listarray.actual; i++){
			os << listarray.data[i] << ' ';
		}
	}
	os << endl;
	return os;
}
