#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s[3];
	int third;
	for (int i=1; i<=3; i++) {
		cin >> s[i-1];
		int num = atoi(s[i-1].c_str());
		if (num != 0)
			third = num + 3 - i + 1;
	}
	// cout << third << endl;
	if (third % 3 == 0 && third % 5 == 0)
		cout << "FizzBuzz";
	else if (third % 3 == 0)
		cout << "Fizz";
	else if (third % 5 == 0)
		cout << "Buzz";
	else
		cout << third;
}