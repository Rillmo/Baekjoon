#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		string str;
		getline(cin, str);
		if (str == ".") return 0;
		string res = "yes";
		stack<char> st;
		int i=0;
		while (str[i] != '.') {
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					res = "no";
			} else if (str[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
					res = "no";
			}
			i++;
		}
		if (!st.empty()) res = "no";
		cout << res << '\n';
	}
}