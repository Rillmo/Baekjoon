#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <queue>
using namespace std;

int n, m, s, e;
vector<pair<int, int> > graph[1002];
vector<int> dist(1002, INT_MAX);

void dijkstra() {
	priority_queue<pair<int, int> >pq;

	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int now_dist = -pq.top().first;
		int now_node = pq.top().second;
		pq.pop();
		if (dist[now_node] < now_dist)
			continue;
		for (size_t i=0; i<graph[now_node].size(); i++) {
			int next_node = graph[now_node][i].first;
			int next_dist = graph[now_node][i].second + now_dist;
			if (dist[next_node] > next_dist) {
				dist[next_node] = next_dist;
				pq.push(make_pair(-next_dist, next_node));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int from, to, cost;
	for (int i=0; i<m; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
	}
	cin >> s >> e;
	dijkstra();
	cout << dist[e];
}