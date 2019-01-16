#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 110;
int n, depth[maxn], cnt[maxn], dist[maxn];
bool G[maxn][maxn], vis[maxn];
queue<int> Q;
inline void get_depth() {
    memset(vis, false, sizeof(vis));
    while (!Q.empty()) Q.pop();
    depth[1] = 1;
    Q.push(1);
    vis[1] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; v++)
            if (G[u][v] && !vis[v]) {
                vis[v] = true;
                depth[v] = depth[u] + 1;
                Q.push(v);
            }
    }
}
int bfs(int s, int t) {
    while (!Q.empty()) Q.pop();
    memset(vis, false, sizeof(vis));
    Q.push(s);
    vis[s] = true;
    dist[s] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; v++)
            if (G[u][v] && !vis[v]) {
                vis[v] = true;
                if (depth[v] > depth[u])
                    dist[v] = dist[u] + 1;
                else
                    dist[v] = dist[u] + 2;
                Q.push(v);
            }
    }
    return dist[t];
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = true;
    }
    scanf("%d%d", &u, &v);
    get_depth();
    int maxdepth = 0;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > maxdepth) maxdepth = depth[i];
        cnt[depth[i]]++;
    }
    int width = 1;
    for (int i = 1; i <= maxdepth; i++)
        if (cnt[i] > width) width = cnt[i];
    int ans = bfs(u, v);
    printf("%d\n%d\n%d\n", maxdepth, width, ans);
    return 0;
}