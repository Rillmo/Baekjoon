#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <queue>
using namespace std;

int v, e, start;
vector<pair<int, int> > graph[20001];
vector<int> dist(300001, INT_MAX);

void dijkstra() {
	std::priority_queue<pair<int, int> > pq;

	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur_dist = -pq.top().first;	// 출발지부터 현재 정점까지의 최소거리
		int cur_node = pq.top().second;	// 현재 정점
		pq.pop();

		for (int i=0; i<graph[cur_node].size(); i++) {
			int nxt_dist = cur_dist + graph[cur_node][i].second;	// 현재 정점부터 다음 정점까지의 가중치
			int nxt_node = graph[cur_node][i].first;	// 다음 정점
			
			if (dist[nxt_node] > nxt_dist) {
				dist[nxt_node] = nxt_dist;
				pq.push(make_pair(-nxt_dist, nxt_node));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> start;
	int from, to, cost;
	for (int i=0; i<e; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
	}
	dijkstra();
	for (int i=1; i<=v; i++) {
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}