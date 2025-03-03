#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Keyboard {
	int price;
	string type;
};

pair<int, int> solve(int usbOnly, int ps2Only, int both, vector<Keyboard> keyboards) {
	//按键盘种类分别放置
	vector<int> usbKeyboards;
	vector<int> ps2Keyboards;

	for (const auto& keyboard : keyboards) {
		if (keyboard.type == "USB") {
			usbKeyboards.push_back(keyboard.price);
		}
		else if (keyboard.type == "PS/2") {
			ps2Keyboards.push_back(keyboard.price);
		}
	}

	//用价格排序
	sort(usbKeyboards.begin(), usbKeyboards.end());
	sort(ps2Keyboards.begin(), ps2Keyboards.end());

	int total = usbOnly + ps2Only + both;
	int usedKeyboard = 0;
	int total_cost = 0;
	//优先满足只有一种接口的电脑
	int usbIndex = 0;
	int ps2Index = 0;
	while (usbIndex < usbKeyboards.size() && usbOnly > 0) {
		total_cost += usbKeyboards[usbIndex];
		usedKeyboard++;
		usbIndex++;
		usbOnly--;
	}
	while (ps2Index < ps2Keyboards.size() && ps2Only > 0) {
		total_cost += ps2Keyboards[ps2Index];
		usedKeyboard++;
		ps2Index++;
		ps2Only--;
	}
	//接着处理两种接口都有的电脑
	vector<int> combinedKeyboards;
	while (usbIndex < usbKeyboards.size()) {
		combinedKeyboards.push_back(usbKeyboards[usbIndex]);
		usbIndex++;
	}
	while (ps2Index < ps2Keyboards.size()) {
		combinedKeyboards.push_back(ps2Keyboards[ps2Index]);
		ps2Index++;
	}
	sort(combinedKeyboards.begin(), combinedKeyboards.end());

	for (int price : combinedKeyboards) {
		if (both > 0) {
			total_cost += price;
			usedKeyboard++;
			both--;
		}
	}
	return { usedKeyboard, total_cost };
  }

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int usbOnly, ps2Only, both;
		cin >> usbOnly >> ps2Only >> both;
		int M;
		cin >> M;
		vector<Keyboard> keyboards;
		for (int j = 0; j < M; j++) {
			Keyboard k;
			cin >> k.price >> k.type;
			keyboards.push_back(k);
		}
		sort(keyboards.begin(), keyboards.end(), [](Keyboard a, Keyboard b) {
			return a.price < b.price;
			});
		pair<int, int> result = solve(usbOnly, ps2Only, both, keyboards);
		cout << "case #" << i << ":" << endl;
		cout << result.first << " " << result.second << endl;
	}
	return 0;
}