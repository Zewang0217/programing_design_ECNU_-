// ********** Specification of struct Node **********
typedef struct Node
{
	int value;
	struct Node* next;

}NODE;
/*/////////////////////////////////////////////////////*/
NODE* EraseNodes(NODE* h, int v)
{ //TODO: your definition
	if (h == nullptr) return h;

	// �����һ���ڵ�����
	while (h->value == v) {
		Node* temp = h;
		h = h->next;
		delete temp;
		if (h == nullptr) return h;
	}

	// ���ֻ��һ���ڵ�
	if (h->next == nullptr) return h;

	Node* current = h->next;
	Node* prev = h;
	while (current != nullptr) {
		// ����ڶ����ڵ�Ҫɾ�����������

		if (current->value == v) {
			prev->next = current->next;
			delete current;
			current = prev->next;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	return h;
}
/*/////////////////////////////////////////////////////*/
/***************************************************************/
/*                                                             */
/*  DON'T MODIFY below code anyway!                             */
/*                                                             */
/***************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

//********** Specification of EraseNodes(head,v) **********
NODE* EraseNodes(NODE* h, int v);
/* PreCondition:
h is a head pointer of a linked-list, v is an integer
PostCondition:
return the head pointer of a linked-list that has not v in its nodes
*/
void solve()
{
	int i, n, v; NODE* head = 0, * p = nullptr, * tail = nullptr;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		p = (NODE*)malloc(sizeof(NODE));
		cin >> p->value; p->next = 0;
		if (head == 0) head = tail = p; else { tail->next = p; tail = p; }
	}
	cin >> v;
	//********** EraseNodes is called here **********
	head = EraseNodes(head, v);
	//****************************************
	while (head)
	{
		p = head; head = head->next;
		cout << p->value;
		if (head) cout << " ";
		free(p);
	}
	cout << endl;
}
/*
int main()
{
	int i, t;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cout << "case #" << i << ":" << endl;
		solve();
	}
	return 0;
}
*/