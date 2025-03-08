/*
#include "Cirqueue.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	int scenario = 1;
	while (cin >> t && t != 0) {
		Cirqueue<int> teamQueue;//存储队伍编号
		Cirqueue<int> teamMembers[11];//每个团队设置一个队列
		bool inQueue[11] = { false };

		string operation;
		cout << "Scenario #" << scenario << endl;
		scenario++;
		while (cin >> operation) {
			if (operation == "STOP") {
				break;
			}
			if (operation == "ENQUEUE") {
				int team, id;
				cin >> team >> id;

				if (!inQueue[team]) {
					teamQueue.append_rear(team);
					inQueue[team] = true;
				}
				teamMembers[team].append_rear(id);
			}
			else if (operation == "DEQUEUE") {
				int frontTeam;
				teamQueue.retrieve_front(frontTeam);
				
				int person;

				teamMembers[frontTeam].serve_and_retrieve(person);
				cout << person << endl;

				if (teamMembers[frontTeam].isEmpty()) {
					teamQueue.serve_front();
					inQueue[frontTeam] = false;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
*/