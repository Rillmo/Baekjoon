#include <iostream>
#include <limits.h>
using namespace std;

/*
	1. 막대기 던지기 처리 : 특정 위치의 x 삭제 O(1)
	2. DFS로 전체 맵 순회하며 클러스터 기록 O(n)
		-> 클러스터의 가장 아래 행을 맵에 기록(클러스터 번호 : 최하단 행 y좌표)
		-> 만약 클러스터의 가장 아래 행이 r-1이 아닌 경우 낙하 처리 필요
	3. 낙하 처리
		-> 해당 행의 열을 모두 순회하며 동일한 열의 가장 위쪽에서 만나는 x 또는 .을 찾고, y 거리를 계산 O(n)
		-> 해당 클러스터의 모든 x를 y거리만큼 아래로 이동
*/

typedef struct _node {
	char val;
	int cluster;
	bool visited;
}	node;

int r, c, n;
node cave[101][101];
int cmd[101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


void printer(int type) {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (type == 1) cout << cave[i][j].val;
			else if (type == 2)	cout << cave[i][j].cluster;
		}
		cout << '\n';
	}
}

void throwStick(int dir) {	// O(c) = max 100
	if (dir % 2 == 0) {
		for (int i=0; i<c; i++) {
			if (cave[r-cmd[dir]-1][i].val == 'x') {
				cave[r-cmd[dir]-1][i].val = '.';
				break;
			}
		}
	} else {
		for (int i=c-1; i>=0; i--) {
			if (cave[r-cmd[dir]-1][i].val == 'x') {
				cave[r-cmd[dir]-1][i].val = '.';
				break;
			}
		}
	}
}

void dfs(int x, int y, int cluster) {
	if (x < 0 || x >= c || y < 0 || y >= r)
		return ;
	if (cave[y][x].visited || cave[y][x].val != 'x')
		return ;
	cave[y][x].visited = true;
	cave[y][x].cluster = cluster;
	maxY = max(maxY, y);
	for (int i=0; i<4; i++)
		dfs(x+dx[i], y+dy[i], cluster);
}

void drop(int cluster) {
	int minY = INT_MAX;
	for (int i=0; i<c; i++) {
		if (cave[y][i].val == 'x' && cave[y][i].cluster == cluster) {
			for (int j=y+1; j<=r; j++) {
				if (cave[j][i].val == 'x' || j == r) {
					minY = min(minY, j-y-1);
					break;
				}
			}
		}
	}
	for (int i=r-1; i>=0; i--) {
		for (int j=c-1; j>=0; j--) {
			if (cave[i][j].cluster == cluster) {
				cave[i+minY][j].val = cave[i][j].val;
				cave[i][j].val = '.';
				cave[i][j].cluster = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	// input
	cin >> r >> c;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> cave[i][j].val;
			cave[i][j].cluster = 0;
			cave[i][j].visited = false;
		}
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> cmd[i];
		cmd[i]--;
	}

	// 막대기 던지기 처리`
	for (int i=0; i<n; i++) {	// O(n) = max 100
		for (int j=0; j<r; j++) {
			for (int k=0; k<c; k++) {
				cave[j][k].cluster = 0;
				cave[j][k].visited = false;
			}
		}
		throwStick(i);
		int cluster = 1;
		for (int j=0; j<r; j++) {
			for (int k=0; k<c; k++) {	// O(rc) = max 10000
				if (cave[j][k].val == 'x' && cave[j][k].cluster == 0) {
					dfs(k, j, cluster);
					cluster++;
				}
			}
		}
		for (int j=1; j<=cluster; j++)
				drop(j);
		}
	}
	printer(1);
}