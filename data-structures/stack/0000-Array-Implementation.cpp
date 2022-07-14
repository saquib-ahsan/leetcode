#include <bits/stdc++.h>
using namespace std;

const int N = 101;

class Stack {
private:
	int arr[N];
	int top;

public:
	void Push(int x);
	void Pop();
	int Top();
	bool isEmpty();

	// constructor
	Stack() {
		top = -1;
	}
};

void Stack::Push(int x) {
	if(top == N-1) return;

	++top;
	arr[top] = x;
}

void Stack::Pop() {
	if(isEmpty()) return;
	--top;
}

int Stack::Top() {
	if(isEmpty()) return INT_MIN;
	return arr[top];
}

bool Stack::isEmpty() {
	return (top == -1);
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

// P.S.: We can increase the array size in case we hit an overflow by using dynamic array. Check if it is an overflow, create
// a new array (generally doubled size of previous one) and copy the data from older array.
// But it would take O(N) time complexity. In other words, in worst case, time complexity = O(N)
// Overall average time complexity = O(1) (constant)
