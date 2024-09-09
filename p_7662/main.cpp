#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int test;
	cin >> test;
	for (int t=0; t<test; t++) {
		multiset<int> mset;
		int k;
		cin >> k;
		char oper;
		int val;
		for (int i=0; i<k; i++) {
			cin >> oper >> val;
			if (oper == 'I') {
				mset.insert(val);
			} else if (oper == 'D') {
				auto it = mset.begin();
				if (mset.empty())
					continue;
				if (val == -1) {
					it = mset.erase(mset.begin());
				}
				else if (val == 1) {
					it = mset.end();
					it = mset.erase(--it);
				}
			}
		}
		if (mset.empty())
			cout << "EMPTY" << '\n';
		else {
			auto it = mset.end();
			cout << *(--it) << ' ' << *(mset.begin())  << '\n';
		}
	}
}