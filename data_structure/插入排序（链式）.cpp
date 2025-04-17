#include <iostream>
using namespace std;

// 定义错误码枚举
enum Error_code { underflow, overflow, rangeError, success };

// 定义节点结构体
template <class Node_entry>
struct Node {
    Node_entry entry;
    Node<Node_entry>* next;
    Node() : next(nullptr) {}
    Node(Node_entry item, Node<Node_entry>* link = nullptr) : entry(item), next(link) {}
};

// 定义链表类
template <class List_entry>
class MyList {
private:
    int count;
    mutable int current_position;
    mutable Node<List_entry>* current;
    Node<List_entry>* head;

    // 辅助函数，定位到指定位置
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
    // 构造函数
    MyList() : count(0), current_position(-1), current(nullptr), head(nullptr) {}

    // 析构函数
    ~MyList() {
        clear();
    }

    // 拷贝构造函数
    MyList(const MyList<List_entry>& copy) : MyList() {
        *this = copy;
    }

    // 赋值运算符重载
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

    // 获取链表大小
    int size() const {
        return count;
    }

    // 判断链表是否为空
    bool empty() const {
        return count == 0;
    }

    // 清空链表
    void clear() {
        while (!empty()) {
            List_entry x;
            remove(0, x);
        }
    }

    // 遍历链表
    void traverse(void (*visit)(List_entry&)) {
        Node<List_entry>* p = head;
        while (p != nullptr) {
            visit(p->entry);
            p = p->next;
        }
    }

    // 在末尾添加元素
    Error_code add(const List_entry& x) {
        return insert(count, x);
    }

    // 在指定位置插入元素
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

    // 删除指定位置的元素
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

    // 获取指定位置的元素
    Error_code retrieve(int position, List_entry& x) const {
        if (position < 0 || position >= count) return rangeError;
        set_position(position);
        x = current->entry;
        return success;
    }

    // 替换指定位置的元素
    Error_code replace(int position, const List_entry& x) {
        if (position < 0 || position >= count) return rangeError;
        set_position(position);
        current->entry = x;
        return success;
    }

    Error_code exchange(int pos1, int pos2) {
        List_entry temp1 = retrieve(pos1);
        List_entry temp2 = retrieve(pos2);
        replace(pos1, temp2);
        replace(pos2, temp1);
        return success;
    }
};

// 打印元素的函数
void print(int& x) {
    cout << x << " ";
}

int main() {
    int n;
    cin >> n;
    MyList<int> list;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.add(x);
    }

    int ordered = 1;
    for (; ordered < n; ordered++) {
        int current;
        list.retrieve(ordered, current);
        int j = ordered - 1;

        while (j >= 0) {
            int toComp;
            list.retrieve(j, toComp);
            if (toComp > current) {
                list.replace(j + 1, toComp);
                j--;
            }
            else {
                break;
            }
        }
        list.replace(j + 1, current);

        if (ordered == n / 2 - 1) {
            list.traverse(print);
            cout << endl;
        }
    }
    list.traverse(print);
}