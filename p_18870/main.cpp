#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec, org;
	for (int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
		org.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
    auto last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
	map<int, int> m;
	for (int i=0; i<vec.size(); i++)
		m[vec[i]] = i;
	for (auto i : org)
		cout << m[i] << ' ';
}