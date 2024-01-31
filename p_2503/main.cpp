#include <iostream>
#include <algorithm>
using namespace std;
	
int n;
int	result[3];
int **list;
int count = 0;

void	checkBalls(int idx) {
	if (idx == n)
		return;
	if (list[idx][3] == 1) {
		for (int i=0; i < 3; i++) {
			if (result[i] != 0)
				result[i] = list[idx][i];
			
		}
	}
	list[idx][0]
}

int main() {
	string line;

	cin >> n;
	list = (int **)calloc(n, sizeof(int *));
	for (int i=0; i<n; i++) {
		cin >> line;
		list[i] = (int *)calloc(5 , sizeof(int));
		for (int j=0; j<3; j++) {
			list[i][j] = line.at(j) - '0';
		}
		cin >> list[i][3];
		cin >> list[i][4];
	}

	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<5; j++)
	// 		cout << list[i][j];
	// 	cout << endl;
	// }

	
}