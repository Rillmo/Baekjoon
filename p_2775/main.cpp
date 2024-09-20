#include <iostream>
using namespace std;

int apart(int k, int n) {
	int ap[20][20] = {0};

	for (int i=0; i<=14; i++)
		ap[0][i] = i;
	for (int i=1; i<=k; i++) {
		for (int j=1; j<=n; j++) {
			ap[i][j] = ap[i][j-1] + ap[i-1][j];
		}
	}
	// for (int i=0; i<=14; i++) {
	// 	for (int j=0; j<=14; j++)
	// 		cout << ap[i][j] << ' ';
	// 	cout << endl;
	// }
	return ap[k][n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, k, n;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> k >> n;
		cout << apart(k, n) << '\n';
	}
}