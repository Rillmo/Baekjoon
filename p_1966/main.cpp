#include <iostream>
#include <queue>
using namespace std;

int t, n, m;
queue<Data> q;
Data input;

class Data {
	public:
		int idx;
		int priority;
};

void	simulate() {
	
}

int main() {
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		cin >> m;
		for (int j=0; j<n; j++) {
			input = new Data();
			cin >> input.priority;
			input.idx = j;
			q.push(input);
		}
		
	}
}