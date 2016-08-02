//This program is the node based stack implementation

#include "stackN.h"

using namespace std;

Node::Node(char c,Node* follow){ //Node parameterized constructor
	data = c;
	next = follow;
}

Stack::Stack(int ignore){ //stack default constructor
	top = NULL;
}

Stack::Stack(const Stack& s){ //stack copy constructor
	top = NULL;
	Node* temp = s.top;
	Node* n = new Node(temp->data,temp->next); //data  values are stored in Node* n
	top = n;
	temp = temp->next;
	while(temp){ //while temp is not NULL
		Node* m = new Node(temp->data,temp->next); //new node takes the values of the temp node
		n->next = m; //n, which is the previous node, has the next pointer to the address of m
		n = m; //n now points to m
		temp = temp->next;
	}
}

Stack::~Stack(){ //destructor takes on the clear function, which deallocates on its own
	clear();
}

Stack& Stack::operator=(const Stack& s){ //assignment operator
	if(this == &s){ //makes sure chaining is possible
		return *this;
	}
	clear(); //clears the entire node based stack of data and pointers
	top = NULL;
	Node* temp = s.top; //this code is exactly the same as the copy constructor because the implementation is the same
	Node* n = new Node(temp->data,temp->next);
	top = n;
	temp = temp->next;
	while(temp){
		Node* m = new Node(temp->data,temp->next);
		n->next = m;
		n = m;
		temp = temp->next;
	}
	return *this;
}

bool Stack::push(char c){ //push function adds a new node
	if(!full()){ //checks to see that the stack is not full
		Node* temp = new Node(c,NULL);
		temp->next = top; //this can account for an empty stack as well
		top = temp;
		temp = NULL;
		delete temp;
	}
}

bool Stack::pop(char& c){ //pop function removes the top node and retrieves its value
	if(!empty()){ //checks to see that the stack is not empty
		c = top->data;
		top = top->next;
		return true;
	}
	else{
		return false;
	}
}

bool Stack::empty() const {
	if(top == NULL){
		return true;
	}
	else{
		return false;
	}
}

bool Stack::full() const {
	return false;
}

bool Stack::clear(){ //clear function deallocates all nodes and starts the stack as if it were just declared
	if(!empty()){ //checks if the stack is not empty
		Node* temp = top;
		while(temp->next != NULL){ //while the temp pointer is not proceeding NULL
			top = top->next;
			delete temp;
			temp = top;	
		}
		delete top;
		temp = top = NULL;
		return true;
	}
	else{ //if a function does not perform a new operation, then it is seen as false
		return false;
	}
}

bool Stack::operator==(const Stack& s) const { //'equal to' comparison operator
	bool test = true;	
	Node* temp1 = top;
	Node* temp2 = s.top;
	while((temp1 != NULL) && (temp2 != NULL)){ //while both pointers are not NULL
		if(temp1->data != temp2->data){ //if any data members at the same relative order are not equal, the test is false
			test = false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if((temp1 != NULL) || (temp2 != NULL)){ //if one pointer is NULL but the other is not, the test is false
		test = false;
	}
	return test;
}

ostream& operator<<(ostream& output,const Stack& s){ //insertion operator
	if(s.empty()){
		output << endl;
		return output;
	}
	Node* temp = s.top;
	output << '[' << temp->data << ']' << ' '; //first stack member has special formatting
	temp = temp->next;
	while(temp){
		if(temp->next){
			output << temp->data << ' ';
		}
		else{
			output << '|' << temp->data << '|'; //last stack member has special formatting
		}
		temp = temp->next;
	}
	return output;
}