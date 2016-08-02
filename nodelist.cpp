#include "nlist.h"
using namespace std;

/*Node Constructor*/

Node::Node(int value, Node* follow){
	data = value;
	next = follow;
}

/*Constructors*/

ListNode::ListNode(int ignore){
	head = cursor = NULL;
}

/*ListNode::ListNode(const ListNode& listnode){
	Node* temp = listnode.head;
	Node* N = new Node(temp->data,NULL);
	head = N;
	Node* M;
	while(temp->next != NULL){
		temp = temp->next;
		M = new Node(temp->data,NULL);
		N->next = M;
		N = M;
		if(temp == listnode.cursor){
			cursor = N;
		}

	}
	temp = M = N = NULL;
}*/

ListNode::ListNode(const ListNode& l){
	if(l.head == NULL){
		head = cursor = NULL;
	}
	else{
		Node* tmp1,tmp2;
		head = new Node(l.head->data,NULL);
		tmp1 = head;
		tmp2 = l.head;
		if(tmp2 == l.cursor){
			cursor = tmp1;
		}
		tmp2 = tmp2->next;
		while(tmp2 != NULL){
			tmp1->next = new Node(tmp2->data,NULL);
			if(tmp2 == l.cursor){
				cursor = tmp1;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
	tmp1 = tmp2 = NULL;
}

ListNode::~ListNode(){
	clear();
}

/*Edit*/

bool ListNode::insertAfter(int value){
	if(isFull()){
		return false;
	}
	else{
		if(isEmpty()){
			Node* N = new Node(value,NULL);
			head = cursor = N;
			N = NULL;
		}
		else{
			Node* N = new Node(value,cursor->next);
			cursor->next = N;
			cursor = N;
			N = NULL;
		}
		return true;
	}
}

bool ListNode::insertBefore(int value){
	if(isFull()){
		return false;
	}
	else{
		if(isEmpty()){
			Node* N = new Node(value,NULL);
			head = cursor = N;
			N = NULL;
		}
		else{
			Node* N = new Node(cursor->data,cursor->next);
			cursor->data = value;
			cursor->next = N;
			N = NULL;
		}
		return true;
	}
}

bool ListNode::get(int& value) const{
	if(isEmpty()){
		return false;
	}
	else{
		value = cursor->data;
		return true;
	}
}

bool ListNode::remove(int& value){
	if(isEmpty()){
		return false;
	}
	else{
		value = cursor->data;
		Node* temp = head;
		while(temp->next != cursor){
			temp = temp->next;
		}
		temp->next = cursor->next;
		delete cursor;
		if(temp->next != NULL){
			cursor = temp->next;
		}
		else{
			cursor = temp;
		}
		temp = NULL;
		return true;
	}
}

void ListNode::clear(){
	if(!isEmpty()){
		Node* temp;
		while(head->next != NULL){
			temp = head;
			head = head->next;
			delete temp;
		}
		delete head;
		head = cursor = temp = NULL;
	}
}

/*Move Cursor*/

bool ListNode::goToBeginning(){
	if(isEmpty() || (head == cursor)){
		return false;
	}
	else{
		cursor = head;
		return true;
	}
}

bool ListNode::goToEnd(){
	if(isEmpty() || (cursor->next == NULL)){
		return false;
	}
	else{
		while(cursor->next != NULL){
			cursor = cursor->next;
		}
		return true;
	}
}

bool ListNode::goToNext(){
	if(isEmpty() || (cursor->next == NULL)){
		return false;
	}
	else{
		cursor = cursor->next;
		return true;
	}
}

bool ListNode::goToPrior(){
	if(isEmpty() || (head == cursor)){
		return false;
	}
	else{
		Node* temp = head;
		while(temp->next != cursor){
			temp = temp->next;
		}
		cursor = temp;
		temp = NULL;
		return true;
	}
}

/*Conditions*/

bool ListNode::isEmpty() const{
	if(head != NULL){
		return false;
	}
	else{
		return true;
	}
}

bool ListNode::isFull() const{
	return false;
}

/*Assignment Operator*/

ListNode& ListNode::operator=(const ListNode& listnode){
	if(this == &listnode){
		return *this;
	}
	Node* temp = listnode.head;
	Node* N = new Node(temp->data,NULL);
	head = N;
	Node* M;
	while(temp->next != NULL){
		temp = temp->next;
		M = new Node(temp->data,NULL);
		N->next = M;
		N = M;
		if(temp == listnode.cursor){
			cursor = N;
		}

	}
	temp = M = N = NULL;
	return *this;
}

/*Insertion Operator*/

ostream& operator<<(ostream& os,const ListNode& listnode){
	if(!listnode.isEmpty()){
		Node* temp = listnode.head;
		while(temp != NULL){
			os << temp->data << ' ';
			temp = temp->next;
		}
	}
	os << endl;
	return os;
}
