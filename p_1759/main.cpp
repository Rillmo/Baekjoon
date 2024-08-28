#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char tmp;
vector<char> arr;
char res[16];

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || \
		c == 'o' || c == 'u')
		return true;
	return false;
}

void brute(int idx, int count, int vowel, int conso) {
	// cout << "now: " << arr[idx] << endl;
	if (count == l) {
		if (vowel < 1 || conso < 2)
			return ;
		// cout << l << "번째 도달 : " << endl;
		// cout << "res: ";
		for (int i=0; i<l; i++)
			cout << res[i];
		cout << '\n';
	} else {
		for (int i=idx+1; i<c; i++) {
			res[count] = arr[i];
			if (isVowel(arr[i]))	brute(i, count+1, vowel+1, conso);
			else	brute(i, count+1, vowel, conso+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> l >> c;
	for (int i=0; i<c; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());
	// for (int i=0; i<c; i++)
	// 	cout << arr[i] << ' ';
	// cout << endl;
	for (int i=0; i<=c-l; i++) {
		// cout << "_____start: " << arr[i] << endl;
		res[0] = arr[i];
		if (isVowel(arr[i]))	brute(i, 1, 1, 0);
		else	brute(i, 1, 0, 1);
	}
}