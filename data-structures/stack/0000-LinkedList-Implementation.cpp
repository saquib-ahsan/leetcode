#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
	// constructor
	Node(int x): data(x), next(nullptr) {}
};

class Stack {
private:
	Node *head;

public:
	void Push(int x);
	void Pop();
	int Top();
	bool isEmpty();

	// constructor
	Stack() {
		head = nullptr;
	}
};

void Stack::Push(int x) {
	Node *tmp = new Node(x);
	if(tmp == nullptr) {
		cout << "Stack Overflow" << endl;
		return;
	}

	tmp->next = head;
	head = tmp;
}

void Stack::Pop() {
	if(isEmpty()) return;
	
	Node *tmp = head;
	head = head->next;
	tmp->next = nullptr;
	delete tmp;
}

int Stack::Top() {
	if(isEmpty()) return INT_MIN;
	return head->data;
}

bool Stack::isEmpty() {
	return (head == nullptr);
}


int main() {
	Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);

	cout << s.Top() << endl;

	s.Pop();
	cout << s.Top() << endl;

	return 0;
}
