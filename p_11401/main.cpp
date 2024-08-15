#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll expdiv(ll n, ll e) {
	if (e == 0)
		return 1;
	ll td = expdiv(n, e/2) % MOD;
	if (e % 2 == 1)
		return td * td % MOD * n % MOD;
	else
		return td * td % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	ll n, k, top, bot, res, dp[2], rem[3];
	cin >> n >> k;
	dp[0] = 1;
	for (int i=1; i<=n; i++) {
		dp[1] = dp[0] * i % MOD;
		if (i == k)	rem[0] = dp[1];
		if (i == n-k)	rem[1] = dp[1];
		if (i == n)	rem[2] = dp[1];
		dp[0] = dp[1];
	}
	if (k == 0)		rem[0] = 1;
	if (n-k == 0)	rem[1] = 1;

	top = rem[2] % MOD;
	bot = expdiv((rem[0] * rem[1]) % MOD, MOD - 2) % MOD;
	res = top * bot % MOD;
	cout << res << '\n';
}