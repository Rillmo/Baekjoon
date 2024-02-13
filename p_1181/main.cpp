#include <iostream>
#include <algorithm>
using namespace std;

int	n;
string *list;

bool compare(string s1, string s2) {
	if (s1.length() > s2.length())
		return false;
	else if (s1.length() < s2.length())
		return true;
	else {
		if (s1.compare(s2) >= 0)
			return false;
		else
			return true;
	}
}

int main() {
	int n;

	cin >> n;
	list = new string[n];
	for (int i=0; i<n; i++)
		cin >> list[i];
	sort(list, list + n, compare);
	cout << list[0] << endl;
	for (int i=1; i<n; i++) {
		if (list[i].compare(list[i - 1])) {
			cout << list[i] << endl;
		}
	}
}