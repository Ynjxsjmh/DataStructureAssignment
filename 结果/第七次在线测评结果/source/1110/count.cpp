#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
long long int c[50005];
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int n,i,t;
    long long int q;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%lld",&c[i]);
    sort(c,c+n);
    q=c[0];
    t=1;
    for(i=1; i<n; i++)
    {
        if(c[i]==q)
        {
            t++;
            if(i==n-1)
                printf("%lld %d\n",c[i-1],t);
        }
        else
        {
            printf("%lld %d\n",c[i-1],t);
            t=1;
            q=c[i];
            if(i==n-1)
            printf("%lld %d\n",c[i],t);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
