#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

const int maxn = 1e5+5;

int dp[maxn];

int vis[maxn];

queue<int> q;

int n,k;

int bfs()
{
    dp[n] = 0;
    vis[n] = 1;
    q.push(n);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        int count = 3;
        int t;
        while(count--)
        {
            //cout<<count<<endl;
            if(count == 2)
            {
                t = temp - 1;
            }
            else if(count == 1)
            {
                t = temp + 1;
            }
            else if(count == 0)
            {
                t = temp * 2;
            }
            if(t < 0 || t > 100000 || vis[t])
                continue;
            else
            {
                dp[t] = dp[temp] + 1;
                if(t == k)
                {
                    return dp[t];
                }
                vis[t] = 1;
                q.push(t);
            }
        }
    }
}

int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        if(n >= k)
            printf("%d\n",n - k);
        else
        {
            memset(dp,0,sizeof(dp));
            memset(vis,0,sizeof(vis));
            printf("%d\n",bfs());
        }
    }
}
