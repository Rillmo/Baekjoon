#include <iostream>
#include <iomanip>
using namespace std;

int T;
int num, M = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	vector<int> input(T, 0);
	
	for (int i=0; i < T; i++) {
		cin >> input[i];
		M = max(input[i], M);
	}

	vector<long double> dp(M, 0);
	for (int i=1; i<=M; i++) {
		for (int j=i; j<=M; j+=i) {	// j는 i의 배수이다
			dp[j] += i;
		}
		dp[i] += dp[i-1];
	}

	for (int i=0; i<T; i++) {
		cout << fixed << setprecision(0) << dp[input[i]] << "\n";
	}
}
