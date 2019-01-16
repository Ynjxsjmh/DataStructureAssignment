#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int maxn=200010;
int n,k;
bool vis[maxn];
queue<PII> Q;
inline int bfs() {
    Q.push(make_pair(n,0)); vis[n]=true;
    PII p,x;
    while (!Q.empty()) {
        p=Q.front(); Q.pop();
        x.second=p.second+1;
        x.first=p.first+1;
        if (x.first>=0 && x.first<=maxn && !vis[x.first]) {
            if (x.first==k) return x.second;
            vis[x.first]=true;
            Q.push(x);
        }
        x.first=p.first-1;
        if (x.first>=0 && x.first<=maxn && !vis[x.first]) {
            if (x.first==k) return x.second;
            vis[x.first]=true;
            Q.push(x);
        }
        x.first=p.first*2;
        if (x.first>=0 && x.first<=maxn && !vis[x.first]) {
            if (x.first==k) return x.second;
            vis[x.first]=true;
            Q.push(x);
        }
    }
}
int main() {
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    scanf("%d%d",&n,&k);
    printf("%d\n",bfs());
    return 0;
}