#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 50000+5;

long long a[maxn];

int main()
{
	freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    long long  temp = 0;
    int cnt = 0;
    //for(int i = 0 ; i < n ; i++)
    //	printf("%lld ",a[i]);
    for(int i = 0 ; i < n ;)
    {
        if(temp != a[i])
        {
        	cnt = 0;
        	temp = a[i];
        	printf("%lld ",temp);
        	while(temp == a[i])
        	{
        		cnt++;
        		i++;
        	}
        	printf("%d\n",cnt);
        }
    }
    return 0;
}
