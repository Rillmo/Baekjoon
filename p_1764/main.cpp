#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	unordered_map<string, bool> umap;
	vector<string> res;
	string tmp;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> tmp;
		umap[tmp] = true;
	}
	for (int i=0; i<m; i++) {
		cin >> tmp;
		if (umap[tmp])
			res.push_back(tmp);
	}
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (auto &s : res)
		cout << s << '\n';
}