#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef struct _modQ {
	int cidx;
	int cval;
}	modQ;
typedef struct _sumQ {
	int id;
	int k;
	int left;
	int right;
}	sumQ;
ll arr[100001];
ll tree[400001];

ll makeSegTree(ll start, ll end, ll nodeIdx) {
	ll mid;

	if (start == end)
		return tree[nodeIdx] = arr[start];
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

bool myComp(const sumQ &v1, const sumQ &v2) {
	if (v1.k < v2.k)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, type, k;
	vector< modQ > modQList;
	vector< sumQ > sumQList;

	// input
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	cin >> m;

	// make segTree
	makeSegTree(0, n-1, 1);

	int id = 0;
	sumQ tmpsq;
	modQ tmpmq;
	// excute
	for (int i=0; i<m; i++) {
		cin >> type;
		if (type == 1) {
			cin >> tmpmq.cidx;
			cin >> tmpmq.cval;
			modQList.push_back(tmpmq);
		} else if (type == 2) {
			tmpsq.id = id++;
			cin >> tmpsq.k;
			cin >> tmpsq.left;
			cin >> tmpsq.right;
			sumQList.push_back(tmpsq);
		}
	}

	sort(sumQList.begin(), sumQList.end(), myComp);
	// printer2(sumQList);
	
	int count = 0, idx =0;
	ll diff;
	ll res[id+1];

	for (sumQ sq : sumQList) {
		// cout << sumQList[i].id << ":" << sumQList[i].k << "(" << sumQList[i].left << "," << sumQList[i].right << ") ";
		while (idx < sq.k) {
			int cidx = modQList[idx].cidx - 1;
			int cval = modQList[idx].cval;
			diff = cval - arr[cidx];
			arr[cidx] = cval;
			changeNode(0, n-1, modQList[idx].cidx - 1, diff, 1);
			idx++;
		}
		res[sq.id] = getPrefixSum(0, n - 1, sq.left-1, sq.right-1, 1);
	}

	for (int i=0; i<id; i++)
		cout << res[i] << '\n';
}
