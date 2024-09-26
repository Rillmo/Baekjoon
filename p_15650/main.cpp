#include <iostream>
#include <vector>
using namespace std;

int n, m;
// vector<vector<int>> graph;
vector<int> res;

void printer() {
	for (int i=0; i<res.size(); i++)
		cout << res[i] << ' ';
	cout << endl;
}

void back_tracking(int idx, int val) {
	res[idx] = val;
	if (idx == m-1) printer();
	// printer();
	for (int i=val+1; i<=n; i++) {
		if (idx+1 < m)
			back_tracking(idx+1, i);
	}
}

int main() {
	cin >> n >> m;
	// graph.assign(n+1, vector<int>(n+1, 0));
	for (int i=1; i<=n-m+1; i++) {
		res.assign(m, 0);
		back_tracking(0, i);
	}
}