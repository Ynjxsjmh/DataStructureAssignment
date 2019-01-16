#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 100005;
int n,k;
bool visit[MAX];
int step[MAX];
int mov[] = {1, -1};

int bfs(int x)
{
	if (n >= k) {
		return n - k;
	}
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	while (!q.empty()) {
		x = q.front(); q.pop();
		for (int i = 0; i < 2; i ++) {
			int xx = x + mov[i];
			if (xx == k) {
				return step[x] + 1;
			}
			if (xx >= 0 && xx <= 100000 && !visit[xx]) {
				q.push(xx);
				visit[xx] = 1;
				step[xx] = step[x] + 1;
			}
		}
		int xx = x * 2;
		if (xx == k) {
			return step[x] + 1;
		}
		if (xx <= 100000 && !visit[xx]) {
			q.push(xx);
			visit[xx] = 1;
			step[xx] = step[x] + 1;
		}
	}
}

int main()
{
//	freopen("catchcow.in","r",stdin);
//	freopen("catchcow.out","w",stdout);
	while (~scanf("%d%d",&n,&k)) {
		memset(visit,0,sizeof(visit));
		memset(step,0,sizeof(step));
		printf("%d\n",bfs(n));
	}
//	fclose(stdin);
//	fclose(stdout);
}
