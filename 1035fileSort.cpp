/*
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct File {
    string date;
    string time;
    long long size;
    string name;
    string datetime;
};

int main() {
    int n;
    bool firstCase = true;
    while (cin >> n) {
        if (n == 0) break;
        vector<File> files;
        files.resize(n);
        for (int i = 0; i < n; i++) {
            // 注意：文件名中不包含空格，所以可以直接用 >> 读取
            cin >> files[i].date >> files[i].time >> files[i].size >> files[i].name;
            files[i].datetime = files[i].date + " " + files[i].time;
        }

        // 读取命令行，此时输入中命令前有换行残留，先读取整行
        string dummy;
        getline(cin, dummy);
        string command;
        getline(cin, command);

        // 提取字段（命令格式为 "LIST /FIELD"）
        string field = command.substr(6); // 从位置6开始，即跳过 "LIST /"
        // 去除可能的多余空格
        while (!field.empty() && field[0] == ' ') {
            field.erase(0, 1);
        }

        // 根据排序字段进行排序，若出现相同的大小或时间，则以文件名升序排序
        if (field == "NAME") {
            sort(files.begin(), files.end(), [](const File& a, const File& b) {
                return a.name < b.name;
                });
        }
        else if (field == "SIZE") {
            sort(files.begin(), files.end(), [](const File& a, const File& b) {
                if (a.size == b.size)
                    return a.name < b.name;
                return a.size < b.size;
                });
        }
        else if (field == "TIME") {
            sort(files.begin(), files.end(), [](const File& a, const File& b) {
                if (a.datetime == b.datetime)
                    return a.name < b.name;
                return a.datetime < b.datetime;
                });
        }

        // 每组数据之间加一个空行（但最后一组后没有空行）
        if (!firstCase) {
            cout << "\n";
        }
        firstCase = false;

        // 按要求格式化输出：日期、时间、文件大小（宽度16，右对齐）、文件名
        for (const auto& f : files) {
            cout << f.date << " " << f.time << " "
                << setw(16) << right << f.size << " " << f.name << "\n";
        }
    }
    return 0;
}
*/