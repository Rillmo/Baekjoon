#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;
using node = tuple<int, int, int>;

int n;
node spos;
int ssize = 2, scount = 0;
int graph[21][21];
int visited[21][21];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs() {
	memset(visited, 0, sizeof(visited));
	queue<node> que;
	que.push(spos);
	visited[get<0>(spos)][get<1>(spos)] = 1;
	vector<node> list; 
	while (!que.empty()) {
		int y = get<0>(que.front());
		int x = get<1>(que.front());
		int time = get<2>(que.front());
		que.pop();
		if (graph[y][x] != 0 && graph[y][x] < ssize)
			list.push_back({y, x, time});
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;
			if (visited[ny][nx] || ssize < graph[ny][nx]) continue;
			visited[ny][nx] = 1;
			que.push({ny, nx, time+1});
		}
	}
	if (list.size() == 0)
		return 0;
	else {
		// 시간->y->x 순 정렬
		sort(list.begin(), list.end(), [](node n1, node n2) {
			if (get<2>(n1) != get<2>(n2))
				return get<2>(n1) < get<2>(n2);
			else if (get<0>(n1) != get<0>(n2))
				return get<0>(n1) < get<0>(n2);
			else
				return get<1>(n1) < get<1>(n2);
		});
		// 생선 먹기 처리
		scount++;
		if (scount == ssize) {
			ssize++;
			scount = 0;
		}
		node res = list[0];
		// for (int i=0; i<list.size(); i++) {
		// 	cout << '(' << get<0>(list[i]) << ',' << get<1>(list[i]) << ") ";
		// }
		// cout << "\nres: (" << get<0>(res) << ',' << get<1>(res) << ")\n";
		spos = {get<0>(res), get<1>(res), get<2>(res)};
		graph[get<0>(res)][get<1>(res)] = 0;
		return get<2>(res);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				spos = {i, j, 0};
				graph[i][j] = 0;
			}
		}
	}
	int now = 1, res;
	while (now) {
		now = bfs();
		if (now == 0)
			cout << res;
		res = now;
		// for (int i=0; i<n; i++) {
		// 	for (int j=0; j<n; j++)
		// 		cout << graph[i][j] << ' ';
		// 	cout << endl;
		// }
		// cout << "____________________" << endl;
		// cout << res << endl;
	}
}