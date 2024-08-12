#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, num, tmp1, tmp2;
	priority_queue<int> maxpq;
	priority_queue<int, vector<int>, greater<int> > minpq;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num;
		if (maxpq.size() <= minpq.size())
			maxpq.push(num);
		else
			minpq.push(num);
		if (maxpq.size() > 0 && minpq.size() > 0 && maxpq.top() > minpq.top()) {
			tmp1 = maxpq.top();
			maxpq.pop();
			tmp2 = minpq.top();
			minpq.pop();
			maxpq.push(tmp2);
			minpq.push(tmp1);
		}
		cout << maxpq.top() << '\n';
	}
}
