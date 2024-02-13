#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int	*result;

int main() {
	int n, k;
	int	cur;
	int count;
	int i;
	
	cin >> n;
	cin >> k;
	result = new int[n];
	for (int i=1; i<=n; i++)
		q.push(i);
	count = 1;
	i = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (count == k) {
			count = 0;
			result[i++] = cur;
		}
		else
			q.push(cur);
		count++;
	}
	cout << "<";
	int j;
	for (j=0; j<n -1; j++) {
		cout << result[j] << ", ";
	}
	cout << result[j] << ">";
}