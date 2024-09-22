#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k, cur, sum = 0;
	cin >> k;
	stack<int> st;
	for (int i=0; i<k; i++) {
		cin >> cur;
		if (cur != 0)
			st.push(cur);
		else
			st.pop();
	}
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}