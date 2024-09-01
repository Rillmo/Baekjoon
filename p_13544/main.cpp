#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, last_ans;
int arr[100001];
vector<int> tree[400001];

void vprinter(vector<int>& v) {
	if (v.size() <= 0)	return ;
	cout << "[";
	for (size_t i=0; i<v.size(); i++)
		cout << v[i] << ' ';
	cout << "]\n";
}

void make_tree(int start, int end, int nidx) {
	if (start == end) {
		tree[nidx].push_back(arr[start]);
		return ;
	}
	int mid = (start + end) / 2;
	make_tree(start, mid, nidx*2);
	make_tree(mid+1, end, nidx*2+1);
	tree[nidx].resize(end-start+1);
	merge(tree[nidx*2].begin(), tree[nidx*2].end(), tree[nidx*2+1].begin(), tree[nidx*2+1].end(), tree[nidx].begin());
}

int get_prefix(int start, int end, int left, int right, int nidx) {
	if (right < start || end < left)	return 0;
	if (left <= start && end <= right) {
		return tree[nidx].end() - upper_bound(tree[nidx].begin(), tree[nidx].end(), k);
	}
	int mid = (start + end) / 2;
	return get_prefix(start, mid, left, right, nidx*2) + get_prefix(mid+1, end, left, right, nidx*2+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	last_ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	make_tree(1, n, 1);

	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> k;
		k = k ^ last_ans;
		last_ans = get_prefix(1, n, a ^ last_ans, b ^ last_ans, 1);
		cout << last_ans << '\n';
	}
}
