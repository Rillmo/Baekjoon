#include <iostream>
#include <vector>
using namespace std;

struct Unionfind {
	vector<int> par, siz;
	Unionfind(int n): par(n+1, -1), siz(n+1, 1) {}

	int root(int x) {
		if (par[x] == -1)	return x;
		else return par[x] = root(par[x]);
	}
	bool issame(int x, int y) {
		if (x == y)	return true;
		return root(x) == root(y);
	}
	void unite(int x, int y) {
		if (x == y)	return ;
		x = root(x); y = root(y);
		if (x == y)	return ;
		if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		} else {
			par[y] = x;
			siz[x] += siz[y];
		}
	}
	void print() {
		for (int i=0; i<par.size(); i++)
			cout << i << '\t';
		cout << '\n';
		for (int i=0; i<par.size(); i++)
			cout << par[i] << '\t';
		cout << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, num, tmp, first, count=0;
	vector<int> truth;
	vector<int> party[51];

	cin >> n >> m;
	Unionfind uf(n);
	// 진실을 아는 사람들
	cin >> num;
	for (int i=0; i<num; i++) {
		cin >> tmp;
		truth.push_back(tmp);
	}
	// 파티
	for (int i=0; i<m; i++) {
		cin >> num;
		cin >> first;
		party[i].push_back(first);
		for (int j=0; j<num-1; j++) {
			cin >> tmp;
			party[i].push_back(tmp);
			uf.unite(first, tmp);
		}
	}
	// uf.print();
	for (int k=0; k<m; k++) {
		bool can_lie = true;
		for (int i=0; i<party[k].size(); i++) {
			int person = party[k][i];
			for (int j=0; j<truth.size(); j++) {
				if (uf.root(truth[j]) == uf.root(person)) {
					can_lie = false;
					goto here;
				}
			}
		}
		here:
		if (can_lie) count++;
	}
	cout << count;
}