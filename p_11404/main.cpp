#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ii = pair<int,int>;
#define INF 9999999

int N, M;
vector<vector<int>> dist;

void floyd_warshall() {
	for (int i=1; i<=N; i++)
		dist[i][i] = 0;
	for (int k=1; k<=N; k++) {
		for (int a=1; a<=N; a++) {
			for (int b=1; b<=N; b++)
				dist[a][b] = min(dist[a][b], dist[a][k]+dist[k][b]);
		}
	}
}

int main() {
	cin >> N >> M;
	int from, to, cost;
	dist.assign(N+1, vector<int>(N+1,INF));
	for (int i=0; i<M; i++) {
		cin >> from >> to >> cost;
		dist[from][to] = dist[from][to] > cost ? cost : dist[from][to];
	}

	floyd_warshall();

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
		}
		cout << '\n';
	}
}