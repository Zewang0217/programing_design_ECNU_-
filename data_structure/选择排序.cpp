#include<iostream>
#include <string>
#include <sstream>
using namespace std;
enum Error_code { underflow, overflow, range_Error, success };
const int max_list = 1000;

template <typename List_entry>
class List
{
public:
    List() {
        count = 0;
    }
    int size()const {
        return count;
    }
    bool full()const {
        return count == max_list;
    }
    bool empty()const {
        return count == 0;
    }
    void clear() {
        count = 0;
    }
    Error_code insert(int position, const List_entry& x) {
        if (full()) return overflow;
        if (position < 0 || position > max_list) return range_Error;
        for (int i = count - 1; i >= position; i--) {
            entry[i + 1] = entry[i];
        }
        entry[position] = x;
        count++;
        return success;
    }

    Error_code remove(int position, List_entry& x) {
        if (empty()) return underflow;
        if (position < 0 || position > max_list) return range_Error;
        for (int i = position; i < count; i++) {
            entry[i] = entry[i + 1];
        }
        count--;
        return success;
    }

    Error_code retrieve(int position, List_entry& x)const {
        if (position < 0 || position > max_list) return range_Error;
        x = entry[position];
        return success;
    }

    Error_code replace(int position, List_entry& x) {
        if (position < 0 || position > max_list) return range_Error;
        entry[position] = x;
        return success;
    }

    void traverse(void(*visit)(List_entry& x)) {
        for (int i = 0; i < count; i++) {
            (*visit)(entry[i]);
        }
    }

    Error_code add(const List_entry& x) {
        return insert(count, x);
    }

    void exchange(int pos1, int pos2) {
        List_entry temp = entry[pos1];
        entry[pos1] = entry[pos2];
        entry[pos2] = temp;
    }

protected:
    int count;
    List_entry entry[max_list];
};

struct Record {
    string key;
    string other;
};

void print(int& x) {
    cout << x << " ";
}

int main() {
    int n;
    cin >> n;
    List<int> list;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.add(x);
    }

    // ��������
    int ordered = 0;
    for (; ordered < n; ordered++) {
        // ÿһ�ֲ�����Сֵ
        int min;
        int minIndex = ordered;
        list.retrieve(ordered, min);
        for (int j = ordered; j < n; j++) {
            int x;
            list.retrieve(j, x);
            if (x < min) {
                minIndex = j;
                min = x;
            }
        }
        // �ҵ���Сֵ�Ժ���orderedλ�õ�ֵ����
        list.exchange(ordered, minIndex);
        // �ڵڣ�n / 2�������һ��
        if (ordered == n / 2 - 1) {
            list.traverse(print);
            cout << endl;
        }
    }

    list.traverse(print);
}