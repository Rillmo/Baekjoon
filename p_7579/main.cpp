#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

vector<vector<int>> dp;

void print() {
	for (int i=0; i<dp.size(); i++) {
		for (int j=0; j<dp[i].size(); j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	int n, m, answer = INT_MAX;
	cin >> n >> m;
	vector<int> v(n+1);
	vector<int> w(n+1);
	for (int i=1; i<=n; i++)
		cin >> v[i];
	for (int i=1; i<=n; i++)
		cin >> w[i];
	dp.assign(n+1, vector<int>(10001, 0));
	for (int i=1; i<=n; i++) {
		for (int j=0; j<10001; j++) {
			if (w[i] <= j) dp[i][j] = max(v[i] + dp[i-1][j-w[i]], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
			if (dp[i][j] >= m) answer = min(answer, j);
		}
	}
	cout << answer;
}