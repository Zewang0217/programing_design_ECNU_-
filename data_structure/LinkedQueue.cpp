#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T item;
	Node* next;
	Node(T val) : item(val), next(nullptr) {}
};

template <typename T>
class LinkedQueue {
private:
	Node<T>* front;
	Node<T>* rear;
	int size;
	int capacity;

public:
	LinkedQueue(int cap) : front(nullptr), rear(nullptr), size(0), capacity(cap) {}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

	void enqueue(T value) {
		if (isFull()) {
			return;
		}
		Node<T>* newNode = new Node<T>(value);
		if (isEmpty()) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}

	void dequeue() {
		if (isEmpty()) {
			return;
		}
		Node* current = front;
		front = front->next;
		delete current;
		size--;
	}

	T frontValue() {
		if (isEmpty()) {
			throw out_of_range("Queue is empty");
		}
		return front->item;
	}

	void printQueue() {
		Node<T>* current = front;
		while (current != nullptr) {
			cout << current->item << " ";
			current = current->next;
		}
		cout << endl;
	}

	~LinkedQueue() {
		Node<T>* current = front;
		while (current != nullptr) {
			Node<T>* temp = current;
			current = current->next;
			delete temp;
		}
	}
};


int main() {
	LinkedQueue<int> queue(100);
	int num;
	while (cin >> num && num != -1) {
		queue.enqueue(num);
	}
	queue.printQueue();
	return 0;
}