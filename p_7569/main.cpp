#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int x; 
	int y;
	int z;
};

int n, m, h;
int graph[101][101][101];
int visited[101][101][101] = {0};
queue<Point> nowq;
queue<Point> nextq;
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

void tomato() {
	// cout << "___day0\n";
	for (int z=0; z<h; z++) {
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++) {
				for (int t=0; t<6; t++) {
					int nx = x+dx[t];
					int ny = y+dy[t];
					int nz = z+dz[t];
					if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h)
						continue;
					// cout << '(' << x << ',' << y << ',' << z << ")";
					if (!visited[z][y][x] && graph[z][y][x] == 0 && graph[nz][ny][nx] == 1) {
						visited[z][y][x] = 1;
						// cout << " push : ";
						// cout << '(' << x << ',' << y << ',' << z << ") 익음\n";
						graph[z][y][x] = 1;
						nowq.push({x, y, z});
					}
					// cout << '\n';
				}
			}
		}
	}
}

int bfs() {
	// cout << "___day1\n";
	int day = 0;
	while (!nowq.empty()) {
		Point now = nowq.front();
		int x = now.x;
		int y = now.y;
		int z = now.z;
		// cout << x << "," << y << ',' << z << '\n';
		// visited[z][y][x] = 1;
		nowq.pop();
		for (int i=0; i<6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h)
				continue;
			if (visited[nz][ny][nx] == 1 || graph[nz][ny][nx] != 0)
				continue;
			visited[nz][ny][nx] = 1;
			graph[nz][ny][nx] = 1;
			// cout << nx << "," << ny << ',' << nz << " 익음\n";
			nextq.push({nx, ny, nz});
		}
		if (nowq.empty()) {
			while(!nextq.empty()) {
				nowq.push(nextq.front());
				nextq.pop();
			}
			if (nowq.empty())	break;
			day++;
			// cout << "____day " << day << "\n";
		}
	}
	for (int z=0; z<h; z++) {
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++)
				if (graph[z][y][x] == 0)
					return -1;
		}
	}
	return day;
}

void printer(int target[][101][101]) {
	for (int z=0; z<h; z++) {
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++)
				cout << target[z][y][x] << " ";
			cout << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n >> h;

	int found0 = false;
	for (int z=0; z<h; z++) {
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++) {
				cin >> graph[z][y][x];
				if (graph[z][y][x] == 0)
					found0 = true;
				if (graph[z][y][x] == 1)
					nowq.push({x,y,z});
			}
		}
	}
	if (found0 == false) {
		cout << 0;
		return 0;
	}
	// tomato();
	// while(!nowq.empty()) {
	// 	Point cur = nowq.front();
	// 	cout << '(' << cur.x << ',' << cur.y << ',' << cur.z << ") ";
	// 	nowq.pop();
	// }
	// memset(visited, 0, sizeof(visited));
	// printer(visited);
	cout << bfs();
}