#include"stdio.h"
#include<algorithm>
using namespace std;
int a[100000];
main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int i,n;
    int k=1,m=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    	scanf("%d",&(a[i]));
    sort(1+a,1+a+n);
    while(k<=n)
    {
        printf("%d ",a[k]);
        for(i=k;i<n;i++)
        {
            if(a[k]==a[k+1])
            {
               m++;
               k++;
            }
        }
        printf("%d\n",m);
        m=1;
        k++;
    }
}

