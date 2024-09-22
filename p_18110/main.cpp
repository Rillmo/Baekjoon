#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	double n, cut;
	vector<int> vec;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	cut = round(n * 0.15);
	for (int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	double sum = 0;
	for (int i=cut; i<vec.size()-cut; i++)
		sum += vec[i];
	cout << round(sum / (n-cut*2));
}