#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
        freopen("count.in","r",stdin);
        freopen("count.out","w",stdout);
        //freopen("E:\\sourse code\\测试数据\\testin12.txt","r",stdin);
        int l[50000];
        int count=0;
        int i=0,n=0;
        memset(l,-1,sizeof(l));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                scanf("%d",&l[i]);
        }
        sort(l,l+n);
        for(i=0;i<n;i++)
        {
                count=1;
                while(l[i]==l[i+1])
                {
                        count++;
                        i++;
                }

                printf("%d %d\n",l[i],count);
        }
}
