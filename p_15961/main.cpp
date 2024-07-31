#include <iostream>
#include <unordered_map>
using namespace std;

int n, d, k, c;
unordered_map<int, int>m; 
int add, del, score = 0, best;
int arr[3000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> d;
	cin >> k;
	cin >> c;

	for (int i=0; i<n; i++)
		cin >> arr[i];

	m[c]++;
	score++;

	for (int i=0; i<k-1; i++) {
		if (m[arr[i]] == 0)
			score++;
		m[arr[i]]++;
	}
	best = score;

	for (int i=0; i<n; i++) {
		add = (i + k - 1) % n;
		if (m[arr[add]]++ == 0) score++;
		best = max(best, score);
		del = i % n;
		if (m[arr[del]] >= 1)	m[arr[del]]--;
		if (m[arr[del]] == 0) 	score--;
	}

	cout << best << endl;

}