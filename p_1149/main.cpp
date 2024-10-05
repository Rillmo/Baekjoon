#include <iostream>
using namespace std;

int n;
int dp[1001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<3; j++)
			cin >> dp[i][j];
	}

	for (int i=1; i<=n; i++) {
		dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
	}

	cout << min(dp[n][0],min(dp[n][1],dp[n][2]));

	/*
		변수 : 각 층의 r, g, b중 무엇을 선택할 것인가?
		변수에 따른 변화 : 각 층의 선택에 따라 전체 합이 달라진다.

		변수 통제가 가능한가?? 즉 모든 경우를 고려했는가?
		각 층마다 r, g, b 선택 결과를 모두 저장한다.
		각 선택마다, 상위 층과의 합 중 최솟값을 저장한다.
		결론적으로 매 층마다 선택 결과를 모두 고려하고, 각 선택 결과마다의 최솟값을 알고 있기 때문에
		모든 층을 순회했을 때 마지막 층에서의 r,g,b중 최솟값이 전체 최소가 된다.
	*/
}