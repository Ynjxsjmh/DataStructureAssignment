#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 110

int n, cnt1, cnt2;
int deep[maxn], num[maxn], w[maxn][maxn], fa[maxn], fa1[maxn], fa2[maxn], vis[maxn];

void dfs(int u) {
    for(int i = 1; i <= n; i++)
        if(w[u][i] && !deep[i]){
            fa[i] = u, deep[i] = deep[u] + 1;
            dfs(i);
        }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        w[u][v] = w[v][u] = 1;
    }
    deep[1] = 1; dfs(1);
    int depth = 0, width = 0;
    for(int i = 1; i <= n; i++) {
        if(depth < deep[i]) depth = deep[i];
        if(width < ++num[deep[i]]) width = num[deep[i]];
    }
    printf("%d\n%d\n", depth, width);
    int u, v;
    scanf("%d%d", &u, &v);
    while(u != 0) {
        vis[u] = 1; fa1[++cnt1] = u;
        u = fa[u];
    }
    while(v != 0) {
        if(vis[v]) break;
        cnt2++, v = fa[v];
    }
    int ans = cnt2;
    for(int i = 1; i <= cnt1; i++) {
        if(fa1[i] == v) break;
        ans += 2;
    }
    printf("%d\n", ans);
}
