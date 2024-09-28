#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;
using ii = pair<int,int>;

int n, m;
vector<int> graph[101];

int dijkstra(int start) {
	vector<int> dist(n+1, INT_MAX);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int x = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		for (int i=0; i<graph[x].size(); i++) {
			int nx = graph[x][i];
			int nd = d + 1;
			if (dist[nx] > nd) {
				dist[nx] = nd;
				pq.push({nd, nx});
			}
		}
	}
	int sum = 0;
	for (auto& d : dist) {
		sum += d;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int a, b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int mini = INT_MAX, answer;
	for (int i=1; i<=n; i++) {
		int tmp = dijkstra(i);
		if (mini > tmp) {
			answer = i;
			mini = tmp;
		}
	}
	cout << answer;
}