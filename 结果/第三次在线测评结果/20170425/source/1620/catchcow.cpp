#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define maxn 100000

int dis[maxn+10], vis[maxn+10];

int spfa(int s, int t) {
    memset(dis, 0x3f, sizeof(dis)); memset(vis, false, sizeof(vis));
    queue<int>q; q.push(s); dis[s] = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        if(x + 1 <= maxn && dis[x+1] > dis[x] + 1) {
            dis[x+1] = dis[x] + 1;
            if(!vis[x+1]) {
                vis[x+1] = true; q.push(x+1);
            }
        }
        if(x - 1 >= 0 && dis[x-1] > dis[x] + 1) {
            dis[x-1] = dis[x] + 1;
            if(!vis[x-1]) {
                vis[x-1] = true; q.push(x-1);
            }
        }
        if(2 * x <= maxn && dis[x*2] > dis[x] + 1) {
            dis[2*x] = dis[x] + 1;
            if(!vis[2*x]) {
                vis[2*x] = true; q.push(2*x);
            }
        }
    }
    return dis[t];
}

int main() {
    freopen("catchcow.in", "r", stdin);
    freopen("catchcow.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", spfa(n, k));
}
