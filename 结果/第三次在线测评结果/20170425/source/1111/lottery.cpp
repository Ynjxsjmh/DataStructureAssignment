#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<map>
using namespace std;

map<int ,int> mp;

int count[7];

int main()
{
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        memset(count,0,sizeof(count));
        for(int i = 0; i < 7; i++)
        {
            scanf("%d",&t);
            mp[t] = 1;
        }
        while(n--)
        {
            int sum = 0;
            for(int i = 0; i < 7; i++)
            {
                scanf("%d",&t);
                if(mp[t])
                    sum++;
            }
            if(sum >= 1)
                count[7-sum]++;
                //cout<<sum<<endl;
        }
        for(int i = 0; i < 6; i++)
            printf("%d ",count[i]);
        printf("%d\n",count[6]);
    }
}
