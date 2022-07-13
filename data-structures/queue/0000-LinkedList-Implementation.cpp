#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
	// constructor
	Node(int x): data(x), next(nullptr) {}
};

class Queue {
private:
	Node *head, *tail;

public:
	// methods
	void enqueue(int x);
	int dequeue();
	bool isempty();
	int frontval();

	// constructors
	Queue() {
		head = tail = nullptr;
	}
};

void Queue::enqueue(int x) {
	Node *tmp = new Node(x);
	if(tmp == nullptr) return;	// failed to allocate

	if(isempty()) {
		head = tail = tmp;
	} else {
		tail->next = tmp;
		tail = tmp;
	}
}

int Queue::dequeue() {
	if(isempty()) return INT_MIN;

	Node *tmp = head;
	if(head == tail) {
		head = tail = nullptr;
	} else {
		head = head->next;
		tmp->next = nullptr;
	}
	return head->data;
}

bool Queue::isempty() {
	if(!head && !tail) return true;
	return false;
}

int Queue::frontval() {
	if(isempty()) return INT_MIN;
	return head->data;
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
