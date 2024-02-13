#include <iostream>
#include <algorithm>
using namespace std;

char	**board;
int		n, m;
int	vertexX[4] = {0, 7, 0, 7};
int	vertexY[4] = {0, 0, 7, 7};

int	countWrong(int y, int x) {
	char	flag;
	int		minimum = 2147483647;
	int		count;

	for (int k=0; k<4; k++) {
		flag = board[y + vertexY[k]][x + vertexX[k]];
		count = 0;
		for (int i=y; i<y+8; i++) {
			for (int j=x; j<x+8; j++) {
				if ((i % 2 == j % 2) && board[i][j] != flag) {
					count++;
				}
				else if ((i % 2 != j % 2) && board[i][j] == flag) {
					count++;
				}
			}
		}
		minimum = min(minimum, count);
	}
	return minimum;
}

int main() {
	int	minimum;

	cin >> n;
	cin >> m;
	board = new char*[n];
	for (int i=0; i<n; i++) {
		board[i] = new char[m];
		for (int j=0; j<m; j++)
			cin >> board[i][j];
	}
	minimum = 2147483647;
	for (int i=0; i<=n - 8; i++) {
		for (int j=0; j<=m - 8; j++) {
			minimum = min(minimum, countWrong(i, j));
		}
	}
	cout << minimum << endl;
}