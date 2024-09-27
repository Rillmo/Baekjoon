#include <iostream>
using namespace std;

int n;
int graph[16];
int counter = 0;

bool check(int lev) {
	for (int i=0; i<lev; i++) {
		if (graph[i] == graph[lev] || lev - i == abs(graph[lev] - graph[i]))
			return false;
	}
	return true;
}

void back_tracking(int lev) {
	if (lev == n)
		counter++;
	for (int i=0; i<n; i++) {
		graph[lev] = i;
		if (check(lev))
			back_tracking(lev+1);
	}
}

int main() {
	cin >> n;
	back_tracking(0);
	cout << counter;
}