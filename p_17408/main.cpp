#include <iostream>
using namespace std;

typedef struct _node {
	int val;
	int elem[2];
}	node;

int n, m;
int arr[100001];
node tree[400000];

node& comp_node(node n1, node n2) {
	int maxi = -1;
	node *ret = new node;

	if (maxi < n1.val) {
		ret->elem[0] = n1.elem[0];
		ret->elem[1] = n1.elem[1];
		maxi = n1.val;
	}
	if (maxi < n2.val) {
		ret->elem[0] = n2.elem[0];
		ret->elem[1] = n2.elem[1];
		maxi = n2.val;
	}
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			if (maxi < n1.elem[i] + n2.elem[j]) {
				ret->elem[0] = n1.elem[i];
				ret->elem[1] = n2.elem[j];
				maxi = n1.elem[i] + n2.elem[j];
			}
		}
	}
	ret->val = maxi;
	return *ret;
}

node make_tree(int start, int end, int nidx) {
	int mid;

	if (start == end) {
		tree[nidx].elem[0] = 0;
		tree[nidx].elem[1] = arr[start];
		tree[nidx].val = tree[nidx].elem[0] + tree[nidx].elem[1];
		// cout << "(" << start << "~" << end << "): [" << tree[nidx].elem[0] << "," << tree[nidx].elem[1] << "] " << tree[nidx].val << endl;
		return tree[nidx];
	}
	mid = (start+end)/2;
	tree[nidx] = comp_node(make_tree(start, mid, nidx*2), make_tree(mid+1, end, nidx*2+1));
	// cout << "(" << start << "~" << end << "): [" << tree[nidx].elem[0] << "," << tree[nidx].elem[1] << "] " << tree[nidx].val << endl;
	return tree[nidx];
}

node& get_prefix(int start, int end, int left, int right, int nidx) {
	int mid;

	if (right < start || end < left) {
		node *empty_node = new node;
		empty_node->elem[0] = 0;
		empty_node->elem[1] = 0;
		empty_node->val = 0;
		// cout << "(" << start << "~" << end << "): 범위 아웃" << endl;
		return *empty_node;
	}
	if (left <= start && end <= right) {
		// cout << "범위내(" << start << "~" << end << "): [" << tree[nidx].elem[0] << "," << tree[nidx].elem[1] << "] " << tree[nidx].val << endl;
		return tree[nidx];
	}
	mid = (start+end)/2;
	// cout << "(" << start << "~" << end << "): [" << ret.elem[0] << "," << ret.elem[1] << "] " << ret.val << endl;
	return comp_node(get_prefix(start, mid, left, right, nidx*2), get_prefix(mid+1, end, left, right, nidx*2+1));
}

node change_node(int start, int end, int changeIdx, int changeVal, int nidx) {
	int mid;

	if (changeIdx < start || end < changeIdx)
		return tree[nidx];
	if (start == end) {
		if (start == changeIdx) {
			tree[nidx].elem[0] = 0;
			tree[nidx].elem[1] = changeVal;
			tree[nidx].val = tree[nidx].elem[0] + tree[nidx].elem[1];
		}
		// cout << "(" << start << "~" << end << "): [" << tree[nidx].elem[0] << "," << tree[nidx].elem[1] << "] " << tree[nidx].val << endl;
		return tree[nidx];
	}
	mid = (start+end)/2;
	tree[nidx] = comp_node(change_node(start, mid, changeIdx, changeVal, nidx*2), change_node(mid+1, end, changeIdx, changeVal, nidx*2+1));
	// cout << "(" << start << "~" << end << "): [" << tree[nidx].elem[0] << "," << tree[nidx].elem[1] << "] " << tree[nidx].val << endl;
	return tree[nidx];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> arr[i];

	// cout << "____making tree____\n";
	make_tree(1, n, 1);
	cin >> m;
	int a, b, c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			// cout << "____changing node___\n";
			arr[b] = c;
			change_node(1, n, b, c, 1);
		} else {
			// cout << "____get_prefix____" << b << "~" << c <<"\n";
			cout << get_prefix(1, n, b, c, 1).val << '\n';
		}
	}
}