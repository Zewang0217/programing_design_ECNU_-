/*
#include<iostream>
#include <string>
#include <sstream>
using namespace std;
enum Error_code { underflow, overflow, range_Error, success };
const int max_list = 100;

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
    
protected:
    int count;
    List_entry entry[max_list];
};
*/

//void print(int& x) {
//    cout << x << " ";
//}

/*
int main() {
    List<int> l;
    int n;
    int count = 0;
    while (cin >> n && n != -1) {
        l.insert(count, n);
        count++;
    }

    l.traverse(print);
}
*/
/*
struct Record {
    string key;
    string other;
};
*/

/*
// 二分查找实现
int main() {
    string target;
    cin >> target;
    cin.ignore();
    string line;
    getline(cin, line);

    istringstream iss(line);
    string key, other;

    List<Record> rs;
    while (iss >> key >> other) {
        Record r;
        r.key = key;
        r.other = other;
        rs.add(r);
    }

    int left = 0, right = rs.size();
    int res = 0;
    bool found = false;
    while (left < right) {
        int mid = left + (right - left) / 2;

        Record x;
        rs.retrieve(mid, x);
        
        if (x.key < target) {
            left = mid + 1;
        }
        else if (x.key > target) {
            right = mid;
        }
        else {
            res = mid;
            cout << res << endl;
            cout << x.key << " " << x.other << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "-1" << endl;
    }

}
*/