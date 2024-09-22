#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int,int>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<ii> vec;
	for (int i=0; i<n; i++) {
		int x,y;
		cin >> x >> y;
		vec.push_back({x,y});
	}
	for (int i=0; i<vec.size(); i++) {
		int count = 0;
		for (int j=0; j<vec.size(); j++) {
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second)
				count++;
		}
		cout << count+1 << ' ';
	}
}