#include <iostream>

using namespace std;

class Queue{
        public:
                Queue(int = 10); //done
                Queue(const Queue&);
                ~Queue();
                Queue& operator=(const Queue&);
                bool enqueue(int);
                bool dequeue(int&);
                bool empty() const; //done
                bool full() const; //done
                bool clear(); //done
                bool operator==(const Queue&) const;
                friend ostream& operator<<(ostream&, const Queue&);
        private:
                int max;
                int front;
                int rear;
                int *data;
};

