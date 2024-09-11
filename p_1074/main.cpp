#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	int x;
	int y;
};

int n, r, c;
int dq_count = 0;

void div_conq(Point start, int n) {
	// cout << n << " (" << start.x << ',' << start.y << ") " << dq_count<< endl;
	if (n == 0 || (start.x == c && start.y == r)) {
		return ;
	}
	int half = (int)pow(2, n-1);
	int end = (int)pow(2, n);
	if (start.x <= c && c < start.x+half && start.y <= r && r < start.y+half) {
		div_conq(start, n-1);
	} else if (start.x+half <= c && c < start.x+end && start.y <= r && r < start.y+half) {
		dq_count += (int)pow(4, n-1);
		div_conq({start.x+half, start.y}, n-1);
	} else if (start.x <= c && c < start.x+half && start.y+half <= r && r < start.y+end) {
		dq_count += 2 * (int)pow(4, n-1);
		div_conq({start.x, start.y+half}, n-1);
	} else {
		dq_count += 3 * (int)pow(4, n-1);
		div_conq({start.x+half, start.y+half}, n-1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> r >> c;
	div_conq({0,0}, n);
	cout << dq_count;
}