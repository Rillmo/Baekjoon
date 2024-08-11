#include <iostream>
using namespace std;
typedef long long ll;

ll arr[4000000];
ll tree[4000000];

ll makeSegTree(int start, int end, int node) {
	int mid;

	if (start == end)
		return tree[node] = arr[start];
	mid = (start + end) / 2;
	return tree[node] = (makeSegTree(start, mid, node * 2) * makeSegTree(mid + 1, end, node * 2 + 1)) % 1000000007;
}

ll getNode(int start, int end, int left, int right, int node) {
	int mid;

	if (right < start || end < left)	return 1;
	if (left <= start && end <= right)	return tree[node];
	mid = (start + end) / 2;
	return (getNode(start, mid, left, right, node * 2) * getNode(mid + 1, end, left, right, node * 2 + 1)) % 1000000007;
}

void changeNode(int start, int end, int cidx, ll newV, int node) {
	int mid;

	if (cidx < start || end < cidx)		return ;
	mid = (start + end) / 2;
	if (start == end) {
		tree[node] = newV;
		return ;
	}
	changeNode(start, mid, cidx, newV, node * 2);
	changeNode(mid + 1, end, cidx, newV, node * 2 + 1);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}

void printer(ll *toprint, int n) {
	for (int i=0; i<n; i++) {
		cout << toprint[i] << " ";
	}
	cout << endl;
}

int main() {
	int m, n, k, a, b, c;
	ll orgV;

	// input
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	// make segtree
	makeSegTree(0, n-1, 1);

	// execute
	for (int i=0; i<m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b-1] = c;
			changeNode(0, n-1, b-1, c, 1);
		} else if (a == 2) {
			cout << getNode(0, n-1, b-1, c-1, 1) % 1000000007 << endl;
		}
	}
}