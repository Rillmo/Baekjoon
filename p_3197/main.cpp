#include <iostream>
#include <utility>
#include <queue>
using namespace std;

/*
	1. bfs로 백조 이동 테스트
		now큐에서 값을 뺀다.
		뺀 값의 상하좌우 노드를 next큐에 넣는다.
		now큐가 비면 next=now 후 빙하를 녹인다.
	2. bfs로 빙하 녹이기
		방문한 노드가 물과 인접한 경우 큐에 해당 노드의 좌표 삽입
		모든 노드를 방문한 후, 큐에 있는 모든 노드를 '.'으로 변경 -> 비효율
		2-1. 미리 모든 물좌표를 기억해 큐에 넣는다.
		2-2. 물큐에서 dfs를 수행해 물과 인접한 얼음을 녹이고, 녹인 좌표를 큐에 다시 넣는다.
		=> 이렇게 하면 얼음과 인접한, 즉 가장자리쪽 물에 대해서만 반복을 수행할 수 있음.
	3. day++
*/

typedef struct _node {
	int x;
	int y;
	bool visited = false;
	char val;
	bool inque = false;
}	node;
int r, c;
node graph[1501][1501];
node start;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<node> nowq;
queue<node> nextq;
queue<node> waterq;
int day;

void printer(int type, string msg) {
	cout << "<" << msg << ">" << endl;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (type == 1)
				cout << graph[i][j].val << " ";
			else if (type == 2)
				cout << graph[i][j].visited << " ";
		}
		cout << "\n";
	}
}

bool checkAdjacent(int i, int j) {
	if (graph[i][j].val != 'X')	return false;
	int nexti, nextj;
	for (int k=0; k<4; k++) {
		nexti = i + dy[k];
		nextj = j + dx[k];
		if (nexti >= 0 && nexti < r && nextj >= 0 && nextj < c \
			&& graph[nexti][nextj].val != 'X')
			return true;
	}
	return false;
}

void meltIce() {
	int wsize = waterq.size();
	while (wsize--) {
		node now = waterq.front();
		waterq.pop();
		for (int i=0; i<4; i++) {
			node next;
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (next.x >= 0 && next.x < c && next.y >= 0 && next.y < r \
				&& graph[next.y][next.x].val == 'X') {
				waterq.push(next);
				graph[next.y][next.x].val = '.';
			}
		}
	}
	day++;
}

void moveSwan(node cur) {
	nowq.push(cur);
	node now;
	while (!nowq.empty()) {
		now = nowq.front();
		nowq.pop();
		if ((now.x != start.x || now.y != start.y) && graph[now.y][now.x].val == 'L') return ;
		if (graph[now.y][now.x].visited) {
			goto here;
		}
		graph[now.y][now.x].visited = true;
		for (int i=0; i<4; i++) {
			node next;
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (next.x >= 0 && next.x < c && next.y >= 0 && next.y < r \
				&& !graph[next.y][next.x].visited && !next.inque) {
				if (graph[next.y][next.x].val == 'X') {
					next.inque = true;
					nextq.push(next);
				}
				else
					nowq.push(next);
			}
		}
		here:
		if (nowq.empty()) {
			// 여기서 빙하를 녹이면 됨
			meltIce();
			while (!nextq.empty()) {
				nowq.push(nextq.front());
				nextq.pop();
			}
		}
	}
}

int main() {
	// input
	cin >> r >> c;
	bool found = false;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> graph[i][j].val;
			if (graph[i][j].val != 'X') {
				node water;
				water.x = j;
				water.y = i;
				waterq.push(water);
			}
			if (!found && graph[i][j].val == 'L') {
				start.x = j;
				start.y = i;
				found = true;
			}
		}
	}

	// 백조 이동
	day = 0;
	moveSwan(start);
	cout << day << '\n';
}