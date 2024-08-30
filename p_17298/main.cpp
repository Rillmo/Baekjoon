#include <iostream>
#include <stack>
using namespace std;

int n, arr[1000001];
stack<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	for (int i=0; i<n; i++) {
		if (st.empty()) {
			st.push(i);
		} else {
			while (!st.empty() && arr[st.top()] < arr[i]) {
				arr[st.top()] = arr[i];
				st.pop();
			}
			st.push(i);
		}
	}
	while (!st.empty()) {
		arr[st.top()] = -1;
		st.pop();
	}

	for (int i=0; i<n; i++)
		cout << arr[i] << ' ';

}