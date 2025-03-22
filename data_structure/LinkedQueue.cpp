#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
struct Node {
	T item;
	Node* next;
	Node(T val) : item(val), next(nullptr) {}
};

struct term {
	int coefficient;//ϵ��
	int exponent;//ָ��
	term() :coefficient(0), exponent(0) {}
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
		Node<T>* current = front;
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

	void clear() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	~LinkedQueue() {
		Node<T>* current = front;
		while (current != nullptr) {
			Node<T>* temp = current;
			current = current->next;
			delete temp;
		}
	}

	int frontExponent() {
		if (isEmpty()) return -1;
		return front->item.exponent;
	}

	//�Ⱥ�����
	LinkedQueue<T>& operator=(const LinkedQueue<T>& other) {
		if (this == &other) return *this; // �����Ը�ֵ

		clear(); // ��յ�ǰ����

		Node<T>* current = other.front;
		while (current != nullptr) {
			enqueue(current->item);
			current = current->next;
		}

		size = other.size;
		capacity = other.capacity;
		return *this;
	}

	//�������캯��
	LinkedQueue(const LinkedQueue<T>& other) : front(nullptr), rear(nullptr), size(0),
		capacity(other.capacity) {
		Node<T>* current = other.front;
		while (current != nullptr) {
			enqueue(current->item);
			current = current->next;
		}
	}

	//����ʽ�ӷ�
	LinkedQueue<T>& addPoly(const LinkedQueue<T>& a, const LinkedQueue<T>& b) {
		clear();

		LinkedQueue<term> tempA = a;
		LinkedQueue<term> tempB = b;

		while (!tempA.isEmpty() || !tempB.isEmpty()) {
			if (!tempA.isEmpty() && !tempB.isEmpty()) {
				term termA, termB;
				if (tempA.frontExponent() > tempB.frontExponent()) {
					termA = tempA.frontValue();
					enqueue(termA);
					tempA.dequeue();
				}
				else if (tempA.frontExponent() < tempB.frontExponent()) {
					termB = tempB.frontValue();
					enqueue(termB);
					tempB.dequeue();
				}
				else {
					termA = tempA.frontValue();
					termB = tempB.frontValue();
					int newCoefficient = termA.coefficient + termB.coefficient;
					if (newCoefficient != 0) {
						term addTerm;
						addTerm.coefficient = newCoefficient;
						addTerm.exponent = termA.exponent;
						enqueue(addTerm);
					}

					tempA.dequeue();
					tempB.dequeue();
				}
			}
			else if (!tempA.isEmpty()) { // bΪ��
				enqueue(tempA.frontValue());
				tempA.dequeue();
			}
			else if (!tempB.isEmpty()) { // aΪ��
				enqueue(tempB.frontValue());
				tempB.dequeue();
			}
		}
		return *this;
	}

	LinkedQueue<term>& subPoly(const LinkedQueue<term>& a, const LinkedQueue<term>& b) {
		clear();

		LinkedQueue<term> tempA = a;
		LinkedQueue<term> tempB = b;

		while (!tempA.isEmpty() || !tempB.isEmpty()) {
			if (!tempA.isEmpty() && !tempB.isEmpty()) {
				term termA, termB;
				if (tempA.frontExponent() > tempB.frontExponent()) {
					termA = tempA.frontValue();
					enqueue(termA);
					tempA.dequeue();
				}
				else if (tempA.frontExponent() < tempB.frontExponent()) {
					termB = tempB.frontValue();
					termB.coefficient = -termB.coefficient;
					enqueue(termB);
					tempB.dequeue();
				}
				else {
					termA = tempA.frontValue();
					termB = tempB.frontValue();
					int newCoefficient = termA.coefficient - termB.coefficient;
					if (newCoefficient != 0) {
						term addTerm;
						addTerm.coefficient = newCoefficient;
						addTerm.exponent = termA.exponent;
						enqueue(addTerm);
					}

					tempA.dequeue();
					tempB.dequeue();
				}
			}
			else if (!tempA.isEmpty()) { // bΪ��
				enqueue(tempA.frontValue());
				tempA.dequeue();
			}
			else if (!tempB.isEmpty()) { // aΪ��
				term termB = tempB.frontValue();
				termB.coefficient = -termB.coefficient;
				enqueue(termB);
				tempB.dequeue();
			}
		}
		return *this;
	}

