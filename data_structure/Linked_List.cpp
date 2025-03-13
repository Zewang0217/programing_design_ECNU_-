#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	// ����Ĭ�ϲ����Ĺ��캯��������ΪĬ�Ϲ��캯��ʹ��
	Node(int value = 0) : data(value), next(nullptr) {} 
};

class Linked_List {
private:
	Node head;

public:
	//���캯��
	Linked_List() : head(0){
		head.next = nullptr;
	}

	//��������
	~Linked_List() {
		if (head.next == nullptr) return;
		Node* current = head.next;
		while (current != nullptr) {
			Node* tmp = current;
			current = current->next;
			delete tmp;
		}
	}

	bool empty() {
		return head.next == nullptr;
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

	int deleteLast() {
		if (head.next == nullptr) return 0;

		if (head.next->next == nullptr) {
			int data = head.next->data;
			delete head.next;
			head.next = nullptr;
			return data;
		}

		Node* current = head.next;
		while (current->next->next != nullptr) {
			current = current->next;
		}

		Node* LastNode = current;
		current = current->next;
		int data = current->data;

		delete current;
		LastNode->next = nullptr;
		return data;
	}

	//����ѭ���б�
	void makeCircular() {
		if (head.next == nullptr) return;

		Node* tmp = head.next;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = head.next;
	}

	//�ָ�Ϊ������
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

	vector<int> insertAfterValue(int after, int value) {
		vector<int> positions;
		int i = 0;
		Node* tmp = &head;

		while (tmp != nullptr) {
			if (tmp->data == after) {
				Node* newNode = new Node(value);
				newNode->next = tmp->next;
				tmp->next = newNode;
				positions.push_back(i);
				tmp = newNode->next;
			}
			else {
				tmp = tmp->next;
			}
			i++;
		}
		return positions;
	}

	//��ֵɾ��
	void deleteByValue(int value) {
		while (head.next != nullptr && head.next->data == value) {
			Node* toDelete = head.next;
			head.next = head.next->next;
			delete toDelete;
		}

		Node* prev = &head;

		while (prev->next != nullptr) {
			if (prev->next->data == value) {
				Node* toDelete = prev->next;
				prev->next = toDelete->next;
				delete toDelete;
			}
			else {
				prev = prev->next;
			}
		}
	}

	//ɾ���м�Ԫ�أ���Ŵ�0��ʼ��
	void deleteAtPosition(int position) {
		if (head.next == nullptr) return;
		
		if (position == 0) {
			Node* toDelete = head.next;
			head.next = head.next->next;
			delete toDelete;
			return;
		}

		if (position < 0) return;
		Node* tmp = &head;
		for (int i = 0; i < position && tmp != nullptr; i++) {
			tmp = tmp->next;
		}

		if (tmp == nullptr || tmp->next == nullptr) return;

		Node* toDelete = tmp->next;
		tmp->next = toDelete->next;
		delete toDelete;
	}

	void printList() {
		Node* tmp = head.next;
		bool first = true;
		while (tmp != nullptr) {
			if (!first) cout << " ";
			cout << tmp->data;
			first = false;
			tmp = tmp->next;
		}
		cout << endl;
	}


	//Լɪ������
	void josephus(int m) {
		if (head.next == nullptr) return;

		makeCircular();

		Node* prev = head.next;
		while (prev->next != head.next) {
			prev = prev->next;
		}

		Node* current = head.next;

		//ѭ����ֻʣ��һ����
		while (current->next != current) {
			for (int i = 1; i < m; i++) {
				prev = current;
				current = current->next;
			}
			//cout << "���ֵ��ˣ� " << current->data << endl;
			prev->next = current->next;
			delete current;
			current = prev->next;
		}
		cout << current->data << endl;
		delete current;
	}

	//��ת���� (���ѵ㣩
	void reverseList() {	
		if (head.next == nullptr || head.next->next == nullptr) return;

		Node* prev = nullptr;
		Node* current = head.next;
		Node* next = nullptr;

		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		head.next = prev;
	}

	void deleteRepeateElement() {
		unordered_set<int> seen;

		Node* prev = &head;
		Node* current = head.next;

		while (current != nullptr) {
			if (seen.find(current->data) != seen.end()) {
				prev->next = current->next;
				delete current;
				current = prev->next;
			}
			else {
				seen.insert(current->data);
				prev = current;
				current = current->next;
			}
		}
	}
};

int main() {
	int n;
	cin >> n;

	Linked_List list;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		list.add(a);
	}

	list.deleteRepeateElement();
	list.printList();
}