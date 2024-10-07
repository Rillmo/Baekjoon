#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string a, b;
	cin >> a >> b;
	n = a.size();
	m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			dp[i][j] = (a[i-1] == b[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]));
			// cout << dp[i][j] << ' ';
		}
		// cout << endl;
	}
	cout << dp[n][m];
}