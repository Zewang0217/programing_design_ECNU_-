#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	// ����һ������Ĭ�ϲ����Ĺ��캯��������ΪĬ�Ϲ��캯��ʹ��
	Node(int value = 0) : data(value), next(nullptr) {} 
};

class Linked_List {
private:
	Node head;

public:
	//���캯��
	Linked_List() {

	}

	//��������
	~Linked_List() {
		Node* current = head.next;
		while (current != nullptr) {
			Node* tmp = current;
			current = current->next;
			delete tmp;
		}
	}

	//��β������Ԫ��
	void add(int value) {
		Node* newNode = new Node(value);
		Node* tmp = &head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}

	//����ѭ���б�
	void makeCircular() {
		Node* tmp = &head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = head.next;
	}

	//�ָ�Ϊ������(����ָ�룩
	void breakCircular() {
		if (head.next == nullptr) return;
		
		Node* current = head.next;
		while (current->next != head.next) {
			current = current->next;
		}
		current->next = nullptr;
	}

	//���м����(��Ŵ�0��ʼ��
	void insert(int value, int position) {
		if (position < 0) return;
		Node* newNode = new Node(value);
		Node* tmp = &head;
		for (int i = 0; i < position && tmp != nullptr; i++) {
			tmp = tmp->next;
		}
		if (tmp == nullptr) {
			//����������
			delete newNode;
			return;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}

	//ɾ���м�Ԫ�أ���Ŵ�0��ʼ��
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

		//ѭ����ֻʣ��һ����
		while (current->next != current) {
			for (int i = 1; i < m; i++) {
				prev = prev->next;
				current = current->next;
			}
			cout << "���ֵ��ˣ� " << current->data << endl;
			prev->next = current->next;
			Node* toDelete = current;
			current = current->next;
			delete toDelete;
		}
		cout << "�����ˣ� " << current->data << endl;
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