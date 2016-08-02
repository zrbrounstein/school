#include <iostream>

using namespace std;

class Queue;

class Node{
	private:
		Node(int, Node*); //done
		int data;
		Node* next;
		friend class Queue;
		friend ostream& operator<<(ostream&, const Queue&);
};

class Queue{
	public:
		Queue(int = 0); //done
		Queue(const Queue&);
  		~Queue();
		Queue& operator=(const Queue&);
		bool enqueue(int); //done
		bool dequeue(int&); //done
		bool empty() const; //done
		bool full() const; //done
		bool clear(); //done
		bool operator==(const Queue&) const;
		friend ostream& operator<<(ostream&, const Queue&);
	private:
		Node* front;
		Node* rear;
};