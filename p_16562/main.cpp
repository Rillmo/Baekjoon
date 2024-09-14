#include <iostream>
#include <vector>
using namespace std;

struct Unionfind {
	vector<int> par, siz, cost;

	Unionfind(int n): par(n+1, -1), siz(n+1, 1), cost(n+1, 0) {}

	int root(int x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}
	void unite(int x, int y, int c) {
		if (x == y) return;
		x = root(x); y = root(y);
		if (x == y) return;
		if (siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		cost[x] = c;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	Unionfind uf(n);
	for (int i=1; i<=n; i++)
		cin >> uf.cost[i];
	for (int i=0; i<m; i++) {
		int v, w;
		cin >> v >> w;
		uf.unite(v, w, min(uf.cost[uf.root(v)], uf.cost[uf.root(w)]));
	}
	int sum = 0;
	for (int i=1; i<=n; i++) {
		// cout << uf.cost[i] << ' ';
		if (uf.par[i] == -1) {
			// cout << i << ":" << uf.cost[i] << endl;
			sum += uf.cost[i];
		}
	}
	if (k < sum)	cout << "Oh no";
	else	cout << sum;
}