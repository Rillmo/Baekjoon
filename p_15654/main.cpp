#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int,int>;

int n, m, tmp;
vector<int> list;
deque<int> res;
vector<int> check;

void print() {
	for (int i=0; i<res.size(); i++)
		cout << res[i] << ' ';
	cout << '\n';
}

void back_tracking(int depth) {
	if (depth == m) print();
	for (int i=0; i<n; i++) {
		if (find(res.begin(), res.end(), list[i]) != res.end())
			continue;
		res.push_back(list[i]);
		back_tracking(depth+1);
		res.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> tmp;
		list.push_back(tmp);
	}
	sort(list.begin(), list.end());
	back_tracking(0);
}