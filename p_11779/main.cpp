#include <iostream>
#include <stack>
#include <limits.h>	
#include <queue>
#include <vector>
using namespace std;
using ii = pair<int,int>;

int n, m;
vector<ii> graph[1001];
vector<int> dist;
vector<int> route(1001, 0);

int dijkstra(int start, int end) {
	dist.assign(n+1, INT_MAX);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, start});
	dist[start] = 0;
	while (!pq.empty()) {
		int x = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (x == end) break;
		for (int i=0; i<graph[x].size(); i++) {
			int nx = graph[x][i].first;
			int nd = d + graph[x][i].second;
			if (dist[nx] > nd) {
				dist[nx] = nd;
				route[nx] = x;
				pq.push({nd, nx});
			}
		}
	}
	return dist[end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int a, b, c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}
	int start, end;
	cin >> start >> end;
	// cout << "_________\n";
	cout << dijkstra(start, end) << '\n';
	int now = end;
	vector<int> res;
	while (now) {
		res.push_back(now);
		now = route[now];
	}
	cout << res.size() << '\n';
	for (int i=res.size()-1; i>=0; i--)
		cout << res[i] << ' ';
}