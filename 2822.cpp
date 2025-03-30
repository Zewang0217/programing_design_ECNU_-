#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>

using namespace std;

void printBytes(int value) {
	unsigned char* bytes = (unsigned char*)&value; // 将int指针转为unsigned char指针
	for (size_t i = 0; i < sizeof(int); i++) {
		cout << hex << setw(2) << setfill('0') << (int)bytes[i] << " "; // 输出每个字节的十六进制
	}
	cout << endl;
}

void printBytes(double value) {
	unsigned char* bytes = (unsigned char*)&value; // 将double指针转为unsigned char指针
	for (size_t i = 0; i < sizeof(double); i++) {
		cout << hex << setw(2) << setfill('0') << (int)bytes[i] << " "; // 输出每个字节的十六进制
	}
	cout << endl;
}

/*
int main()
{
	string line;
	while (getline(cin, line)) {
		if (line.find('.') != string::npos) {
			double d;
			istringstream iss(line);
			iss >> d;
			printBytes(d);
		}
		else {
			int i;
			istringstream iss(line);
			iss >> i;
			printBytes(i);
		}
	}
	return 0;
}
*/