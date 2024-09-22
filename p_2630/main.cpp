#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int,int>;

int n, white, black;
vector<vector<int>> graph;

int check_color(ii start, int size) {
	int y = start.first;
	int x = start.second;
	int flag = graph[y][x];
	for (int i=y; i<y+size; i++) {
		for (int j=x; j<x+size; j++) {
			if (graph[i][j] != flag) {
				return -1;
			}
		}
	}
	return flag;
}

void div_conq(ii now, int size) {
	int check = check_color(now, size);
	if (check == 1) {
		black++;
		return ;
	} else if (check == 0) {
		white++;
		return ;
	}
	int ny = now.first, nx = now.second;
	int nsize = size / 2;
	div_conq({ny, nx}, nsize);
	div_conq({ny, nx+nsize}, nsize);
	div_conq({ny+nsize, nx}, nsize);
	div_conq({ny+nsize, nx+nsize}, nsize);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	graph.assign(n, vector<int>(n,0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cin >> graph[i][j];
	}
	div_conq({0, 0}, n);
	cout << white << '\n' << black;
}