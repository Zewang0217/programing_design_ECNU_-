#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Error_code { underflow, overflow, rangeError, success };

template <class Node_entry>
struct Node {
    Node_entry entry;
    Node<Node_entry>* next;
    Node<Node_entry>* prev;
    Node(Node_entry item, Node<Node_entry>* link_next = nullptr,
        Node<Node_entry>* link_prev = nullptr)
        : entry(item), next(link_next), prev(link_prev) {
    }
};

template <class List_entry>
class MyList {
private:
    int count;
    mutable int current_position;
    mutable Node<List_entry>* current;
    Node<List_entry>* head;
    Node<List_entry>* tail;

    void set_position(int position) const {
        if (position < 0 || position >= count) return;
        if (current == nullptr || current_position == -1) {
            current = head;
            current_position = 0;
        }

        while (current_position < position) {
            current = current->next;
            current_position++;
        }
        while (current_position > position) {
            current = current->prev;
            current_position--;
        }
    }

public:
    MyList() : count(0), current_position(-1), current(nullptr), head(nullptr), tail(nullptr) {}

    MyList(const MyList<List_entry>& copy) : count(0), current_position(-1), current(nullptr), head(nullptr), tail(nullptr) {
        Node<List_entry>* p = copy.head;
        while (p) {
            insert(count, p->entry);  // 尾插
            p = p->next;
        }
    }


    ~MyList() {
        clear();
    }

    void clear() {
        while (!empty()) {
            List_entry temp;
            remove(0, temp);
        }
    }

    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

    Error_code insert(int position, const List_entry& x) {
        if (position < 0 || position > count) return rangeError;

        Node<List_entry>* new_node = new Node<List_entry>(x);
        if (!new_node) return overflow;

        if (position == 0) {
            new_node->next = head;
            if (head != nullptr) head->prev = new_node;
            head = new_node;
            if (tail == nullptr) tail = new_node;
        }
        else if (position == count) {
            new_node->prev = tail;
            if (tail != nullptr) tail->next = new_node;
            tail = new_node;
            if (head == nullptr) head = new_node;
        }
        else {
            set_position(position);
            Node<List_entry>* after = current;
            Node<List_entry>* before = current->prev;

            new_node->next = after;
            new_node->prev = before;
            if (before) before->next = new_node;
            if (after) after->prev = new_node;

            if (position == 0) head = new_node;
            if (position == count) tail = new_node;
        }

        current = new_node;
        current_position = position;
        count++;
        return success;
    }

    Error_code remove(int position, List_entry& x) {
        if (position < 0 || position >= count) return rangeError;

        Node<List_entry>* to_delete;
        if (position == 0) {
            to_delete = head;
            head = head->next;
            if (head) head->prev = nullptr;
            if (to_delete == tail) tail = nullptr;
        }
        else if (position == count - 1) {
            to_delete = tail;
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            if (to_delete == head) head = nullptr;
        }
        else {
            set_position(position);
            to_delete = current;
            Node<List_entry>* before = to_delete->prev;
            Node<List_entry>* after = to_delete->next;
            if (before) before->next = after;
            if (after) after->prev = before;
        }

        x = to_delete->entry;
        delete to_delete;
        current = nullptr;
        current_position = -1;
        count--;
        return success;
    }

    Error_code replace(int position, const List_entry& x) {
        if (position < 0 || position >= count) return rangeError;
        set_position(position);
        current->entry = x;
        return success;
    }

    void traverse_forward(void (*visit)(List_entry&)) {
        Node<List_entry>* p = head;
        while (p) {
            visit(p->entry);
            p = p->next;
        }
    }

    void traverse_backward(void (*visit)(List_entry&)) {
        Node<List_entry>* p = tail;
        while (p) {
            visit(p->entry);
            p = p->prev;
        }
    }

    Error_code retrieve(int position, List_entry& x) const {
        if (position < 0 || position >= count) return rangeError;  // 确保位置有效

        set_position(position);  // 设置当前位置
        x = current->entry;  // 获取当前节点的值
        return success;  // 返回成功
    }

};

/*
void print(int& x) {
    cout << x << " ";
}
*/

/*
int main() {
    MyList<int> lst;
    int num;

    // 读取输入直到 -1
    while (cin >> num && num != -1) {
        lst.insert(lst.size(), num);
    }

    int m = lst.size();
    vector<int> forward(m, 0), backward(m, 0);

    // 前向最近邻值（正序）
    for (int i = 0; i < m; ++i) {
        int cur;
        lst.retrieve(i, cur);

        for (int j = i - 1; j >= 0; --j) {
            int val;
            lst.retrieve(j, val);
            if (val < cur) {
                forward[i] = val;
                break;
            }
        }
    }

    // 后向最近邻值（逆序）
    for (int i = 0; i < m; ++i) {
        int cur;
        lst.retrieve(i, cur);

        for (int j = i + 1; j < m; ++j) {
            int val;
            lst.retrieve(j, val);
            if (val > cur) {
                backward[i] = val;
                break;
            }
        }
    }

    // 输出前向最近邻值
    for (int i = 0; i < m; ++i) {
        cout << forward[i] << " ";
    }
    cout << endl;

    // 输出后向最近邻值
    for (int i = 0; i < m; ++i) {
        cout << backward[i] << " ";
    }
    cout << endl;

    return 0;
}
*/