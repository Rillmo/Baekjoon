#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> cost;
vector<int> dp;
vector<int> indegree;
int n, k, x, y;

void bfs(int end) {
	queue<int> que;
	for (int i=1; i<=n; i++) {
		if (indegree[i] == 0) {
			que.push(i);
			dp[i] = cost[i];
		}
	}
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i=0; i<v[now].size(); i++) {
			int next = v[now][i];
			dp[next] = max(dp[next], cost[next] + dp[now]);
			if (--indegree[next] == 0)
				que.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;
	for (int t=0; t<test; t++) {
		int end;
		cin >> n >> k;
		v.resize(n+1);
		cost.resize(n+1);
		dp.resize(n+1, 0);
		indegree.resize(n+1,0);
		for (int i=1; i<=n; i++)
			cin >> cost[i];
		for (int i=0; i<k; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			indegree[y]++;
		}
		cin >> end;
		bfs(end);
		cout << dp[end] << '\n';
		v.clear();
		cost.clear();
		dp.clear();
		indegree.clear();
	}
}