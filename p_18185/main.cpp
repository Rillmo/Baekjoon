#include <iostream>
using namespace std;

int main() {
	int n;
	int cost;
	int	*list;
	int	j;

	cin >> n;
	list = new int[n];
	for (int i=0; i<n; i++) {
		cin >> list[i];
	}
	j = 0;
	cost = 0;
	while (j < n) {
		while (list[j] > 0) {
			if (j < n - 2 && list[j] <= list[j+ 1] && list[j + 1] <= list[j + 2]) {
				list[j]--; list[j + 1]--; list[j + 2]--;
				cost += 7;
			}
			else if (j < n - 1 && list[j] <= list[j + 1]) {
				list[j]--; list[j + 1]--;
				cost += 5;
			}
			else {
				list[j]--;
				cost += 3;
			}
		}
		j++;
	}
	cout << cost << endl;
}