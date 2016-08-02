//This is the implementation for the array based queue in which front stays

#include "queue.h"
using namespace std;

Queue::Queue(int n){
	max = n;
	front = rear = -1;
	data = new int[max];
}

Queue::Queue(const Queue& queue){
	max = queue.max;
	front = queue.front;
	rear = queue.rear;
	data = new int[max];

	if(!queue.empty()){
		for(int i = 0; i <= rear; i++){
			data[i] = queue.data[i];
		}
	}
}

Queue::~Queue(){
	delete data;
	data = NULL;
}

Queue& Queue::operator=(const Queue& queue){
	if(this == &queue){
		return *this;
	}
	if(max != queue.max){
		max == queue.max;
		delete data;
		data = new int[max];
	}
	front = queue.front;
	rear = queue.rear;
	if(!queue.empty()){
		for(int i = 0; i <= rear; i++){
			data[i] = queue.data[i];
		}
	}
	return *this;
}

bool Queue::enqueue(int k){
	if(empty()){
		front++;
	}
	if(!full()){ //moves rear first and then assigns data values
		rear++;
		data[rear] = k;
		return true;
	}
	else{
		return false;
	}
}

bool Queue::dequeue(int& k){
	if(!empty()){
		k = data[0];
		if(rear > 1){	
			for(int i = 0; i < rear; i++){
				data[i] = data[i+1];
			}
		}
		rear--;
		return true;
	}
	else{
		return false;
	}
}

bool Queue::empty() const { //rear should only be front when there are no elements
	if(rear == -1){
		return true;
	}
	else{
		return false;
	}
}

bool Queue::full() const { //where rear is now pointing to the end of the queue
	if(rear == max-1){
		return true;
	}
	else{
		return false;
	}
}

bool Queue::clear(){
	if(empty()){
		return false;
	}
	else{
		rear = -1;
		return true;
	}
}

bool Queue::operator==(const Queue& queue) const{
	if(rear != queue.rear){
		return false;
	}
	else{
		for(int i = 0; i <= rear; i++){
			if(data[i] != queue.data[i]){
				return false;
			}
		}
	}
	return true;
}

ostream& operator<<(ostream& os, const Queue& queue){
	if(queue.empty()){
		os << endl;
	}
	else{
		os << '[' << queue.data[0] << ']' << ' '; //special formatting is used
		for(int i = 1; i < queue.rear; i++){		
			os << queue.data[i] << ' ';
		}
		if(queue.rear != 0){
			os << '|' << queue.data[queue.rear] << '|' << endl;
		}
		else{
			os << endl;
		}
	}
	return os;
}