#include <cstdio>
#include <cstring>
using namespace std;
bool vis[35];
int cnt[10],tcnt;
int main() {
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int n,t;
    scanf("%d",&n);
    memset(vis,false,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for (int i=0; i<7; i++) {
        scanf("%d",&t);
        vis[t]=true;
    }
    for (int i=0; i<n; i++) {
        tcnt=0;
        for (int j=0; j<7; j++) {
            scanf("%d",&t);
            if (vis[t]) tcnt++;
        }
        cnt[tcnt]++;
    }
    for (int i=7; i>1; i--)
        printf("%d ",cnt[i]);
    printf("%d\n",cnt[1]);
    return 0;
}