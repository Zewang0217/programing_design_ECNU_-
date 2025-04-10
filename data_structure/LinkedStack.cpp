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

	//µ»∫≈÷ÿ‘ÿ
	LinkedStack<T>& operator = (const LinkedStack<T>& other) {
		if (this == &other) {
			return *this;
		}
		clear();

		if (other.topNode != nullptr) {
			Node<T>* copyNode = other.topNode;
			Node<T>* current = nullptr;
			
			while (copyNode != nullptr) {
				Node<T>* newNode = new Node<T>(copyNode->data);
				
				if (topNode == nullptr) {
					topNode = newNode;
					current = newNode;
				}
				else {
					current->next = newNode;
					current = current->next;
				}
				copyNode = copyNode->next;
			}
			stackSize = other.stackSize;
		}

		return *this;
	}

	int exponent() {
		if (empty()) return -1;
		return topNode->data.exponent;
	}

	

 
};

