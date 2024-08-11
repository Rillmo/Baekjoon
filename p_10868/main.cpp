#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll arr[100001];
ll tree[400001];

ll myMin(ll n1, ll n2) {
	if (n1 < 1)
		return n2;
	else if (n2 < 1)
		return n1;
	else
		return min(n1, n2);
}

ll makeSegTree(int start, int end, int node) {
	int mid;

	if (start == end)
		return tree[node] = arr[start];
	mid = (start + end) / 2;
	return tree[node] = min(makeSegTree(start, mid, node * 2), makeSegTree(mid+1, end, node*2 + 1));
}

ll getNode(int start, int end, int left, int right, int node) {
	int mid;

	if (right < start || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];
	mid = (start + end) / 2;
	return myMin(getNode(start, mid, left, right, node * 2), getNode(mid+1, end, left, right, node * 2 + 1));
}

void printer(ll *toprint, int n) {
	for (int i=0; i<n; i++) {
		cout << toprint[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b;

	// input
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];

	// make segTree
	makeSegTree(0, n-1, 1);

	vector<ll> res;
	// excute
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		res.push_back(getNode(0, n-1, a-1, b-1, 1));
	}

	for (int i=0; i<res.size(); i++)
		cout << res[i] << '\n';
}