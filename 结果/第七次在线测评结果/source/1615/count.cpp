#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=(1<<31)-1;
const int nmax=50010;
int a[nmax];
void swap(int &a,int &b)
{
	int t=a;
	a=b; b=t;
}
void quicksort(int a[],int l, int r)
{
	if(r-l<2) return;
	int i=l,j=r, m=l;
	while(i<j)
	{
		i++; while(a[i]<a[l]) i++;
		j--; while(a[j]>a[l]) j--;
		if(i<j) swap(a[i],a[j]);
		else    swap(a[j],a[l]);
	}
    quicksort(a,l,j);
    quicksort(a,j+1,r);
}

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n;
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof a);
		for(int i=1;i<=n; i++)
		{
		   scanf("%d",&a[i]);
		}
        a[n+1]=inf;
        quicksort(a, 1, n+1);
	    int cur=a[1],cnt=0,i=1;
	    while(1)
	    {
	    	if(a[i]==cur&&i<=n)  { cnt++; i++; continue; }
	    	if(a[i]!=cur&&i<=n)  { printf("%d %d\n",cur,cnt); cur=a[i]; cnt=0; continue; }
	    	if(i>n) { printf("%d %d\n",cur,cnt); break; }
	    }
	}
	return 0;
}
