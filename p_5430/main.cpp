#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

void parse(string& str, deque<int>& vec) {
	string num_str;
	int i=0;
	while (i<str.size()) {
		if (isdigit(str[i])) {
			num_str.push_back(str[i]);
		} else {
			// cout << "^^^^^^^" << num_str << " ";
			if (num_str.size()) {
				vec.push_back(stoi(num_str));
				num_str = "";
			}
		}
		i++;
	}
}

int main() {
	int t, n;
	string p, list;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> p >> n >> list;
		deque<int> deq;
		parse(list, deq);
		int dir = 1;
		bool error = false;
		for (auto &c : p) {
			if (c == 'R')
				dir *= -1;
			else if (c == 'D') {
				if (deq.empty()) {
					error = true;
					break;
				}
				if (dir == 1)
					deq.pop_front();
				else
					deq.pop_back();
			}
		}
		if (error) {
			cout << "error\n";
			continue;
		}
		cout << "[";
		int idx = 0;
		int size = deq.size();
		if (dir == 1) {
			while (!deq.empty()) {
				int now = deq.front();
				cout << now << (idx == size-1 ? "" : ",");
				idx++;
				deq.pop_front();
			}
		} else {
			while (!deq.empty()) {
				int now = deq.back();
				cout << now << (idx == size-1 ? "" : ",");
				idx++;
				deq.pop_back();
			}
		}
		cout << "]\n";
	}
}