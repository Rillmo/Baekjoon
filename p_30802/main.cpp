#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, tee[7], t, p;
	cin >> n;
	for (int i=0; i<6; i++)
		cin >> tee[i];
	cin >> t >> p;

	int tsum = 0, psum = 0;
	for (int i=0; i<6; i++) {
		tsum += tee[i] / t;
		if (tee[i] % t != 0)
			tsum++;
	}
	cout << tsum << '\n';
	cout << n / p << ' ' << n % p;
}