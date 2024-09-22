#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int m, n, k;
int graph[51][51], visited[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(ii start) {
	// cout << "(" << start.first << "," << start.second << ")\n_________\n";
	queue<ii> que;
	que.push({start.first, start.second});
	visited[start.first][start.second] = 1;
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		// cout << "(" << y << "," << x << ") ";
		que.pop();
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || nx<0 || ny>=n || nx>=m || visited[ny][nx] == 1 || graph[ny][nx] == 0)
				continue;
			visited[ny][nx] = 1;
			que.push({ny, nx});
		}
	}
	// cout << "\n";
}

void printer() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cout << graph[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> m >> n >> k;
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		for (int j=0; j<k; j++) {
			int x, y;
			cin >> x >> y;
			graph[y][x] = 1;
		}
		int count{};
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++) {
				if (graph[y][x] == 1 && !visited[y][x]) {
					bfs({y, x});
					count++;
					// printer();
				}
			}
		}
		cout << count << '\n';
	}
}