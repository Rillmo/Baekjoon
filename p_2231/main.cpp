#include <iostream>
using namespace std;

int	get_disassemble(int target) {
	int result = 0;

	result += target;
	while (target != 0) {
		result += target % 10;
		target /= 10;
	}
	return result;
}

int main() {
	int input;

	cin >> input;
	for (int i=1; i<input; i++) {
		if (get_disassemble(i) == input) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}