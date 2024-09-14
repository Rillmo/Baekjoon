#include <iostream>
#include <stack>
using namespace std;

void print_bit(int num) {
	cout << "___bit ";
	stack<int> st;
	while (num) {
		st.push(num % 2);
		num /= 2;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m;
	cin >> m;
	unsigned int s = 0;
	string str;
	int n;
	for (int i=0; i<m; i++) {
		cin >> str;
		if (str == "add") {
			cin >> n;
			s |= (1 << n);
		} else if (str == "remove") {
			cin >> n;
			s &= ~(1 << n);
		} else if (str == "check") {
			cin >> n;
			if ((s & (1 << n)) == 0)	cout << 0 << '\n';
			else	cout << 1 << '\n';
		} else if (str == "toggle") {
			cin >> n;
			s ^= (1 << n);
		} else if (str == "all") {
			s = (1 << 21) - 1;
		} else if (str == "empty") {
			s = 0;
		}
		// print_bit(s);
	}
}