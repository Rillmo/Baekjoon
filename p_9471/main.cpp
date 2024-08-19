#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int p, n , m, res, tmp, first, second;
map<int, int> test;

int getK(int m) {
	first = 1;
	second = 1;
	int i;
	for (i=1; ; i++) {
		tmp = first;
		first = second;
		second += tmp;
		first %= m;
		second %= m;
		if (first == 0 && second == 1)
			break;
	}
	return i+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> p;
	for (int i=0; i<p; i++) {
		cin >> n >> m;
		test[n] = m;
	}

	for (int i=0; i<p; i++) {
		n = i+1;
		m = test[n];
		res = -1;
		if (log2(m) == (int)log2(m))
			res = 3 * pow(2, log2(m) - 1);
		else if (log(m)/log(5) == (int)(log(m)/log(5)))
			res = 4 * pow(5, log(m)/log(5));
		else if (log(m)/log(10) == (int)log(m)/log(10))
			res = 15 * pow(10, log(m)/log(10) - 1);
		else
			res = getK(m);
		cout << n << " " << res << '\n';
	}
}