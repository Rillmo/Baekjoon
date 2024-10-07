#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define DP_SIZ 100000

ll mod, siz, num;
vector<ll> dp;

ll div_conq(ll n) {
	// cout << "now : " << num << "^" << n << endl;
	if (n < DP_SIZ) {
		if (dp[n] != -1)
			return dp[n];
		dp[n/2] = div_conq(n/2);
		dp[n-n/2] = div_conq(n-n/2);
		return dp[n] = dp[n/2] * dp[n-n/2] % mod;
	} else {
		return div_conq(n/2) * div_conq(n-n/2) % mod;
	}
}

int main() {
	int a;
	cin >> a >> siz >> mod;
	num = a;
	dp.assign(DP_SIZ, -1);
	dp[0] = 1;
	dp[1] = num % mod;
	cout << div_conq(siz);
}