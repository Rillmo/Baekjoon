#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int test, k;
	int arr[502], sum[502];
	int dp[502][502];
	cin >> test;
	for (int t=0; t<test; t++) {
		cin >> k;
		for (int i=1; i<=k; i++) {
			cin >> arr[i];
			sum[i] = sum[i-1] + arr[i];
		}
		for (int i=1; i<k; i++) {	// 범위값(몇개씩 비교할건지)
			for (int j=1; j+i<=k; j++) {	// 어디부터 시작할지
				int x = j, y = x+i;
				dp[x][y] = INT_MAX;
				// cout << "_____" << x << "~" << y << endl;
				for (int mid=x; mid<y; mid++) {	// 나누는 기준점
					dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y]-sum[x-1]);
					// cout << x << "~" << mid << " + " << mid+1 << "~" << y << ": " << dp[x][y] << endl;
				}
			}
		}
		cout << dp[1][k] << '\n';
	}
}