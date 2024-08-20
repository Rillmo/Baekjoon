#include <iostream>
#include <cmath>
using namespace std;
#define DIV 1000000
typedef long long ll;
//1000000000000000000

ll fibo(ll num) {
	ll first = 0, second = 1, tmp;
	if (num == 1)	return 1;
	for (ll i=1; i<num; i++) {
		tmp = first;
		first = second;
		second += tmp;
		first %= DIV;
		second %= DIV;
	}
	return second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	ll n, p;
	cin >> n;

	p = 15 * pow(10, 5);
	cout << fibo(n % p) << endl;
}