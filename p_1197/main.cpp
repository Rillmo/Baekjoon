#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using iii = tuple<int,int,int>;

int v, e;
vector<iii> graph;

struct UnionFind {
	vector<int> par;
	UnionFind(int n) :par(n+1) {
		for (int i=1; i<=n; i++) par[i] = i;
	};
	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		if (x == y) return ;
		x = find(x); y = find(y);
		if (x == y) return ;
		par[y] = x;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	int a, b, c, sum = 0;
	for (int i=0; i<e; i++) {
		cin >> a >> b >> c;
		graph.push_back({a,b,c});
	}
	sort(graph.begin(), graph.end(), [](iii& v1, iii& v2) {
		return get<2>(v1) < get<2>(v2);
	});
	// for (auto& now : graph) {
	// 	cout << get<0>(now) << "->" << get<1>(now) << ":" << get<2>(now) << endl;
	// }
	UnionFind uf(v);
	for (auto& now : graph) {
		int from = get<0>(now);
		int to = get<1>(now);
		int cost = get<2>(now);
		if (uf.find(from) != uf.find(to)) {
			uf.unite(from, to);
			sum += cost;
		}
	}
	cout << sum;
}