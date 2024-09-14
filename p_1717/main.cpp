#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct UnionFind {
	vector<int> par, siz;
	UnionFind(int n): par(n+1, -1), siz(n+1, 1) {}

	// 루트 구하기
	int root(int x) {
		if (par[x] == -1)	return x;
		else return par[x] = root(par[x]);
	}
	// x와 y가 같은 집합에 속하는지 확인
	bool issame(int x, int y) {
		if (x == y)	return true;
		return root(x) == root(y);
	}
	// 두 집합 합치기
	void unite(int x, int y) {
		if (x == y)	return;
		x = root(x); y = root(y);
		if (x == y)	return;
		if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		} else {
			par[y] = x;
			siz[x] += siz[y];
		}
		return;
	}
	// x를 포함하는 그룹의 크기 확인
	int size(int x) {
		return siz[root(x)];
	}
};

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	UnionFind uf(n);
	for (int i=0; i<m; i++) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 0)
			uf.unite(a, b);
		else {
			if (uf.issame(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}