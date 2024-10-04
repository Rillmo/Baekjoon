#include <iostream>
#include <tuple>
#include <limits.h>
#include <vector>
using namespace std;
using iii = tuple<int,int,int>;

int n, m, w;

string bellman_ford(vector<iii> edges) {
	vector<int> dist(n+1, INT_MAX);
	// dist[1] = 0;
	for (int i=1; i<n; i++) {
		for (int j=0; j<edges.size(); j++) {
			int from = get<0>(edges[j]);
			int to = get<1>(edges[j]);
			int cost = get<2>(edges[j]);
			if (dist[to] > cost + dist[from]) {
				dist[to] = cost + dist[from];
			}
		}
	}
	for (int j=0; j<edges.size(); j++) {
		int from = get<0>(edges[j]);
		int to = get<1>(edges[j]);
		int cost = get<2>(edges[j]);
		if (dist[to] > cost + dist[from]) {
			return "YES";
		}
	}
	return "NO";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int test=0; test<tc; test++) {
		cin >> n >> m >> w;
		vector<iii> edges;
		int s, e, t;
		for (int i=0; i<m; i++) {
			cin >> s >> e >> t;
			edges.push_back({s, e, t});
			edges.push_back({e, s, t});
		}
		for (int i=0; i<w; i++) {
			cin >> s >> e >> t;
			edges.push_back({s, e, -t});
		}
		cout << bellman_ford(edges);
	}
}