#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
#define MOD 10000

int a, b;
int visited[10000];

void dfs() {
	queue<pair<int, string> > que;
	que.push({a, ""});
	visited[a] = 1;
	while (!que.empty()) {
		int now_val = que.front().first;
		string now_op = que.front().second;
		if (now_val == b) {
			cout << now_op << '\n';
			return ;
		}
		que.pop();
		int next;
		next = now_val * 2 % MOD;
		if (!visited[next]) {
			que.push({next, now_op+"D"});
			visited[next] = 1;
		}
		next = now_val == 0 ? 9999 : now_val-1;
		if (!visited[next]) {
			que.push({next, now_op+"S"});
			visited[next] = 1;
		}
		next = (now_val%1000)*10 + now_val/1000;
		if (!visited[next]) {
			que.push({next, now_op+"L"});
			visited[next] = 1;
		}
		next = now_val/10 + (now_val%10)*1000;
		if (!visited[next]) {
			que.push({next, now_op+"R"});
			visited[next] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int test;
	cin >> test;
	for (int t=0; t<test; t++) {
		cin >> a >> b;
		dfs();
		memset(visited, 0, sizeof(visited));
	}
}