#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int n, m;
bool malf[11] = {false};

bool checkMalf(int num) {
	string str = to_string(num);
	for (int i=0; i<str.length(); i++) {
		if (malf[str[i]-'0'] == true)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// input
	cin >> n >> m;
	int tmp;
	for (int i=0; i<m; i++) {
		cin >> tmp;
		malf[tmp] = true;
	}

	int try1 = abs(n - 100);

	for (int i=0; i<=1000000; i++) {
		if (checkMalf(i)) {
			int try2 = abs(n - i) + to_string(i).length();
			try1 = min(try1, try2);
		}
	}
	cout << try1 << '\n';
}