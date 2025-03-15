/*
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 创建链表
ListNode* createLinkedList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}

// 删除链表中在第二个链表中出现过的节点
ListNode* removeNodes(ListNode* head1, ListNode* head2) {
    unordered_set<int> valuesToRemove;
    ListNode* current = head2;
    // 将第二个链表中的值存入集合
    while (current) {
        valuesToRemove.insert(current->val);
        current = current->next;
    }

    ListNode dummy(0);
    dummy.next = head1;
    ListNode* prev = &dummy;
    current = head1;
    // 遍历第一个链表，删除符合条件的节点
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

// 打印链表
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

// 释放链表内存
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