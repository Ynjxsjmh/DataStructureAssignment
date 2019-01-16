#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 210000
int a[maxn][10];
int n,ans[10];
int main()
{
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        for(int j=1;j<=7;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        int same=0;
        for(int j=1;j<=7;j++)
        {
            for(int k=1;k<=7;k++)
            {
                if(a[i][j]==a[0][k])
                {
                    same++;
                }
            }
        }
        ans[7-same]++;
    }
    printf("%d",ans[0]);
    for(int i=1;i<=6;i++) printf(" %d",ans[i]);
    return 0;
}
/*
2
23 1 11 14 19 17 18
12 8 9 23 1 16 7
11 7 10 21 2 9 31
*/
