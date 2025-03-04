/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

// 将字符串转换为小写的函数
string toLowerCase(const string& str) {
    string lowerStr = str;
    // 使用transform函数将字符串中的每个字符转换为小写
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
        return tolower(c);
        });
    return lowerStr;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // 忽略掉输入T后的换行符

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        cin.ignore(); // 忽略掉输入n后的换行符

        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            getline(cin, v[i]); // 使用getline读取包含空格的文献记录
        }

        // 对文献记录进行排序，排序时忽略大小写
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            return toLowerCase(a) < toLowerCase(b);
            });

        // 输出问题编号
        cout << "case #" << t << ":" << endl;
        // 输出排好序的文献记录
        for (const auto& str : v) {
            cout << str << endl;
        }
    }
    return 0;
}

*/