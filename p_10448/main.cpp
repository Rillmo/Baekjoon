#include <iostream>
using namespace std;

int	getTriNum(int idx) {
	return idx * (idx + 1) / 2;
}

int	isCombOf3TriNum(int n) {
	int max=1;

	while (getTriNum(max) < n)
		max++;
	for (int i=1; i<=max; i++) {
		for (int j=i; j<=max; j++) {
			for (int k=j; k<=max; k++) {
				if (getTriNum(i) + getTriNum(j) + getTriNum(k) == n)
					return (1);
			}
		}
	}
	return 0;
}

int main() {
	int t;
	int n;

	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		cout << isCombOf3TriNum(n) << endl;
	}
}