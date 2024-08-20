#include <iostream>
using namespace std;

int main() {
	int n, m, t, k, basket[101], tmp;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		basket[i] = i;
	}

	for (int i=0; i<m; i++) {
		cin >> t >> k;
		tmp = basket[t];
		basket[t] = basket[k];
		basket[k] = tmp;
	}
	for (int i=1; i<=n; i++)
		cout << basket[i] << " ";
}