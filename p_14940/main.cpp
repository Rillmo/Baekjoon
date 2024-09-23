#include <iostream>
#include <tuple>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int n, m;
int graph[1001][1001];
int dist[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dijkstra(ii start) {
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + m, INT_MAX);
	dist[start.first][start.second] = 0;
	pq.push({0, start.first, start.second});
	while (!pq.empty()) {
		int y = get<1>(pq.top());
		int x = get<2>(pq.top());
		int d = get<0>(pq.top());
		pq.pop();
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nd = d + 1;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || graph[ny][nx] == 0) continue;
			if (dist[ny][nx] > nd) {
				dist[ny][nx] = nd;
				pq.push({nd, ny, nx});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tmp;
	ii start;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> tmp;
			graph[i][j] = tmp;
			if (tmp == 2) start = {i, j};
		}
	}
	dijkstra(start);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (graph[i][j] == 0)
				cout << 0 << ' ';
			else if (dist[i][j] == INT_MAX)
				cout << -1 << ' ';
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}