	//����˷�
	LinkedQueue<term>& mulPoly(const LinkedQueue<term>& a, const LinkedQueue<term>& b) {
		clear();

		LinkedQueue<term> tempA = a;
		LinkedQueue<term> tempB = b;
		LinkedQueue<term> result(200);


		//������������ʽ������������
		//����A
		while (!tempA.isEmpty() ) {
			term termA = tempA.frontValue();
			tempA.dequeue();

			LinkedQueue<term> tempB_copy = tempB;

			//����B
			while (!tempB_copy.isEmpty()) {
				term termB = tempB_copy.frontValue();
				tempB_copy.dequeue();
				
				// �������
				term newTerm;
				newTerm.coefficient = termA.coefficient * termB.coefficient;
				newTerm.exponent = termA.exponent + termB.exponent;

				result.enqueue(newTerm);
			}
		}

		/* ���Ӷ�O��K^2��
		//�ų������ظ���
		LinkedQueue<term> mergedRes(50);// ���ڴ���Ѿ��ϲ�����

		// ����result�е�ȫ�����û�кϲ���ֱ�����
		while (!result.isEmpty()) {
			term current = result.frontValue(); // ȡ����ǰ��������
			result.dequeue(); // �Ƴ���ȷ��ֻ����һ��

			LinkedQueue<term> tempQueue; // ���ڴ��δ�ϲ�����
			bool merged = false; // �жϵ�ǰ���Ƿ�ϲ�

			// ����mergedRes��ȡ��existing���
			// ���Ѻϲ���������Ų飬�Ƿ��뵱ǰ��ָ����ͬ
			while (!mergedRes.isEmpty()) {
				term existing = mergedRes.frontValue();
				mergedRes.dequeue();

				// ����ͬ���ϲ�
				if (existing.exponent == current.exponent) {
					existing.coefficient += current.coefficient;
					merged = true;
				}

				// ���´���existing��tempQueue�У�������0��
				if (existing.coefficient != 0) {
					tempQueue.enqueue(existing);
				}
			}

			// currentû���ҵ���ָͬ����ֱ�Ӵ���tempQueue
			if (!merged) {
				tempQueue.enqueue(current);
			}

			// �����Ѻϲ������ʼ��һ�ֵ�current���
			mergedRes = tempQueue;
		}*/

		// ��map�ų���ͬ����
		unordered_map<int, int> termMap;
		while (!result.isEmpty()) {
			term t = result.frontValue();
			result.dequeue();
			termMap[t.exponent] += t.coefficient;
		}

		// �ٽ�map�е�ȫ��Ԫ��ת��vector������
		vector<term> sortedTerms;
		for (auto& p : termMap) {
			if (p.second != 0) {
				term newTerm;
				newTerm.coefficient = p.second;
				newTerm.exponent = p.first;
				sortedTerms.push_back(newTerm);
			}
		}

		sort(sortedTerms.begin(), sortedTerms.end(), [](const term& a, const term& b) {
			return a.exponent > b.exponent;
			});

		// ��vector��Ԫ�طŻض���
		LinkedQueue<term> mergedResult(200);
		for (auto& p : sortedTerms) {
				mergedResult.enqueue(p);
		}

		// ���ض���
		*this = mergedResult;
		return *this;
	}

	// ��ӡ����ʽ
	void polyPrint() {
		Node<term>* current = front;
		bool first = true;

		// �ն���ʽ���ӡ0
		if (isEmpty()) {
			cout << "0" << endl;
			return;
		}

		// ����ÿһ��
		while (current != nullptr) {
			term temp = current->item;

			// ���������ţ���һ�����Ų����
			if (temp.coefficient > 0 && first == false) cout << "+";
			else if (temp.coefficient < 0) cout << "-";
			first = false;

			//�����
			if (temp.exponent == 0) {
				//ָ��Ϊ0��ֻ���ϵ��
				cout << abs(temp.coefficient);
			}
			else if (temp.exponent == 1) { // ָ��Ϊ1
				if (abs(temp.coefficient) != 1) {
					cout << abs(temp.coefficient);
				}
				cout << "X";
			}
			else {
				//ָ������1
				if (abs(temp.coefficient) != 1) {
					cout << abs(temp.coefficient);
				}
				cout << "X^" << temp.exponent;
			}
			
			current = current->next;
		}
		cout << endl;
	}
}; 


int main() {
	char op;
	cin >> op;

	//��ȡ����ʽ1��2
	LinkedQueue<term> poly1(200);
	LinkedQueue<term> poly2(200);

	int coefficient, exponent;
	while (cin >> coefficient >> exponent) {
		if (coefficient == 0 && exponent == 0) break;

		term temp;
		temp.coefficient = coefficient;
		temp.exponent = exponent;
		poly1.enqueue(temp);

	}
	while (cin >> coefficient >> exponent) {
		if (coefficient == 0 && exponent == 0) break;

		term temp;
		temp.coefficient = coefficient;
		temp.exponent = exponent;
		poly2.enqueue(temp);

	}

	LinkedQueue<term> polyRes(200);
	//����ӷ�
	if (op == '+') {
		polyRes.addPoly(poly1, poly2);
	}
	else if (op == '-') {
		polyRes.subPoly(poly1, poly2);
	}
	else if (op == '*') {
		polyRes.mulPoly(poly1, poly2);
	}

	polyRes.polyPrint();

	return 0;
}