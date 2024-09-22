#include <iostream>
using namespace std;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	ii dp[50];
	dp[0] = {1, 0};
	dp[1] = {0, 1};
	for (int i=2; i<50; i++) {
		dp[i].first = dp[i-1].first + dp[i-2].first;
		dp[i].second = dp[i-1].second + dp[i-2].second;
	}
	cin >> t;
	for (int i=0; i<t; i++) {
		int n;
		cin >> n;
		cout << dp[n].first << ' ' << dp[n].second << '\n';
	}
}