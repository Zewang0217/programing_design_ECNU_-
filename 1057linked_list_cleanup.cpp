/*
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// ��������ڵ�ṹ
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ��������
ListNode* createLinkedList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}

// ɾ���������ڵڶ��������г��ֹ��Ľڵ�
ListNode* removeNodes(ListNode* head1, ListNode* head2) {
    unordered_set<int> valuesToRemove;
    ListNode* current = head2;
    // ���ڶ��������е�ֵ���뼯��
    while (current) {
        valuesToRemove.insert(current->val);
        current = current->next;
    }

    ListNode dummy(0);
    dummy.next = head1;
    ListNode* prev = &dummy;
    current = head1;
    // ������һ������ɾ�����������Ľڵ�
    while (current) {
        if (valuesToRemove.count(current->val)) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return dummy.next;
}

// ��ӡ����
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    bool first = true;
    while (current) {
        if (!first) {
            cout << " ";
        }
        cout << current->val;
        first = false;
        current = current->next;
    }
    cout << endl;
}

// �ͷ������ڴ�
void freeLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int T;
    cin >> T;
    for (int caseNum = 0; caseNum < T; ++caseNum) {
        int m, n;
        cin >> m >> n;
        vector<int> list1(m), list2(n);
        for (int i = 0; i < m; ++i) {
            cin >> list1[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> list2[i];
        }

        ListNode* head1 = createLinkedList(list1);
        ListNode* head2 = createLinkedList(list2);

        ListNode* result = removeNodes(head1, head2);

        cout << "case #" << caseNum << ":" << endl;
        printLinkedList(result);

        freeLinkedList(result);
        freeLinkedList(head2);
    }
    return 0;
}
*/