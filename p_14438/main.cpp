#include <iostream>
#include <limits.h>
using namespace std;

int n, m;
int tree[400001], arr[100001];

void printer() {
	for (int i=1; i<=n; i++)
		cout << tree[i] << ' ';
	cout << endl;
}

int makeTree(int start, int end, int nodeIdx) {
	int mid;

	if (start == end)	return tree[nodeIdx] = arr[start];
	mid = (start + end) / 2;
	return tree[nodeIdx] = min(makeTree(start, mid, nodeIdx*2), makeTree(mid+1, end, nodeIdx*2+1));
}

int getPrefixMin(int start, int end, int left, int right, int nodeIdx) {
	int mid;

	if (right < start || end < left)
		return INT_MAX;
	if (left <= start && end <= right)
		return tree[nodeIdx];
	mid = (start + end) / 2;
	return min(getPrefixMin(start, mid, left, right, nodeIdx*2), getPrefixMin(mid+1, end, left, right, nodeIdx*2+1));
}

int changeNode(int start, int end, int changeIdx, int changeVal, int nodeIdx) {
	int mid;

	if (changeIdx < start || end < changeIdx) {
		return tree[nodeIdx];
	}
	if (start == end) {
		if (start == changeIdx) {
			return tree[nodeIdx] = changeVal;
		} else {
			return tree[nodeIdx];
		}
	}
	mid = (start + end) / 2;
	return tree[nodeIdx] = min(changeNode(start, mid, changeIdx, changeVal, nodeIdx*2), changeNode(mid+1, end, changeIdx, changeVal, nodeIdx*2+1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	makeTree(1, n, 1);

	cin >> m;
	int a, b, c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		if (a == 1)	changeNode(1, n, b, c, 1);
		else cout << getPrefixMin(1, n, b, c, 1) << '\n';
	}
}