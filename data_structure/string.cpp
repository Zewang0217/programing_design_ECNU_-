/*
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class String {
public:
	// 默认构造函数
	String() : entries(nullptr), length(0) {}

	// 析构函数
	~String() {
		delete[] entries; // entries是字符数组，用delete[]
	}

	// C风格字符串构造
	String(const char* copy) {
		if (copy == nullptr) { // 空指针
			length = 0;
			entries = nullptr;
		}
		else {
			length = 0;
			while (copy[length] != '\0') length++;

			entries = new char[length + 1];

			for (int i = 0; i < length; i++) {
				entries[i] = copy[i];
			}

			entries[length] = '\0';
		}
	}

	// 拷贝构造函数（深构造）
	String(const String& copy) {
		length = copy.length;
		if (length == 0) entries = nullptr;
		else {
			entries = new char[length + 1];
			for (int i = 0; i <= length; i++) {
				entries[i] = copy.entries[i];
			}
		}
	}

	// 等号重载
	String& operator=(const String& copy) {
		if (this != &copy) { // 自等
			delete[] entries;

			// 空
			length = copy.length;
			if (length == 0) {
				entries = nullptr;
			}
			else {
				entries = new char[length + 1];
				for (int i = 0; i <= length; i++) {
					entries[i] = copy.entries[i];
				}
			}
		}
		return *this;
	}
	const char* c_str() const { // 只读
		return entries;
	}

	int getLength() const{
		return length;
	}
	// 让这些函数可以直接访问类的私有成员
	friend istream& operator>>(istream& in, String& s);
	friend ostream& operator<<(ostream& out, const String& s);

protected:
	char* entries;
	int length;
};

bool operator == (const String& first, const String& second) {
	if (&first == &second) return true;

	else if (first.getLength() != second.getLength()) return false;

	const char* str1 = first.c_str();
	const char* str2 = second.c_str();

	if (str1 == nullptr && str2 == nullptr) return true;
	else if (str1 == nullptr || str2 == nullptr) return false;
	else {
		for (int i = 0; i < first.getLength(); i++) {
			if (str1[i] != str2[i]) return false;
		}
		return true;
	}
}
bool operator > (const String& first, const String& second) {
	if (&first == &second) return false;
	
	const char* str1 = first.c_str();
	const char* str2 = second.c_str();

	if (str1 == nullptr) return false;  // 空字符串不大于任何字符串
	if (str2 == nullptr) return true;   // 非空字符串大于空字符串

	int mL = min(first.getLength(), second.getLength());
	for (int i = 0; i < mL; i++) {
		if (str1[i] > str2[i]) return true;
		if (str1[i] < str2[i]) return false;
		// 相等就继续比较下一个
	}
	// length
	return first.getLength() > second.getLength();
}
bool operator < (const String& first, const String& second) {
	if (&first == &second) return false;

	const char* str1 = first.c_str();
	const char* str2 = second.c_str();

	if (str1 == nullptr) return true;  // 空字符串不大于任何字符串
	if (str2 == nullptr) return false;   // 非空字符串大于空字符串

	int mL = min(first.getLength(), second.getLength());
	for (int i = 0; i < mL; i++) {
		if (str1[i] > str2[i]) return false;
		if (str1[i] < str2[i]) return true;
		// 相等就继续比较下一个
	}
	// length
	return first.getLength() < second.getLength();
}

bool operator >= (const String& first, const String& second) {
	return !(first < second);
}

bool operator <= (const String& first, const String& second) {
	return !(first > second);
}

bool operator != (const String& first, const String& second) {
	return !(first == second);
}


void strncpy(String& to, const String& from, int n) {
	if (n <= 0) {
		to = String();
		return;
	}

	const char* src = from.c_str();
	if (src == nullptr) {
		to = String();
		return;
	}

	int srcLen = from.getLength();
	int copyLen = min(n, srcLen);

	char* buffer = new char[copyLen + 1];

	for (int i = 0; i < copyLen; i++) {
		buffer[i] = src[i];
	}
	buffer[copyLen] = '\0';

	to = String(buffer);

	delete[] buffer;
}

// add_on追加到add_to上
void strcat(String& add_to, const String& add_on) {
	const char* on = add_on.c_str();
	const char* to = add_to.c_str();
	int onLen = add_on.getLength();
	int toLen = add_to.getLength();

	if (onLen == 0 || on == nullptr) return;

	char* buffer = new char[onLen + toLen + 1];

	// 复制to的内容
	if (to != nullptr) {
		for (int i = 0; i < toLen; i++) {
			buffer[i] = to[i];
		}
	}

	for (int i = 0; i < onLen; i++) {
		buffer[toLen + i] = on[i];
	}

	buffer[toLen + onLen] = '\0';

	add_to = String(buffer);

	delete[] buffer;
}


int strstr(const String& text, const String& target) {
	int targetLen = target.getLength();
	int textLen = text.getLength();
	const char* src = text.c_str();
	const char* tar = target.c_str();

	if (targetLen > textLen || textLen == 0 || src == nullptr) return -1;
	if (targetLen == 0 || tar == nullptr) return 0;

	for (int i = 0; i <= textLen - targetLen; i++) {
		bool found = true;
		for (int j = 0; j < targetLen; j++) {
			if (src[i + j] != tar[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			return i;
		}
	}
	return -1;
}
String read_in(istream& input) {
	const int BUFFER_SIZE = 256;
	char buffer[BUFFER_SIZE];
	String result;

	while (input.getline(buffer, BUFFER_SIZE)) {
		strcat(result, String(buffer));

		if (input.gcount() < BUFFER_SIZE - 1 ||
			buffer[input.gcount() - 1] == '\0') {
			break;
		}
	}
	return result;
}
void write(String& s) {
	const char* str = s.c_str();
	if (str != nullptr) {
		cout << str;
	}
}

ostream& operator<<(ostream& out, const String& s) {
	const char* str = s.c_str();
	if (str != nullptr) {
		out << str;
	}
	return out;
}

istream& operator>>(istream& in, String& s) {
	char buffer[1000];
	in >> buffer;
	s = String(buffer);  // 构造新的 String 对象
	return in;
}
*/

/*
int main() {
	// 上机作业
	int N;
	cin >> N;
	cin.ignore();
	vector<String> strings;
	string line;
	getline(cin, line);
	istringstream iss(line);
	string token;
	while (iss >> token) {
		strings.push_back(String(token.c_str()));
	}

	// 读取查询对
	vector<pair<int, int>> queries;
	int a, b;
	while (cin >> a >> b) {
		if (a == -1 && b == -1) break;
		queries.emplace_back(a, b);
	}

	// 处理
	vector<int> results;
	for (const auto& q : queries) {
		int pos = strstr(strings[q.second], strings[q.first]);
		results.push_back(pos);
	}

	for (size_t i = 0; i < results.size(); i++) {
		if (i != 0) cout << " ";
		cout << results[i];
	}
	cout << endl;

	// 字典序输出
	sort(strings.begin(), strings.end(), [](const String& a, const String& b) {
		return a < b;
		});
	for (int i = 0; i < strings.size(); i++) {
		if (i != 0) {
			cout << " ";
		}
		write(strings[i]);
	}
	cout << endl;
	return 0;
	
	// cin 实现

	String s1, s2;

	cout << "Enter two words: ";
	cin >> s1 >> s2;

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	if (s1 < s2) {
		cout << s1 << " is less than " << s2 << endl;
	}
	
}
*/

// cin功能的添加