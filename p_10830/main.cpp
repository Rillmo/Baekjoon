#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int a[6][6];
int ans[6][6];
int n;
ll b;

void mMulti(int m1[6][6], int m2[6][6]) {
	int res[6][6];

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			res[i][j] = 0;
			for (int k=0; k<n; k++) {
				res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % 1000;
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			m1[i][j] = res[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n >> b;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
		ans[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1)
			mMulti(ans, a);
		mMulti(a, a);
		b /= 2;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
}