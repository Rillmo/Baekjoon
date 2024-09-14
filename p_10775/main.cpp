#include <iostream>
#include <vector>
using namespace std;

struct Unionfind {
	vector<int> par;
	Unionfind(int n) :par(n+1, 0) {
		for (int i=0; i<n; i++)
			par[i] = i;
	}
	int root(int x) {
		if (par[x] == x) return x;
		else return par[x] = root(par[x]);
	}
	void unite(int x, int y) {
		if (x == y) return ;
		x = root(x); y = root(y);
		if (x == y) return ;
		if (x > y) swap(x, y);
		par[y] = x;
	}
};

int main() {
	int g, p;
	cin >> g >> p;
	vector<int> plane(p, 0), gate(g, 0);
	Unionfind uf(g);
	for (int i=0; i<p; i++)
		cin >> plane[i];
	int count = 0;
	for (int i=0; i<p; i++) {
		int idx = plane[i] - 1;
		if (gate[idx] == 0 && i > 1 && gate[idx-1] == 1)
			uf.unite(idx, idx-1);
		while (gate[idx] != 0) {
			idx = uf.root(idx);
			--idx;
			if (gate[idx] == 0)
				uf.unite(idx, idx+1);
		}
		if (idx < 0) break;
		gate[idx]++;
		// cout << "______\n";
		// for (int j=0; j<g; j++) {
		// 	cout << gate[j] << ' ';
		// }
		// cout << '\n';
		// for (int j=0; j<g; j++) {
		// 	cout << uf.par[j] << ' ';
		// }
		// cout << "\n";
		count++;
	}
	// for (int i=0; i<p; i++)
	// 	cout << gate[i] << ' ';
	// cout << endl;
	cout << count;
}