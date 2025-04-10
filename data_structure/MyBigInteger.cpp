#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MyBigInteger {
private:
    string value;  // ���ַ�������ʾ����

    // �ַ����ӷ������ش������ĺ�
    string add(const string& num1, const string& num2) const {
        int len1 = num1.size(), len2 = num2.size();
        int maxLen = max(len1, len2) + 1;  // �����󳤶�
        string result(maxLen, '0');
        int carry = 0;
        int i = len1 - 1, j = len2 - 1, k = maxLen - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += num1[i] - '0';  // ����num1�ĵ�ǰλ
            if (j >= 0) sum += num2[j] - '0';  // ����num2�ĵ�ǰλ
            result[k] = (sum % 10) + '0';  // ���浱ǰλ�Ľ��
            carry = sum / 10;  // ���½�λ
            i--; j--; k--;
        }
        return result;
    }

    // �ַ������������ش������Ĳ�
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

        // �Ƴ�ǰ����
        size_t start = result.find_first_not_of('0');
        return start == string::npos ? "0" : result.substr(start);
    }

    // �ַ����˷������ش������Ļ�
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
            if (!(resultStr.empty() && num == 0)) {  // ȥ��ǰ����
                resultStr += to_string(num);
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }

    // �ַ������������ش���������
    string divide(const string& num1, const string& num2) const {
        if (num2 == "0") throw runtime_error("Division by zero");  // ���������

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

        // �Ƴ�ǰ����
        size_t start = result.find_first_not_of('0');
        return start == string::npos ? "0" : result.substr(start);
    }

    // �Ƚ������ַ������ִ�С
    int compare(const string& num1, const string& num2) const {
        if (num1.size() > num2.size()) return 1;
        if (num1.size() < num2.size()) return -1;
        return num1.compare(num2);
    }

public:
    MyBigInteger(string val = "") : value(val) {}

    // ʵ�ּӷ�
    MyBigInteger operator+(const MyBigInteger& other) const {
        return MyBigInteger(add(value, other.value));
    }

    // ʵ�ּ���
    MyBigInteger operator-(const MyBigInteger& other) const {
        return MyBigInteger(subtract(value, other.value));
    }

    // ʵ�ֳ˷�
    MyBigInteger operator*(const MyBigInteger& other) const {
        return MyBigInteger(multiply(value, other.value));
    }

    // ʵ�ֳ���
    MyBigInteger operator/(const MyBigInteger& other) const {
        return MyBigInteger(divide(value, other.value));
    }

    // ��ȡ��������ֵ
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