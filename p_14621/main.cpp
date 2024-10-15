#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
using iii = tuple<int,int,int>;

int n, m;
vector<int> schools;
vector<iii> graph;

struct UnionFind {
	vector<int> par;
	UnionFind() :par(n+1) {
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
		if (x < y) par[y] = x;
		else par[x] = y;
	}
};

int kruskal() {
	int sum = 0, count = 0;
	UnionFind uf;
	for (auto& now: graph) {
		int from = get<0>(now);
		int to = get<1>(now);
		int cost = get<2>(now);
		if (uf.find(from) == uf.find(to)) continue;
		uf.merge(from, to);
		sum += cost;
		count++;
	}
	if (count < n-1) return -1;
	return sum;
}

int main() {
	cin >> n >> m;
	char tmp;
	for (int i=0; i<n ;i++) {
		cin >> tmp;
		schools.push_back(tmp == 'M' ? 1 : 0);
	}
	int a, b, c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		if (schools[a-1] != schools[b-1])
			graph.push_back({a,b,c});
	}
	sort(graph.begin(), graph.end(), [](iii& v1, iii& v2) { return get<2>(v1) < get<2>(v2); });
	cout << kruskal();
}