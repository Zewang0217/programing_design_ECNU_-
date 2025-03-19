#include <iostream> 
using namespace std;

template <typename T>
struct Node {
	int data;
	Node* next;
	Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedStack {
private:
	Node<T>* topNode;
	int stackSize;

public:
	LinkedStack() : topNode(nullptr), stackSize(0) {}

	void push(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = topNode;
		topNode = newNode;
		stackSize++;
	}

	void pop() {
		if (topNode != nullptr) {
			Node<T>* temp = topNode;
			topNode = topNode->next;
			delete temp;
			stackSize--;
		}
		else {
			throw out_of_range("Stack is empty");
		}
	}

	T top() {
		if (topNode != nullptr) {
			return topNode->data;
		}
		else {
			throw out_of_range("Stack is empty");
		}
	}

	int size() {
		return stackSize;
	}

	bool empty() {
		return stackSize == 0;
	}

	void clear() {
		while (topNode != nullptr) {
			pop();
		}
	}

	~LinkedStack() {
		clear();
	}
 
};

/*
int main() {
	LinkedStack<int> stack;
	int num;
	cin >> num;
	while (num != -1) {
		stack.push(num);
		cin >> num;
	}
	while (!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	return 0;
}
*/