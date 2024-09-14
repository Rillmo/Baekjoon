#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Line {
	double x1, y1, x2, y2;
};

double ccw(pair<double,double>& c1, pair<double,double>& c2, pair<double,double>& c3) {
	double s = (c1.first * c2.second + c2.first * c3.second + c3.first * c1.second)
		- (c2.first * c1.second + c3.first * c2.second + c1.first * c3.second);
	if (s < 0)	return 1;
	if (s > 0)	return -1;
	return 0;
}

bool checkOverlap(Line& a, Line& b) {
	pair<double,double> c1 = {a.x1, a.y1};
	pair<double,double> c2 = {a.x2, a.y2};
	pair<double,double> c3 = {b.x1, b.y1};
	pair<double,double> c4 = {b.x2, b.y2};

	double c1c2 = ccw(c1, c2, c3) * ccw(c1, c2, c4);
	double c3c4 = ccw(c3, c4, c1) * ccw(c3, c4, c2);
	if (c1c2 == 0 && c3c4 == 0) {
		if (c2 < c1) swap(c1, c2);
		if (c4 < c3) swap(c3, c4);
		return c1 <= c4 && c3 <= c2;
	}
	return c1c2 <= 0 && c3c4 <= 0;
}

struct Unionfind {
	vector<int> par, siz;

	Unionfind(int n): par(n+1, -1), siz(n+1, 1) {}

	int root(int x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}
	void unite(int x, int y) {
		if (x == y) return;
		x = root(x); y = root(y);
		if (x == y) return;
		if (siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		// cout << "siz[x] : " << siz[x] << " max: " << max_siz << endl;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	double n, x1, x2, y1, y2;
	cin >> n;
	vector<Line> list;
	Unionfind uf(n);
	
	for (int i=0; i<n; i++) {
		Line line;
		cin >> line.x1 >> line.y1 >> line.x2 >> line.y2;
		list.push_back(line);
	}
	for (int i=0; i<list.size()-1; i++) {
		for (int j=i+1; j<list.size(); j++) {
			if (uf.root(i) == uf.root(j)) continue;
			if (checkOverlap(list[i], list[j]))
				uf.unite(i, j);
		}
	}
	int count = 0;
	int max_siz = 1;
	for (int i=0; i<n; i++) {
		if (uf.par[i] == -1)
			count++;
		max_siz = max(max_siz, uf.siz[i]);
	}
	cout << count << '\n';
	cout << max_siz << '\n';
	// Line c1 = {-1, -1, 1, 1};
	// Line c2 = {-2, -2, 2, 2};
	// cout << "check: " << checkOverlap(c1, c2);
}