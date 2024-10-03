#include <iostream>
#include <vector>
using namespace std;

int graph[1025][1025];
int dp[1025][1025];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> graph[i][j];
			// if (i == 0 && j == 0) dp[i][j] = graph[i][j];
			// else if (i == 0 && j > 0) dp[i][j] = graph[i][j] + dp[i][j-1];
			// else if (i > 0 && j == 0) dp[i][j] = graph[i][j] + dp[i-1][j];
			dp[i][j] = graph[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	vector<int> answer;
	for (int i=0; i<m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// x1--; y1--; x2--; y2--;
		if (x1 == x2 && y1 == y2)
			answer.push_back(graph[x1][y1]);
		else
			answer.push_back(dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]);
	}
	
	// cout << "_______________\n";
	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<n; j++) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << "_______________\n";

	for (auto &i : answer)
		cout << i << '\n';
}