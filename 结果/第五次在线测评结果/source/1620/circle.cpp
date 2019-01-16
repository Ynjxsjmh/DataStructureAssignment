#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define maxn 7010

int n;
int x[maxn], y[maxn], r[maxn], vis[maxn], w[maxn][maxn];

double dist(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

void dfs(int u) {
    vis[u] = true;
    for(int i = 1; i <= n; i++)
        if(w[u][i] && !vis[i]) dfs(i);
}

int main() {
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(dist(i, j) <= 1.0 * (r[i]+r[j])) w[i][j] = w[j][i] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) {
            ans++; dfs(i);
        }
    printf("%d\n", ans);
}
