#include <iostream>
using namespace std;

int main() {
	int l, p, v;
	int result = 0;
	int	i = 1;

	while (1) {
		cin >> l;
		cin >> p;
		cin >> v;
		result = 0;
		if ((l == 0 && p == 0 && v == 0))
			return 0;

		while (v > p) {
			v -= p;
			result += l;
		}
		if (v >= l)
			result += l;
		else
			result += v;
		cout << "Case " << i++ << ": "<< result << endl;
	}
}