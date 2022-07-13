#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

class Queue {
private:
	int arr[N];
	int front, rear;
public:
	// methods
	void enqueue(int x);
	int dequeue();
	bool isempty();
	int frontval();

	// constructors
	Queue() {
		for(int i = 0; i < N; ++i) arr[i] = 0;
		front = rear = -1;
	}
};

void Queue::enqueue(int x) {
	if((rear + 1)%N == front) return;

	if(isempty()) {
		front = rear = 0;
	} else {
		rear = (rear + 1)%N;
	}
	arr[rear] = x;
}

int Queue::dequeue() {
	if(isempty()) return INT_MIN;

	int x = arr[front];
	if(front == rear) {
		front = rear = -1;
	} else {
		front = (front + 1)%N;
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
