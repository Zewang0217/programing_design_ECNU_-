#include <iostream>
using namespace std;

// ���������ö��
enum Error_code { underflow, overflow, rangeError, success };

// ����ڵ�ṹ��
template <class Node_entry>
struct Node {
    Node_entry entry;
    Node<Node_entry>* next;
    Node() : next(nullptr) {}
    Node(Node_entry item, Node<Node_entry>* link = nullptr) : entry(item), next(link) {}
};

// ��ӡԪ�صĺ���
void print(int& x) {
    cout << x << " ";
}

// ����������
template <class List_entry>
class MyList {
private:
    int count;
    mutable int current_position;
    mutable Node<List_entry>* current;
    Node<List_entry>* head;

    // ������������λ��ָ��λ��
    void set_position(int position) const {
        if (position < 0 || position >= count) return;
        if (current_position == -1 || position < current_position) {
            current_position = 0;
            current = head;
        }
        for (; current_position < position; current_position++) {
            current = current->next;
        }
    }

public:
    // ���캯��
    MyList() : count(0), current_position(-1), current(nullptr), head(nullptr) {}

    // ��������
    ~MyList() {
        clear();
    }

    // �������캯��
    MyList(const MyList<List_entry>& copy) : MyList() {
        *this = copy;
    }

    // ��ֵ���������
    MyList& operator=(const MyList<List_entry>& copy) {
        if (this != &copy) {
            clear();
            Node<List_entry>* p = copy.head;
            int pos = 0;
            while (p != nullptr) {
                insert(pos, p->entry);
                p = p->next;
                pos++;
            }
        }
        return *this;
    }

    // ��ȡ�����С
    int size() const {
        return count;
    }

    // �ж������Ƿ�Ϊ��
    bool empty() const {
        return count == 0;
    }

    // �������
    void clear() {
        while (!empty()) {
            List_entry x;
            remove(0, x);
        }
    }

    // ��������
    void traverse(void (*visit)(List_entry&)) {
        Node<List_entry>* p = head;
        while (p != nullptr) {
            visit(p->entry);
            p = p->next;
        }
        cout << endl;
    }

    // ��ĩβ���Ԫ��
    Error_code add(const List_entry& x) {
        return insert(count, x);
    }

    // ��ָ��λ�ò���Ԫ��
    Error_code insert(int position, const List_entry& x) {
        if (position < 0 || position > count) return rangeError;
        Node<List_entry>* new_node = new Node<List_entry>(x);
        if (new_node == nullptr) return overflow;

        if (position == 0) {
            new_node->next = head;
            head = new_node;
        }
        else {
            set_position(position - 1);
            new_node->next = current->next;
            current->next = new_node;
        }
        current = new_node;
        current_position = position;
        count++;
        return success;
    }

    // ɾ��ָ��λ�õ�Ԫ��
    Error_code remove(int position, List_entry& x) {
        if (position < 0 || position >= count) return rangeError;

        Node<List_entry>* toDelete;
        if (position == 0) {
            toDelete = head;
            head = head->next;
            x = toDelete->entry;
            delete toDelete;
            if (current_position == 0) {
                current = head;
            }
            else if (current_position > 0) {
                current_position--;
            }
        }
        else {
            set_position(position - 1);
            toDelete = current->next;
            current->next = toDelete->next;
            x = toDelete->entry;
            delete toDelete;
            if (current_position == position) {
                current_position--;
            }
        }
        count--;
        return success;
    }

    // ��ȡָ��λ�õ�Ԫ��
    Error_code retrieve(int position, List_entry& x) const {
        if (position < 0 || position >= count) return rangeError;
        set_position(position);
        x = current->entry;
        return success;
    }

    // �滻ָ��λ�õ�Ԫ��
    Error_code replace(int position, const List_entry& x) {
        if (position < 0 || position >= count) return rangeError;
        set_position(position);
        current->entry = x;
        return success;
    }

    // �鲢����������
    void mergesort() {
        int depth = 0;
        head = recursiveMergesort(head, depth);
        current_position = -1; // ���õ�ǰλ��
    }

private:
    // �ݹ�鲢����
    Node<List_entry>* recursiveMergesort(Node<List_entry>* subList, int& depth) {
        if (subList == nullptr || subList->next == nullptr) {
            return subList;
        }

        // �ָ�����
        Node<List_entry>* secondHalf = divide_from(subList);

        // �ݹ�����
        depth++;
        subList = recursiveMergesort(subList, depth);
        secondHalf = recursiveMergesort(secondHalf, depth);
        depth--;

        // ���Ϊ0ʱ��ӡ
        if (depth == 0) {
            printList(subList);
            printList(secondHalf);
        }

        // �ϲ�������������
        return merge(subList, secondHalf);
    }

    // �ָ���������ָ�뷨��
    Node<List_entry>* divide_from(Node<List_entry>* subList) {
        Node<List_entry>* position, * midpoint, * second_half;
        // �Ȱ��м���ʼ��Ϊ��ͷ
        if ((midpoint = subList) == NULL) return NULL; // ��
        // ����ָ���ȡ�м�λ��
        position = midpoint->next;
        while (position != NULL) {
            position = position->next; // ����position,�ж��Ƿ�ͷ
            if (position != NULL) {
                midpoint = midpoint->next;
                position = position->next;
            }
        }
        // �ҵ��м�λ�ú󣬸�ֵ��second_half
        second_half = midpoint->next;
        //�Ͽ��б�
        midpoint->next = nullptr;
        return second_half;
    }

    // �ϲ�������������
    Node<List_entry>* merge(Node<List_entry>* first, Node<List_entry>* second) {
        Node<List_entry> dummy; // �ƽڵ�
        Node<List_entry>* tail = &dummy;

        while (first != nullptr && second != nullptr) {
            if (first->entry <= second->entry) {
                tail->next = first;
                first = first->next;
            }
            else {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }

        // ����ʣ�ಿ��
        if (first != nullptr) {
            tail->next = first;
        }
        else {
            tail->next = second;
        }

        return dummy.next;
    }

    // ��ӡ����
    void printList(Node<List_entry>* list) {
        Node<List_entry>* p = list;
        while (p != nullptr) {
            cout << p->entry << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    MyList<int> list;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.add(x);
    }

    // ִ�й鲢����
    list.mergesort();

    // ������ս��
    list.traverse(print);

    return 0;
}