#include<iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
enum Error_code { underflow, overflow, range_Error, success };
const int max_list = 1000;
struct Record {
    string key;
    string other;
};

void print(int& x) {
    cout << x << " ";
}

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

    Error_code insertSort(int n) {
        int ordered = 1;
        for (; ordered < n; ordered++) {
            // 拿出要检查的current
            int current;
            retrieve(ordered, current);
            int j = ordered - 1; // 从有序序列的最后一个开始

            while (j >= 0) {
                int toComp;
                retrieve(j, toComp);
                if (toComp > current) {
                    replace(j + 1, toComp);
                    j--;
                }
                else {
                    break;
                }
            }
            replace(j + 1, current);
        }
        return success;
    }

    // 希尔排序
    void shell_sort(vector<int> increments, int group) {
        int increment, start;
        int i = 0;
        do {
            increment = increments[i];
            i++;
            // 对不同的increment进行插入排序
            for (start = 0; start < increment; start++) {
                sort_interval(start, increment);
            }
            traverse(print);
            cout << endl;
        } while (i < group);
    }

    void sort_interval(int start, int increment) {
        int first_unsorted;
        int position;
        int current;
        for (first_unsorted = start + increment; first_unsorted
            < count; first_unsorted += increment) {
            if (entry[first_unsorted] < entry[first_unsorted - increment]) {
                // 取出当前元素的位置和item
                position = first_unsorted;
                current = entry[first_unsorted];

                do { // 把有序队列里比它大的全部前移一位，并找到它的位置
                    entry[position] = entry[position - increment];
                    position -= increment;
                } while (position > start && entry[position - increment] > current);
                // 进行替换
                entry[position] = current;
            }
        }
    }

protected:
    int count;
    List_entry entry[max_list];
};



int main() {
    int n,group;
    cin >> n >> group;
    List<int> list;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.add(x);
    }
    vector<int> increments(group);
    for (int i = 0; i < group; i++) {
        cin >> increments[i];
    }

    list.shell_sort(increments, group);

    // list.traverse(print);
}