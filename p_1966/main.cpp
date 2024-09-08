#include <iostream>
#include <queue>
using namespace std;

struct Data {
	int val;
	bool ans;
};

int test, n, m;

int simulate(queue<Data>& que, priority_queue<int>& pque) {
	int count = 0;
	int ret;
	while (!pque.empty()) {
		int maxi = pque.top();
		pque.pop();
		Data tmp;
		do {
			tmp = que.front();
			que.pop();
			que.push(tmp);
		} while (maxi != tmp.val);
		count++;
		// cout << "test: (" <<  tmp.val << "," << tmp.ans << ") " << "count: " << count << endl;
		if (tmp.ans) ret = count;
	}
	return ret;
}

int main() {
	cin >> test;
	for (int t=0; t<test; t++) {
		cin >> n >> m;
		int tmp;
		queue<Data> que;
		priority_queue<int> pque;
		// cout << "_______" << endl;
		for (int i=0; i<n; i++) {
			cin >> tmp;
			if (i == m)
				que.push({tmp, true});
			else
				que.push({tmp, false});
			pque.push(tmp);
		}
		cout << simulate(que, pque) << '\n';
	}
}