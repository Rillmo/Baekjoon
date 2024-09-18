#include <iostream>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
#define DIV 1000000007

map<ll, ll> m;

ll fibo(ll x) {
	if (m[x]) return m[x];

	if (x % 2 == 0)
		return m[x] = fibo(x/2) * (fibo(x/2+1) + fibo(x/2-1)) % DIV;
	else
		return m[x] = (fibo((x+1)/2) * fibo((x+1)/2) + fibo((x-1)/2) * fibo((x-1)/2)) % DIV;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	ll n, p;
	cin >> n;
	m[0] = 0;
	m[1] = 1;
	m[2] = 1;
	p = fibo(n);
	cout << p << endl;
}