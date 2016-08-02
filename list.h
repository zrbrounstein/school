#include <iostream>
using namespace std;

template <typename T>
class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray<T>&);
    ~ListArray();

    bool insertBefore(const T&);
    bool insertAfter(const T&);
    bool get(T&) const;
    bool remove(T&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray<T>& operator = (const ListArray<T>&);

    template <typename S>
    friend ostream& operator << (ostream&, const ListArray<S>&);

private:
    T *data;
    int cursor;
    int actual;
    int size;
};

/*Constructors*/
template <typename T>
ListArray<T>::ListArray(int n){
	if(n < 1){ //in case there is an invalid entry
		size = 10;
	}
	else{
		size = n;
	}	
	cursor = -1;
	actual = 0;
	data = new T[size];
}

template <typename T>
ListArray<T>::ListArray(const ListArray<T>& listarray){
	size = listarray.size;
	data = new T[size];
	actual = listarray.actual;
	cursor = listarray.cursor;
	for(int i = 0; i < actual; i++){
		data[i] = listarray.data[i];
	}
}

template <typename T>
ListArray<T>::~ListArray(){
	delete data;
	data = NULL;
}

/*Edit List*/

template <typename T>
bool ListArray<T>::insertBefore(const T& value){
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

template <typename T>
bool ListArray<T>::insertAfter(const T& value){
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

template <typename T>
bool ListArray<T>::get(T& value) const {
	if(isEmpty()){
		return false;
	}
	else{
		value = data[cursor];
		return true;
	}
}

template <typename T>
bool ListArray<T>::remove(T& value){
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

template <typename T>
void ListArray<T>::clear(){
	cursor = -1;
	actual = 0;
}

/*Move Cursor*/

template <typename T>
bool ListArray<T>::goToBeginning(){
	if((cursor > 0) && (actual > 1)){
		cursor = 0;
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
bool ListArray<T>::goToEnd(){
	if((cursor < size-1) && (actual > 1)){
		cursor = actual-1;
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
bool ListArray<T>::goToNext(){
	if(cursor < actual-1){
		cursor++;
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
bool ListArray<T>::goToPrior(){
	if((cursor > 0) && (actual > 1)){
		cursor--;
		return true;
	}
	else{
		return false;
	}
}

/*Conditions*/

template <typename T>
bool ListArray<T>::isEmpty() const{
	if(actual == 0){
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
bool ListArray<T>::isFull() const{
	if(actual == size){
		return true;
	}
	else{
		return false;
	}
}

/*Assignment operator*/

template <typename T>
ListArray<T>& ListArray<T>::operator=(const ListArray<T>& listarray){
	if(this = &listarray){
		return *this;
	}
	if(size != listarray.size){
		delete data;
		size = listarray.size;
		data = new T(size);
	}
	actual = listarray.actual;
	cursor = listarray.cursor;
	for(int i = 0; i < actual; i++){
		data[i] = listarray.data[i];
	}
	return *this;
}

template <typename S>
ostream& operator<<(ostream& os,const ListArray<S>& listarray){
	if(listarray.isEmpty()){
		os << endl;
	}
	else{
		for(int i = 0; i < listarray.cursor; i++){
			os << listarray.data[i] << ' ';
		}
		os << '[' << listarray.data[listarray.cursor] << ']' << ' ';
		for(int i = listarray.cursor+1; i < listarray.actual; i++){
			os << listarray.data[i] << ' ';
		}
	}
	return os;
}