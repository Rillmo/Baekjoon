#include <iostream>
#include <vector>
using namespace std;

int n, arr[22][22];
bool team[22] = { false };
int mini = 200000000;

int calc() {
	int sum1 = 0, sum2 = 0;
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (team[i] && team[j])
				sum1 += arr[i][j] + arr[j][i];
			else if (!team[i] && !team[j])
				sum2 += arr[i][j] + arr[j][i];
		}
	}
	return abs(sum1-sum2);
}

void comb(int idx, int count) {
	if (count > n/2)	return ;
	if (count > 0)
		mini = min(calc(), mini);
	for (int i=idx; i<n; i++) {
		team[i] = true;
		comb(i+1, count+1);
		team[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cin >> arr[i][j];
	}
	comb(0, 0);
	cout << mini << endl;
}