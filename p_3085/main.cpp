#include <iostream>
#include <algorithm>
using namespace std;

int	n;
char **list;
int	M = -1;

void	print() {
	cout << "==============" << endl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << list[i][j];
		}
		cout << endl;
	}
	cout << "==============" << endl;
}

void	swap(int x1, int y1, int x2, int y2) {
	char tmp;

	tmp = list[y1][x1];
	list[y1][x1] = list[y2][x2];
	list[y2][x2] = tmp;
}

char	*lineToArr(string line) {
	char *result;

	result = (char *)calloc(line.length(), sizeof(char));
	for (int i=0; i<line.length(); i++) {
		result[i] = line.at(i);
	}
	return result;
}

void findMaxLine() {
	int count;

	// find in row
	for (int i=0; i<n; i++) {
		count = 1;
		for (int j=0; j<n-1; j++) {
			if (list[i][j] == list[i][j + 1])
				count++;
			else {
				M = max(M, count);
				count = 1;
			}
		}
		M = max(M, count);
	}
	// find in col
	for (int i=0; i<n; i++) {
		count = 1;
		for (int j=0; j<n-1; j++) {
			if (list[j][i] == list[j + 1][i])
				count++;
			else {
				M = max(M, count);
				count = 1;
			}
		}
		M = max(M, count);
	}
}

int	swapInRow() {
	// select two adjacent spaces (row)
	for (int i=0; i<n; i++) {
		for (int j=0; j<n - 1; j++) {
			if (list[i][j] != list[i][j + 1]) {
				swap(j, i, j + 1, i);
				findMaxLine();
				swap(j, i, j + 1, i);
			}
		}
	}
	return (1);
}

int swapInCol() {
	// select two adjacent spaces (col)
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-1; j++) {
			if (list[j][i] != list[j + 1][i]) {
				swap(i, j, i, j + 1);
				findMaxLine();
				swap(i, j, i, j + 1);
			}
		}
	}
	return (1);
}

int main() {
	cin >> n;

	list = (char **)calloc(n, sizeof(char *));
	string line;
	for (int i=0; i<n; i++) {
		cin >> line;
		list[i] = lineToArr(line);
	}

	swapInRow();
	swapInCol();

	cout << M << endl;	
}