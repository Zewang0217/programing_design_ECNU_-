#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MyBigInteger {
private:
    string value;  // 用字符串来表示大数

    // 字符串加法，返回大整数的和
    string add(const string& num1, const string& num2) const {
        int len1 = num1.size(), len2 = num2.size();
        int maxLen = max(len1, len2) + 1;  // 结果最大长度
        string result(maxLen, '0');
        int carry = 0;
        int i = len1 - 1, j = len2 - 1, k = maxLen - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += num1[i] - '0';  // 加上num1的当前位
            if (j >= 0) sum += num2[j] - '0';  // 加上num2的当前位
            result[k] = (sum % 10) + '0';  // 保存当前位的结果
            carry = sum / 10;  // 更新进位
            i--; j--; k--;
        }
        return result;
    }

    // 字符串减法，返回大整数的差
    string subtract(const string& num1, const string& num2) const {
        int len1 = num1.size(), len2 = num2.size();
        string result(len1, '0');
        int borrow = 0;
        int i = len1 - 1, j = len2 - 1, k = len1 - 1;

        while (i >= 0 || j >= 0) {
            int diff = (num1[i] - '0') - borrow;
            if (j >= 0) diff -= (num2[j] - '0');
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            result[k] = diff + '0';
            i--; j--; k--;
        }

        // 移除前导零
        size_t start = result.find_first_not_of('0');
        return start == string::npos ? "0" : result.substr(start);
    }

    // 字符串乘法，返回大整数的积
    string multiply(const string& num1, const string& num2) const {
        int len1 = num1.size(), len2 = num2.size();
        vector<int> result(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string resultStr;
        for (int num : result) {
            if (!(resultStr.empty() && num == 0)) {  // 去掉前导零
                resultStr += to_string(num);
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }

    // 字符串除法，返回大整数的商
    string divide(const string& num1, const string& num2) const {
        if (num2 == "0") throw runtime_error("Division by zero");  // 处理除以零

        string result = "0";
        string current = "";

        for (size_t i = 0; i < num1.size(); i++) {
            current += num1[i];
            if (current.size() >= num2.size()) {
                int count = 0;
                while (compare(current, num2) >= 0) {
                    current = subtract(current, num2);
                    count++;
                }
                result += to_string(count);
            }
            else {
                result += "0";
            }
        }

        // 移除前导零
        size_t start = result.find_first_not_of('0');
        return start == string::npos ? "0" : result.substr(start);
    }

    // 比较两个字符串数字大小
    int compare(const string& num1, const string& num2) const {
        if (num1.size() > num2.size()) return 1;
        if (num1.size() < num2.size()) return -1;
        return num1.compare(num2);
    }

public:
    MyBigInteger(string val = "") : value(val) {}

    // 实现加法
    MyBigInteger operator+(const MyBigInteger& other) const {
        return MyBigInteger(add(value, other.value));
    }

    // 实现减法
    MyBigInteger operator-(const MyBigInteger& other) const {
        return MyBigInteger(subtract(value, other.value));
    }

    // 实现乘法
    MyBigInteger operator*(const MyBigInteger& other) const {
        return MyBigInteger(multiply(value, other.value));
    }

    // 实现除法
    MyBigInteger operator/(const MyBigInteger& other) const {
        return MyBigInteger(divide(value, other.value));
    }

    // 获取大整数的值
    string getValue() const {
        return value;
    }
};

/*

int main() {
    string n, m, op;
    cin >> n >> m >> op;

    MyBigInteger num1(n), num2(m);
    MyBigInteger result("0");

    if (op == "+") {
        result = num1 + num2;
    }
    else if (op == "-") {
        result = num1 - num2;
    }
    else if (op == "*") {
        result = num1 * num2;
    }
    else if (op == "/") {
        result = num1 / num2;
    }

    cout << result.getValue() << endl;

    return 0;
}
*/