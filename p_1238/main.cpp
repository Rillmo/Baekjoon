#include <iostream>
#include <vector>
#include <limits.h>
#include <utility>
#include <queue>
using namespace std;

int n, m, x;
vector<pair<int, int>> graph[1001];
vector<int> dist;

int dijkstra(int start, int end) {
	dist.assign(n+1, INT_MAX);
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int now_node = pq.top().second;
		int now_dist = -pq.top().first;
		if (now_node == end)
			break;
		pq.pop();
		for (int i=0; i<graph[now_node].size(); i++) {
			int nxt_node = graph[now_node][i].first;
			int nxt_dist = graph[now_node][i].second + now_dist;
			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.push({-nxt_dist, nxt_node});
			}
		}
 	}
	return dist[end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x;
	int s, e, d;
	for (int i=0; i<m; i++) {
		cin >> s >> e >> d;
		graph[s].push_back({e, d});
	}
	dijkstra(x, 0);
	vector<int> student(n+1, 0);
	// x에서 각 학생의 집까지 걸리는 시간
	for (int i=1; i<=n; i++)
		student[i] = dist[i];
	// 각 학생들이 x까지 가는 시간
	for (int i=1; i<=n; i++)
		student[i] += dijkstra(i, x);
	int maxi = -1;
	for (int i=1; i<=n; i++)
		maxi = max(maxi, student[i]);
	cout << maxi;
}