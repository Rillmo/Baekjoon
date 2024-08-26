#include <iostream>
using namespace std;

int n, m, maxval = -1;
int board[600][600];
bool visited[600][600] = {false};
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void tetromino(int i, int j, int count, int sum) {
	int ni, nj;
	if (count == 4) {
		maxval = max(maxval, sum);
	}
	else {
		for (int k=0; k<4; k++) {
			ni = i + dy[k];
			nj = j + dx[k];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
				visited[ni][nj] = true;
				tetromino(ni, nj, count+1, sum + board[ni][nj]);
				visited[ni][nj] = false;
			}
		}
	}
}

int get_purple(int i, int j) {
	int sum = board[i][j];
	int minval = 2000;
	int count = 0;
	for (int k=0; k<4; k++) {
		int ni = i + dy[k];
		int nj = j + dx[k];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
			minval = min(minval, board[ni][nj]);
			count++;
			sum += board[ni][nj];
		}
	}
	if (count >= 4)	sum -= minval;
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// input
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cin >> board[i][j];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			visited[i][j] = true;
			tetromino(i, j, 1, board[i][j]);
			visited[i][j] = false;
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m ;j++) {
			maxval = max(maxval, get_purple(i, j));
		}
	}
	cout << maxval << '\n';
}