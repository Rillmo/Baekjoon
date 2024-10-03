#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using ii = pair<int,int>;

int n;
char graph1[101][101];
char graph2[101][101];
int visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void printer(int toprint[101][101]) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout << toprint[i][j] << ' ';
		cout << endl;
	}
}

int bfs(char graph[101][101], ii start) {
	int count = 0;
	queue<ii> que;
	que.push({start.first,start.second});
	visited[start.first][start.second] = 1;
	while (!que.empty()) {
		int x = que.front().second;
		int y = que.front().first;
		que.pop();
		count++;
		for (int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) continue;
			if (graph[ny][nx] != graph[y][x]) continue;
			visited[ny][nx] = 1;
			que.push({ny,nx});
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> graph1[i][j];
			if (graph1[i][j] == 'R') graph2[i][j] = 'G';
			else graph2[i][j] = graph1[i][j];
		}
	}

	// printer(graph1);
	// printer(graph2);

	memset(visited, 0, sizeof(visited));
	int count1 = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (visited[i][j]) continue;
			// cout << "(" << i << "," << j << ")\n";
			bfs(graph1, {i,j});
			count1++;
		}
	}
	cout << count1 << ' ';
	memset(visited, 0, sizeof(visited));
	int count2 = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (visited[i][j]) continue;
			// cout << "(" << i << "," << j << ")\n";
			bfs(graph2, {i,j});
			count2++;
		}
	}
	cout << count2;
}