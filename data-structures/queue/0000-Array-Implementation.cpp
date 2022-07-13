#include <bits/stdc++.h>
using namespace std;

const int mxN = 1000;

class Queue {
private:
	int arr[mxN];
	int front, rear;
public:
	// methods
	void enqueue(int x);
	int dequeue();
	bool isempty();
	int frontval();


	// constructors
	Queue() {
		for(int i = 0; i < mxN; ++i) arr[i] = 0;
		front = rear = -1;
	}
};

void Queue::enqueue(int x) {
	if(rear == mxN-1) return;

	if(isempty()) {
		front = rear = 0;
	} else {
		++rear;
	}
	arr[rear] = x;
}

int Queue::dequeue() {
	if(isempty()) return INT_MIN;

	int x = arr[front];
	if(front == rear) {
		front = rear = -1;
	} else {
		++front;
	}
	return x;
}

bool Queue::isempty() {
	if(front == -1 && rear == -1) return true;
	return false;
}

int Queue::frontval() {
	if(isempty()) return INT_MIN;
	return arr[front];
}


int main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	cout << q.frontval() << endl;

	q.dequeue();
	cout << q.frontval() << endl;

	return 0;
}
