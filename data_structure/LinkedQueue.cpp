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
	int coefficient;//系数
	int exponent;//指数
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

	//等号重载
	LinkedQueue<T>& operator=(const LinkedQueue<T>& other) {
		if (this == &other) return *this; // 避免自赋值

		clear(); // 清空当前队列

		Node<T>* current = other.front;
		while (current != nullptr) {
			enqueue(current->item);
			current = current->next;
		}

		size = other.size;
		capacity = other.capacity;
		return *this;
	}

	//拷贝构造函数
	LinkedQueue(const LinkedQueue<T>& other) : front(nullptr), rear(nullptr), size(0),
		capacity(other.capacity) {
		Node<T>* current = other.front;
		while (current != nullptr) {
			enqueue(current->item);
			current = current->next;
		}
	}

	//多项式加法
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
			else if (!tempA.isEmpty()) { // b为空
				enqueue(tempA.frontValue());
				tempA.dequeue();
			}
			else if (!tempB.isEmpty()) { // a为空
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
			else if (!tempA.isEmpty()) { // b为空
				enqueue(tempA.frontValue());
				tempA.dequeue();
			}
			else if (!tempB.isEmpty()) { // a为空
				term termB = tempB.frontValue();
				termB.coefficient = -termB.coefficient;
				enqueue(termB);
				tempB.dequeue();
			}
		}
		return *this;
	}

	//处理乘法
	LinkedQueue<term>& mulPoly(const LinkedQueue<term>& a, const LinkedQueue<term>& b) {
		clear();

		LinkedQueue<term> tempA = a;
		LinkedQueue<term> tempB = b;
		LinkedQueue<term> result(200);


		//遍历两个多项式的所有项，并相乘
		//遍历A
		while (!tempA.isEmpty() ) {
			term termA = tempA.frontValue();
			tempA.dequeue();

			LinkedQueue<term> tempB_copy = tempB;

			//遍历B
			while (!tempB_copy.isEmpty()) {
				term termB = tempB_copy.frontValue();
				tempB_copy.dequeue();
				
				// 相乘运算
				term newTerm;
				newTerm.coefficient = termA.coefficient * termB.coefficient;
				newTerm.exponent = termA.exponent + termB.exponent;

				result.enqueue(newTerm);
			}
		}

		/* 复杂度O（K^2）
		//排除所有重复项
		LinkedQueue<term> mergedRes(50);// 用于存放已经合并的项

		// 遍历result中的全部项，若没有合并，直接入队
		while (!result.isEmpty()) {
			term current = result.frontValue(); // 取出当前项（处理对象）
			result.dequeue(); // 移除，确保只处理一次

			LinkedQueue<term> tempQueue; // 用于存放未合并的项
			bool merged = false; // 判断当前项是否合并

			// 遍历mergedRes，取出existing检查
			// 对已合并的项逐个排查，是否与当前项指数相同
			while (!mergedRes.isEmpty()) {
				term existing = mergedRes.frontValue();
				mergedRes.dequeue();

				// 若相同，合并
				if (existing.exponent == current.exponent) {
					existing.coefficient += current.coefficient;
					merged = true;
				}

				// 重新存入existing到tempQueue中，不存入0项
				if (existing.coefficient != 0) {
					tempQueue.enqueue(existing);
				}
			}

			// current没有找到相同指数，直接存入tempQueue
			if (!merged) {
				tempQueue.enqueue(current);
			}

			// 更新已合并的项，开始新一轮的current检查
			mergedRes = tempQueue;
		}*/

		// 用map排除相同的项
		unordered_map<int, int> termMap;
		while (!result.isEmpty()) {
			term t = result.frontValue();
			result.dequeue();
			termMap[t.exponent] += t.coefficient;
		}

		// 再将map中的全部元素转到vector中排序
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

		// 将vector中元素放回队列
		LinkedQueue<term> mergedResult(200);
		for (auto& p : sortedTerms) {
				mergedResult.enqueue(p);
		}

		// 返回队列
		*this = mergedResult;
		return *this;
	}

	// 打印多项式
	void polyPrint() {
		Node<term>* current = front;
		bool first = true;

		// 空多项式则打印0
		if (isEmpty()) {
			cout << "0" << endl;
			return;
		}

		// 遍历每一项
		while (current != nullptr) {
			term temp = current->item;

			// 处理正负号，第一个正号不输出
			if (temp.coefficient > 0 && first == false) cout << "+";
			else if (temp.coefficient < 0) cout << "-";
			first = false;

			//输出项
			if (temp.exponent == 0) {
				//指数为0，只输出系数
				cout << abs(temp.coefficient);
			}
			else if (temp.exponent == 1) { // 指数为1
				if (abs(temp.coefficient) != 1) {
					cout << abs(temp.coefficient);
				}
				cout << "X";
			}
			else {
				//指数大于1
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

	//读取多项式1、2
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
	//处理加法
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