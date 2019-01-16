#include <cstdio>
#include <algorithm>
#define MAXN 500002
using namespace std;
int n,a[MAXN];

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int i,t,num;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+1+n);
	a[n+1]=-1;num=1;
	for(i=1;i<=n;i++)
	  	if(a[i]==a[i+1]) num++;
	  	else{
	 		printf("%d %d\n",a[i],num);
	  	 	num=1;
	  	}
	
    return 0;
}
