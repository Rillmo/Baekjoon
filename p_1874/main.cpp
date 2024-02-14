#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	stack<int> s;
	char *result;
	int	n;
	int j, k;
	int	*list;

	cin >> n;
	result = new char[2 * n ];
	memset(result, 0, 2 * n );
	list = new int[n];
	for (int i=0; i<n; i++)
		cin >> list[i];
	j = 0;
	k = 0;
	for (int i=1; i<=n; i++) {
		// cout << i << " pushed " << endl;
		s.push(i);
		result[k++] = '+';
		while (!s.empty() && list[j] == s.top()) {
			// cout << s.top() << " poped " << endl;
			s.pop();
			result[k++] = '-';
			j++;
		}
	}
	if (!s.empty())
		cout << "NO" << endl;
	else {
		for (int i=0; i < 2 *n; i++) {
			cout << result[i] << "\n";
		}
	}
}