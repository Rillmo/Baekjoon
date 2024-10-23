#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int,int>;


int main() {
	int n, k, tmp, m, v;
	long long sum = 0;
	cin >> n >> k;
	priority_queue<int> pq;
	vector<ii> jewel;
	vector<int> bag;
	for (int i=0; i<n; i++) {
		cin >> m >> v;
		jewel.push_back({m, v});
	}
	for (int i=0; i<k; i++) {
		cin >> tmp;
		bag.push_back(tmp);
	}
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
	// cout << "____bag____\n";
	// for (int i=0; i<bag.size(); i++)
	// 	cout << bag[i] << ' ';
	// cout << endl;
	// cout << "____jewel____\n";
	// for (int i=0; i<jewel.size(); i++)
	// 	cout << jewel[i].first << '(' << jewel[i].second << ") ";
	// cout << endl;

	int idx = 0;
	for (int i=0; i<k; i++) {
		while (idx < n && jewel[idx].first <= bag[i]) pq.push(jewel[idx++].second);
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << '\n';
}
