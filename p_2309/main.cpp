#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tmp;
	int list[9];
	int res1, res2;
	int	sum = 0;

	for (int i=0; i<9; i++) {
		cin >> list[i];
		sum += list[i];
	}
	tmp = sum - 100;

	for (int i=0; i<8; i++) {
		for (int j=i + 1; j<9; j++) {
			if (list[i] + list[j] == tmp) {
				res1 = list[i];
				res2 = list[j];
				break;
			}
		}
	}

	sort(list, list + 9);
 
	for (int i=0; i<9; i++) {
		if (list[i] != res1 && list[i] != res2)
			cout << list[i] << endl;
	}
}