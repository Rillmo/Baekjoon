#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long ll;

int n;
ll arr[100001], maxi;
ll tree[400001];

ll tree_init(int start, int end, int nidx) {
	if (start == end)
		return tree[nidx] = start;
	int mid = (start+end)/2;
	ll lv = tree_init(start, mid, nidx*2);
	ll rv = tree_init(mid+1, end, nidx*2+1);
	return tree[nidx] = arr[lv] < arr[rv] ? lv : rv;
}

ll get_prefix(int start, int end, int left, int right, int nidx) {
	if (right < start || end < left) {
		// cout << start << "~" << end << ": 범위아웃" << endl;
		return INT_MAX;
	}
	if (left <= start && end <= right) {
		// cout << start << "~" << end << ": " << tree[nidx] << endl;
		return tree[nidx];
	}
	int mid = (start+end)/2;
	ll lv = get_prefix(start, mid, left, right, nidx*2);
	ll rv = get_prefix(mid+1, end, left, right, nidx*2+1);
	// cout << start << "~" << end << ": " << lv << "/" << rv << endl;
	if (lv == INT_MAX)	return rv;
	else if (rv == INT_MAX)	return lv;
	else	return arr[lv] < arr[rv] ? lv : rv;
}

void div_conq(ll left, ll right) {
	if (right < left)
		return ;
	// cout << "탐색범위" << left << "~" << right << "\n";
	ll min_idx = get_prefix(1, n, left, right, 1);
	// cout << "결과: " << min_idx << endl;
	maxi = max(maxi, arr[min_idx] * (right-left+1));
	div_conq(left, min_idx-1);
	div_conq(min_idx+1, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> n;
		if (n == 0)
			return 0;
		for (int i=1; i<=n; i++)
			cin >> arr[i];
		tree_init(1, n, 1);
		// cout << endl;
		// for (int i=1; i<=n; i++)
		// 	cout << tree[i] << ' ';
		// cout << endl;
		maxi = -1;
		div_conq(1, n);
		cout << maxi << endl;
		// cout << get_prefix(1, n, 1, 4, 1) << '\n';
	}
}