#include <iostream>
#include <map>
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
		return root(x) == root(y);
	}
	void unite(int x, int y) {
		if (x == y) return ;
		x = root(x); y = root(y);
		if (x == y) return ;
		if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		} else {
			par[y] = x;
			siz[x] += siz[y];
		}
	}
	int size(int x) {
		return siz[root(x)];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	map<string, int> users;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> m;
		int id = 0;
		Unionfind uf(m*2);
		string user1, user2;
		for (int j=0; j<m; j++) {
			cin >> user1 >> user2;
			int id1, id2;
			if (users.find(user1) == users.end()) {
				users[user1] = id;
				id1 = id;
				id++;
			}
			else
				id1 = users[user1];
			if (users.find(user2) == users.end()) {
				users[user2] = id;
				id2 = id;
				id++;
			}
			else
				id2 = users[user2];
			// cout << id1 << "/" << id2 << '\n';
			uf.unite(id1, id2);
			cout << uf.size(id1) << '\n';
		}
	}
}