#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>

using namespace std;

void printBytes(int value) {
	unsigned char* bytes = (unsigned char*)&value; // ��intָ��תΪunsigned charָ��
	for (size_t i = 0; i < sizeof(int); i++) {
		cout << hex << setw(2) << setfill('0') << (int)bytes[i] << " "; // ���ÿ���ֽڵ�ʮ������
	}
	cout << endl;
}

void printBytes(double value) {
	unsigned char* bytes = (unsigned char*)&value; // ��doubleָ��תΪunsigned charָ��
	for (size_t i = 0; i < sizeof(double); i++) {
		cout << hex << setw(2) << setfill('0') << (int)bytes[i] << " "; // ���ÿ���ֽڵ�ʮ������
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