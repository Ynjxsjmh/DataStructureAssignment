#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 100000
int n,a[maxn];
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    a[n+1]=a[n]+1;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt++;
        if(a[i]!=a[i+1])
        {
            printf("%d %d\n",a[i],cnt);
            cnt=0;
        }
    }
    return 0;
}
/*
12
8 2 8 2 2 11 1 1 8 1 13 13
*/
