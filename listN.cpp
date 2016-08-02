#include "listnode.h"
using namespace std;

/*Node Constructor*/

Node::Node(int value, Node* follow){
	data = value;
	next = follow;
}

/*ListNode Constructors*/

ListNode::ListNode(int ignore){
	head = cursor = NULL;
}

ListNode::ListNode(const ListNode& listnode){
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
}

ListNode::~ListNode(){
	clear();
}

/*Edit ListNode*/

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
			cursor = cursor->next;
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
		cursor = temp->next;
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

/*ListNode Movements*/

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
		cursor = temp->next;
		temp = NULL;
		return true;
	}
}

/*ListNode Conditions*/

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

/*ListNode Assignment Operator*/

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

/*ListNode Insertion Operator*/

ostream& operator<<(ostream& os,const ListNode& listnode){
	if(listnode.isEmpty()){
		os << endl;
	}
	else{
		Node* temp = listnode.head;
		while(temp != listnode.cursor){
			os << temp->data << ' ';
			temp = temp->next;
		}
		os << '[' << temp->data << ']' << ' ';
		temp = temp->next;
		while(temp != NULL){
			os << temp->data << ' ';
			temp = temp->next;
		}
	}
	return os;
}