#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tmp, maxi = -1, maxv;
	double sum = 0, n;
	bool flag = false;
	vector<int> vec;
	map<int, int> m;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> tmp;
		m[tmp]++;
		maxi = max(maxi, m[tmp]);
		vec.push_back(tmp);
		sum += tmp;
	}
	vector<int> newv;
	for (auto& pair : m) {
		if (pair.second == maxi)
			newv.push_back(pair.first);
	}
	sort(newv.begin(), newv.end());
	sort(vec.begin(), vec.end());
	int res1 = round(sum / n);
	if (res1 == -0)	res1 = 0;
	cout << res1 << '\n';
	cout << vec[vec.size()/2] << '\n';
	if (newv.size() == 1)
		cout << newv[0] << '\n';
	else
		cout << newv[1] << '\n';
	cout << vec[vec.size()-1] - vec[0];
}