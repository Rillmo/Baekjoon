#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	stack<char> stck;
	map<char, int> pri;
	pri['('] = 0;
	pri[')'] = 0;
	pri['+'] = 1;
	pri['-'] = 1;
	pri['*'] = 2;
	pri['/'] = 2;
	cin >> str;
	for (int i=0; i<str.length(); i++) {
		// cout << "now:" << str[i] << '\n';
		// if (!stck.empty())
		// 	cout << "top:" << stck.top() << endl;
		if (isalpha(str[i]))
			cout << str[i];
		else if (str[i] == '(')
			stck.push(str[i]);
		else if (str[i] == ')') {
			while (!stck.empty()) {
				if (stck.top() == '(') {
					stck.pop();
					break;
				}
				cout << stck.top();
				stck.pop();
			}
		} else {
			if (stck.empty())
				stck.push(str[i]);
			else {
				if (pri[stck.top()] >= pri[str[i]]) {
					while (!stck.empty() && pri[stck.top()] >= pri[str[i]]) {
						cout << stck.top();
						stck.pop();
					}
					stck.push(str[i]);
				} else
					stck.push(str[i]);
			}
		}
	}
	while (!stck.empty()) {
		cout << stck.top();
		stck.pop();
	}
}