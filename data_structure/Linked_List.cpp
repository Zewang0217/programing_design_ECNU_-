#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	// 这是一个带有默认参数的构造函数，可作为默认构造函数使用
	Node(int value = 0) : data(value), next(nullptr) {} 
};

class Linked_List {
private:
	Node head;

public:
	//构造函数
	Linked_List() {

	}

	//析构函数
	~Linked_List() {
		Node* current = head.next;
		while (current != nullptr) {
			Node* tmp = current;
			current = current->next;
			delete tmp;
		}
	}

	//在尾部插入元素
	void add(int value) {
		Node* newNode = new Node(value);
		Node* tmp = &head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}

	//创建循环列表
	void makeCircular() {
		Node* tmp = &head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = head.next;
	}

	//恢复为单链表(快慢指针）
	void breakCircular() {
		if (head.next == nullptr) return;
		
		Node* current = head.next;
		while (current->next != head.next) {
			current = current->next;
		}
		current->next = nullptr;
	}

	//在中间插入(序号从0开始）
	void insert(int value, int position) {
		if (position < 0) return;
		Node* newNode = new Node(value);
		Node* tmp = &head;
		for (int i = 0; i < position && tmp != nullptr; i++) {
			tmp = tmp->next;
		}
		if (tmp == nullptr) {
			//超出链表长度
			delete newNode;
			return;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}

	//删除中间元素（序号从0开始）
	void deleteAtPosition(int position) {
		if (position < 0) return;
		Node* tmp = &head;
		for (int i = 0; i < position && tmp != nullptr; i++) {
			tmp = tmp->next;
		}
		Node* toDelete = tmp->next;
		tmp->next = toDelete->next;
		delete toDelete;
	}

	void printList() {
		Node* tmp = head.next;
		while (tmp != nullptr) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void josephus(int m) {
		if (head.next == nullptr) return;
		Node* prev = &head;
		Node* current = head.next;

		while (prev->next != current) {
			prev = prev->next;
		}

		//循环到只剩下一个人
		while (current->next != current) {
			for (int i = 1; i < m; i++) {
				prev = prev->next;
				current = current->next;
			}
			cout << "出局的人： " << current->data << endl;
			prev->next = current->next;
			Node* toDelete = current;
			current = current->next;
			delete toDelete;
		}
		cout << "最后的人： " << current->data << endl;
	}
}; 

int main() {
	int n = 10;
	int m = 3;

	Linked_List list;
	for (int i = 0; i < n; i++) {
		list.add(i);
	}
	list.makeCircular();
	list.josephus(m);
}