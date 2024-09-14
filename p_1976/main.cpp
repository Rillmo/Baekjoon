#include <iostream>
#include <vector>
using namespace std;

struct Unionfind {
	vector<int> par, siz;

	Unionfind(int n): par(n+1, -1), siz(n+1, 1) {}
	
	int root(int x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}
	bool issame(int x, int y) {
		if (x == y)	return true;
		return root(x) == root(y);
	}
	void unite(int x, int y) {
		if (x == y)	return;
		x = root(x); y = root(y);
		if (x == y) return;
		if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		} else {
			par[y] = x;
			siz[x] += siz[y];
		}
	}
	void print() {
		for (int i=0; i<par.size(); i++) {
			cout << i << '\t';
		}
		cout << '\n';
		for (int i=0; i<par.size(); i++) {
			cout << par[i] << '\t';
		}
		cout << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, graph[201][201];
	cin >> n >> m;
	vector<int> plan(m);
	Unionfind uf(n);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i=1; i<=n-1; i++) {
		for (int j=i+1; j<=n; j++) {
			if (graph[i][j] == 1)
				uf.unite(i, j);
		}
	}
	string ans = "YES";
	cin >> plan[0];
	// cout << uf.root(plan[0]);
	for (int i=1; i<m; i++) {
		cin >> plan[i];
		// cout << uf.root(plan[i]);
		if (!uf.issame(plan[0], plan[i]))
			ans = "NO";
	}
	cout << ans << '\n';
}