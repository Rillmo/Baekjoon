#include <iostream>
using namespace std;

int main() {
	int n, k;
	int w[101];
	int v[101];
	int **dp;

	// input
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> w[i] >> v[i];
	}

	dp = new int*[n+1];
	for (int i=0; i<n+1; i++)
		dp[i] = new int[k+1];

	for (int j=0; j<=k; j++) {
		for (int i=0; i<=n; i++) {
			if (i == 0 || j == 0)	dp[i][j] = 0;
			else if (w[i] > j)	dp[i][j] = dp[i-1][j];
			else if (w[i] <= j)	dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
		}
	}
	cout << dp[n][k] << endl;
}