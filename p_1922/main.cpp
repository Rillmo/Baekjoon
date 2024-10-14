#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using iii = tuple<int,int,int>;

int n, m;
vector<iii> v;

struct UnionFind {
	vector<int> par;
	UnionFind(int n) :par(n+1) {
		for (int i=1; i<=n; i++) par[i] = i;
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	void merge(int x, int y) {
		if (x == y) return ;
		x = find(x); y = find(y);
		if (x == y) return ;
		par[y] = x;
	}
};

int kruskal() {
	int sum = 0;
	UnionFind uf(n);
	for (auto& now: v) {
		int from = get<0>(now);
		int to = get<1>(now);
		int cost = get<2>(now);
		if (uf.find(from) == uf.find(to)) continue;
		uf.merge(from, to);
		sum += cost;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int a, b, c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		v.push_back({a,b,c});
	}
	sort(v.begin(), v.end(), [](iii& v1, iii&v2) {
		return get<2>(v1) < get<2>(v2);
	});
	// for (int i=0; i<m; i++)
	// 	cout << get<0>(v[i]) << "," << get<1>(v[i]) << "," << get<2>(v[i]) << '\n';
	cout << kruskal();
}