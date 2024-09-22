#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;
using ii = pair<int,int>;

int n, k, dx[2]={-1, 1};

int dijkstra(int start, int end) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<int> dist(100001, INT_MAX);
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int x = pq.top().second;
		int d = pq.top().first;
		if (x == end)	break;
		pq.pop();
		// cout << x  << "," << d << '\n';
		for (int i=0; i<3; i++) {
			int nx;
			int nd = d + 1;
			if (i == 2)
				nx = x * 2;
			else
				nx = x + dx[i];
			if (nx < 0 || nx > 100000) continue;
			if (dist[nx] > nd) {
				dist[nx] = nd;
				pq.push({nd, nx});
			}
		}
	}
	return dist[end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cout << dijkstra(n, k);
}