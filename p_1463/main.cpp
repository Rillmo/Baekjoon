#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int	n;
	int	i;
	int count;

	cin >> n;
	count = 0;
	i = 666;
	while (1) {
		if (to_string(i).find("666") != string::npos) {
			count++;
			if (count == n) {
				cout << i << endl;
				break;
			}
		}
		i++;
	}
}