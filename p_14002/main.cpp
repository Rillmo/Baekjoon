#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, arr[1001], dp[1001], maxl = -1, maxi;
vector<int> lis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> arr[0];
	dp[0] = 1;
	for (int i=1; i<n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j=i-1; j>=0; j--) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}

	for (int i=0; i<n; i++) {
		if (maxl < dp[i]) {
			maxl = dp[i];
			maxi = i;
		}
	}

	for (int j=maxi; j>=0; j--) {
		if (dp[j] == maxl) {
			lis.push_back(arr[j]);
			maxl--;
		}
	}

	cout << lis.size() << '\n';
	for (int i=lis.size()-1; i>=0; i--) {
		cout << lis[i] << ' ';
	}
}