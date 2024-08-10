#include <iostream>
#include <cmath>
using namespace std;

int getGCD(int a, int b) {
	if (b == 0)	return a;
	return getGCD(b, a % b);
}

int main() {
	long long int lcm, gcd;
	long long int div, a, b, A, B;

	cin >> gcd;
	cin >> lcm;

	div = lcm / gcd;
	for (int i=1; i<=sqrt(div); i++) {
		if (div % i == 0) {
			a = i;
			b = div / i;

			if (getGCD(a, b) == 1) {
				A = a * gcd;
				B = b * gcd;
			}
		}
	}

	cout << A << " " << B << endl;
	
}