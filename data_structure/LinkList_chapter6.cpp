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
};

// ��ӡԪ�صĺ���
//void print(int& x) {
//    cout << x << " ";
//}

/*
int main() {
    MyList<int> list;
    int num;

    // ��1�У���ʼ����
    while (cin >> num && num != -1) {
        list.insert(list.size(), num);
    }

    // ��2�У��������
    int a, b;
    while (cin >> a >> b && !(a == -1 && b == -1)) {
        list.insert(a, b);
    }

    // ��3�У�ɾ������
    int c;
    while (cin >> c && c != -1) {
        int temp;
        list.remove(c, temp);
    }

    // ��4�У��滻����
    int d, e;
    while (cin >> d >> e && !(d == -1 && e == -1)) {
        list.replace(d, e);
    }

    // �����������
    list.traverse(print);
    cout << endl;

    return 0;
}
*/