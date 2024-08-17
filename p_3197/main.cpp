#include <iostream>
#include <utility>
#include <queue>
using namespace std;

typedef struct _node {
	int x;
	int y;
	bool visited;
	char val;
}	node;
int r, c;
node graph[1501][1501];
node l1, l2, tmp;
queue<node> que;

void bfs(int x, int y) {
	graph[x][y].visited = true;
	que.push(graph[x][y]);
	while (!que.empty()) {
		tmp = que.front();
		que.pop();
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if ()
			}
		}
	}
}

void printer() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	// input
	l1.x = 0;
	l1.y = 0;
	cin >> r >> c;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> graph[i][j].val;
			if (graph[i][j].val == 'L' && l1.x == 0) {
				l1.x = i;
				l2.y = j;
			}
			else {
				l2.x = i;
				l2.y = j;
			}
		}
	}
	
	// 백조 이동
	
}