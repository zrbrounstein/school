//This is the implementation for the array based queue in which front wrap

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

	int index = front;
	while(index != rear){
		data[index] = queue.data[index];
		index = (index+1)%max; //this modulo operator is how the queue implements wrapping around
	}
	data[index] = queue.data[index];
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

	int index = front;
	while(index != rear){
		data[index] = queue.data[index];
		index = (index+1)%max;
	}
	data[index] = queue.data[index];
	return *this;
}

bool Queue::enqueue(int k){
	if(empty()){
		front++;
	}	
	if(!full()){
		rear = (rear+1)%max; 
		data[rear] = k;
		return true;
	}
	else{
		return false;
	}
}

bool Queue::dequeue(int& k){
	if(!empty()){
		k = data[front];
		front = (front+1)%max;
		return true;
	}
	else{
		return false;
	}
}

bool Queue::empty() const {
	if(rear == -1){
		return true;
	}
	else{
		return false;
	}
}

bool Queue::full() const {
	if((front == (rear+1)%max) && (rear > -1)){ //have to ensure that the queue is not empty, thus the second argument
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
		front = rear = -1;
		return true;
	}
}

bool Queue::operator==(const Queue& queue) const{
	int index = front;
	while(index != rear){
		if(data[index] != queue.data[index]){
			return false;
		}
		index = (index+1)%max;
	}
	return true;
}

ostream& operator<<(ostream& os, const Queue& queue){
	if(queue.empty()){
		os << endl;
	}
	else{
		if(queue.front == queue.rear){
			os << '[' << queue.data[queue.front] << ']' << endl; //speical formatting is used
		}
		else{
			int index = queue.front;
			os << '[' << queue.data[index] << ']' << ' ';
			while(index != ((queue.rear+queue.max-1)%queue.max)){
				index = (index+1)%queue.max;
				os << queue.data[index] << ' ';
			}
			index = (index+1)%queue.max;
			os << '|' << queue.data[index] << '|' << endl;
		}	
	}
	return os;
}
