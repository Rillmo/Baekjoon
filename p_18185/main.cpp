#include <iostream>
using namespace std;

int main() {
	int n;
	int b, c;
	unsigned long long cost;
	int tmp;
	int	*list;
	int	j;

	cin >> n;
	cin >> b; cin >> c;
	list = new int[n];
	for (int i=0; i<n; i++)
		cin >> list[i];
	j = 0;
	cost = 0;
	while (j < n) {
		while (list[j] > 0) {
			// cout << "cost : " << cost << " + ";
			if (j < n - 2 && list[j] <= list[j+ 1] && list[j + 1] <= list[j + 2] && \
				b + 2*c <= 3 * b) {
				tmp = list[j];
				list[j] -= tmp;
				list[j + 1] -= tmp;
				list[j + 2] -= tmp;
				cost += (b + 2 * c) *tmp;
				// cout << (b + 2 * c) * tmp << " (3)" << endl;
			}
			else if (j < n - 1 && list[j] <= list[j + 1] && b + c <= 2 * b) {
				if (j < n - 2 && list[j] > list[j + 1] - list[j + 2])
					tmp = list[j + 1] - list[j + 2];
				else
					tmp = list[j];
				list[j] -= tmp;
				list[j + 1] -= tmp;
				cost += (b + c) * tmp;
				// cout << (b + c) * tmp << " (2)" << endl;
			}
			else {
				if (j < n - 1 && list[j] > list[j + 1])
					tmp = list[j] - list[j + 1];
				else
					tmp = list[j];
				list[j] -= tmp;
				cost += b * tmp;
				// cout << b * tmp << " (1)" << endl;
			}
			// for (int i=0; i<n; i++) {
			// 	cout << list[i] << " ";
			// }
		}
			j++;
	}
	// cout << endl;
	cout << cost << endl;
}