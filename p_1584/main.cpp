#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef struct _node {
	int x;
	int y;
	int cost;
}	node;

int n, m;
int graph[501][501] = { 0 };
bool visited[501][501] = {false};
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs() {
	deque<node> deq;
	deq.push_back({ 0,0,0 });
	visited[0][0] = true;
	while (!deq.empty()) {
		int x = deq.front().x;
		int y = deq.front().y;
		int cost = deq.front().cost;
		deq.pop_front();
		if (x == 500 && y == 500)
			return cost;
		for (int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncost = cost;
			if (nx < 0 || ny < 0 || nx > 500 || ny > 500)
				continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				if (graph[nx][ny] == 1)
					deq.push_back({nx, ny, ++ncost});
				else
					deq.push_front({nx, ny, ncost});
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int x[2], y[2];
	for (int i=0; i<n; i++) {
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		if (x[0] > x[1])	swap(x[0], x[1]);
		if (y[0] > y[1])	swap(y[0], y[1]);
		for (int j=x[0]; j<=x[1]; j++) {
			for (int k=y[0]; k<=y[1]; k++) {
				graph[j][k] = 1;	// 위험구역은 1로 초기화
			}
		}
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		if (x[0] > x[1])	swap(x[0], x[1]);
		if (y[0] > y[1])	swap(y[0], y[1]);
		for (int j=x[0]; j<=x[1]; j++) {
			for (int k=y[0]; k<=y[1]; k++) {
				visited[j][k] = true;
			}
		}
	}
	cout << bfs();
}