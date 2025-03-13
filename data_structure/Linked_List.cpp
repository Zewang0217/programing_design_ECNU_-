#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	// 带有默认参数的构造函数，可作为默认构造函数使用
	Node(int value = 0) : data(value), next(nullptr) {} 
};

class Linked_List {
private:
	Node head;

public:
	//构造函数
	Linked_List() : head(0){
		head.next = nullptr;
	}

	//析构函数
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

	//在尾部插入元素
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

	//创建循环列表
	void makeCircular() {
		if (head.next == nullptr) return;

		Node* tmp = head.next;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = head.next;
	}

	//恢复为单链表
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

	//按值删除
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

	//删除中间元素（序号从0开始）
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


	//约瑟夫问题
	void josephus(int m) {
		if (head.next == nullptr) return;

		makeCircular();

		Node* prev = head.next;
		while (prev->next != head.next) {
			prev = prev->next;
		}

		Node* current = head.next;

		//循环到只剩下一个人
		while (current->next != current) {
			for (int i = 1; i < m; i++) {
				prev = current;
				current = current->next;
			}
			//cout << "出局的人： " << current->data << endl;
			prev->next = current->next;
			delete current;
			current = prev->next;
		}
		cout << current->data << endl;
		delete current;
	}

	//逆转链表 (重难点）
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