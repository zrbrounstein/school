//This is the implementation for the node based queue

#include "queueN.h"

using namespace std;

Node::Node(int c,Node* follow){
	data = c;
	next = follow;
}

Queue::Queue(int ignore){
	front = rear = NULL;
}

Queue::Queue(const Queue& queue){
	front = rear = NULL;
	Node* temp = queue.front;
	Node* N = new Node(temp->data,temp->next);
	front = rear = N;
	temp = temp->next;
	while(temp){
		Node* M = new Node(temp->data,temp->next); //new node takes the values of the temp node
		rear->next = M;
		rear = M;
		temp = temp->next;
	}
}

Queue::~Queue(){
	clear();
}

Queue& Queue::operator=(const Queue& queue){ //the assignment operator is implemented in the same way as the parameterized constructor
	if(this == &queue){
		return *this;
	}
	clear();
	front = rear = NULL;
	Node* temp = queue.front;
	Node* N = new Node(temp->data,temp->next);
	front = rear = N;
	temp = temp->next;
	while(temp){
		Node* M = new Node(temp->data,temp->next);
		rear->next = M;
		rear = M;
		temp = temp->next;
	}
	return *this;
}

bool Queue::enqueue(int n){
	if(empty()){
		Node* temp = new Node(n,NULL);
		front = rear = temp;
	}
	else if(!full()){
		if(empty()){
			Node* temp = new Node(n,NULL);
			front = rear = temp;
		}
		else{
			Node* temp = new Node(n,NULL);
			rear->next = temp;
			rear = temp;
			temp = NULL;
		}
	 	
		return true;
	}
	else{
		return false;
	}
}

bool Queue::dequeue(int& n){
	if(!empty()){
		Node* temp;
		n = front->data;
		temp = front;
		front = front->next;
		delete temp;
		return true;
	}
	else{
		return false;
	}
}

bool Queue::empty() const {
	if(front == NULL){
		return true;
	}
	else{
		return false;
	}
}

bool Queue::full() const {
	return false;
}

bool Queue::clear(){ //clear function deallocates all nodes and starts the Queue as if it were just declared
	if(!empty()){
		Node* temp = front;
		while(temp->next != NULL){
			front = front->next;
			delete temp;
			temp = front;	
		}
		delete front;
		temp = front = rear = NULL;
		return true;
	}
	else{
		return false;
	}
}

bool Queue::operator==(const Queue& queue) const{
	Node* temp1 = front;
	Node* temp2 = queue.front;
	while((temp1 != NULL) && (temp2 != NULL)){
		if(temp1->data != temp2->data){
			return false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if((temp1 != NULL) || (temp2 != NULL)){
		return false;
	}
	return true;
}

ostream& operator<<(ostream& os,const Queue& queue){
	if(queue.empty()){
		os << endl;
	}
	else{
		if(queue.front->next == NULL){
			os << '[' << queue.front->data << ']' << endl;
		}
		else{
			Node* temp = queue.front;
			os << '[' << temp->data << ']' << ' '; //first Queue member has special formatting
			temp = temp->next;
			while(temp){
				if(temp->next){
					os << temp->data << ' ';
				}
				else{
					os << '|' << temp->data << '|'; //last Queue member has special formatting
				}
				temp = temp->next;
			}
		}		
	}
	return os;
}