#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<int> graph(100001, INT_MAX);
priority_queue<pair<int, int> > pq;
int dx[2] = {1, -1};

int dijkstra(int start, int end) {
	graph[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int x = pq.top().second;
		int dist = -pq.top().first;
		// cout << "now : " << x << "/" << dist << "\n";
		if (x == end)
			break;
		pq.pop();
		for (int i=0; i<3; i++) {
			int nx;
			int ndist;
			if (i == 2) {
				nx = x * 2;
				ndist = dist;
			} else {
				nx = x + dx[i];
				ndist = dist + 1;
			}
			if (nx > 100000)	continue;
			if (graph[nx] > ndist) {
				graph[nx] = ndist;
				pq.push({-ndist, nx});
			}
		}
	}
	return graph[end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	cout << dijkstra(n, k);
}