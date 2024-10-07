#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, answer = -1;
	cin >> n;
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++)
			cin >> dp[i][j];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
			if (i == n) answer = max(answer, dp[i][j]);
			// cout << dp[i][j] << ' ';
		}
		// cout << endl;
	}
	cout << answer;
}