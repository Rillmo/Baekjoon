#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[101];
int visited[101];

int bfs() {
	queue<int> que;
	que.push(1);
	visited[1] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto& next : graph[now]) {
			if (visited[next])	continue;
			que.push(next);
			visited[next] = 1;
		}
	}
	int count = 0;
	for (int i=2; i<=n+1; i++) {
		if (visited[i] == 1)
			count++;
	}
	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cout << bfs();
}