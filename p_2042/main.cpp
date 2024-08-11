#include <iostream>
#include <vector>
using namespace std;

// 1 2 3 4 5

typedef long long ll;
vector<ll> org;
ll tree[4000000];

ll makeSegTree(ll start, ll end, ll nodeIdx) {
	ll mid;

	if (start == end)
		return tree[nodeIdx] = org[start];
	mid = (start + end) / 2;
	return tree[nodeIdx] = makeSegTree(start, mid, nodeIdx * 2) + makeSegTree(mid + 1, end, nodeIdx * 2 + 1);
}

ll getPrefixSum(ll start, ll end, ll left, ll right, ll nodeIdx) {
	ll mid;

	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[nodeIdx];
	mid = (start + end) / 2;
	return getPrefixSum(start, mid, left, right, nodeIdx * 2) + getPrefixSum(mid + 1, end, left, right, nodeIdx * 2 + 1);
}

void changeNode(ll start, ll end, ll changeIdx, ll diff, ll nodeIdx) {
	ll mid;

	if (changeIdx < start || end < changeIdx)
		return ;

	tree[nodeIdx] += diff;
	mid = (start + end) / 2;
	if (start == end)	return;
	changeNode(start, mid, changeIdx, diff, nodeIdx * 2);
	changeNode(mid + 1, end, changeIdx, diff, nodeIdx * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, k, tmp, a, b, c;
	ll res[10000];

	// input
	cin >> n >> m >> k;
	for (ll i=0; i<n; i++) {
		cin >> tmp;
		org.push_back(tmp);
	}

	// make segment tree
	makeSegTree(0, n - 1, 1);

	// calculate with segtree
	for (ll i=0, j=0; i<m + k; i++) {
		cin >> a >> b >> c;
		if (a == 2) {
			res[j++] = getPrefixSum(0, n - 1, b - 1, c - 1, 1);
		} else if (a == 1) {
			ll diff = c - org[b - 1];
			org[b-1] = c;
			changeNode(0, n-1, b - 1, diff, 1);
		}
	}

	for (ll i=0; i<k; i++)
		cout << res[i] << endl;
}